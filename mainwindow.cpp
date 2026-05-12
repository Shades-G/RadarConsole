#include "mainwindow.h"
#include <cmath>
#include <QScreen>
#include <QGuiApplication>
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDir>
#include <QDebug>
#include <QPushButton>
#include "QtMath"
#include <utility>
#include "SimulatedTarget/SimulatedTarget.h"
#include "TCPSetting.h"
#include "UDPSetting.h"
#include "CPACalc/CPACalculator.h" // <-- NEW COLLISION ENGINE IMPORT

QString formatDecimalDegrees(double decimalDegrees, bool isLongitude) {
    QString direction;
    if (isLongitude) {
        direction = (decimalDegrees >= 0) ? "E" : "W";
    } else {
        direction = (decimalDegrees >= 0) ? "N" : "S";
    }

    double absVal = std::abs(decimalDegrees);
    int degrees = static_cast<int>(absVal);
    double minutes = (absVal - degrees) * 60.0;

    if (isLongitude) {
        return QString("%1° %2' %3")
            .arg(degrees, 3, 10, QChar('0'))
            .arg(minutes, 5, 'f', 2, QChar('0'))
            .arg(direction);
    } else {
        return QString("%1° %2' %3")
            .arg(degrees, 2, 10, QChar('0'))
            .arg(minutes, 5, 'f', 2, QChar('0'))
            .arg(direction);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect availableSpace = screen->availableGeometry();

    //split calc
    int halfWidth = availableSpace.width() / 2;
    int fullHeight = availableSpace.height();
    this->setFixedSize(halfWidth, fullHeight);
    this->move(availableSpace.x() + halfWidth, availableSpace.y());
    ui->Config_Frame->hide();

    QWidget *central = ui->centralWidget;

    cursorBearing_le = central->findChild<QLineEdit*>("cursorBearing_le");
    cursorRange_le = central->findChild<QLineEdit*>("cursorRange_le");

    if (!cursorBearing_le) cursorBearing_le = new QLineEdit("N/A", this);
    if (!cursorRange_le) cursorRange_le = new QLineEdit("N/A", this);

    cursorBearing_le->setReadOnly(true);
    cursorBearing_le->setAlignment(Qt::AlignCenter);

    cursorRange_le->setReadOnly(true);
    cursorRange_le->setAlignment(Qt::AlignCenter);

    alertBox = new QDialog(this);
    alertBox->setWindowTitle("SYSTEM ALERT");
    alertBox->setModal(false);
    alertBox->setFixedSize(300, 100);
    alertBoxLabel = new QLabel("⚠ PROXIMITY ALERT ⚠", alertBox);
    alertBoxLabel->setAlignment(Qt::AlignCenter);
    alertBoxLabel->setWordWrap(true);
    QVBoxLayout *alertLayout = new QVBoxLayout(alertBox);
    alertLayout->addWidget(alertBoxLabel);

    telemetryFrame = new QFrame(central);
    telemetryFrame->setFrameShape(QFrame::StyledPanel);
    telemetryFrame->setFrameShadow(QFrame::Raised);
    telemetryFrame->setFixedSize(300, 180);
    telemetryFrame->setStyleSheet("background-color: #1a1a1a; color: #00ff00; border: 2px solid #005500; border-radius: 5px;");

    QLabel *titleLabel = new QLabel("SENSOR DATA", telemetryFrame);
    titleLabel->setGeometry(10, 5, 280, 20);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-weight: bold; font-size: 14px; color: white; border: none; border-bottom: 1px solid gray;");

    telemetryLabel = new QLabel("No data...", telemetryFrame);
    telemetryLabel->setGeometry(10, 35, 280, 135);
    telemetryLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    telemetryLabel->setStyleSheet("font-size: 16px; font-weight: bold; border: none;");
    telemetryFrame->hide();

    connect(ui->DGPS, &QPushButton::clicked, this, &MainWindow::handleGPSClick);
    connect(ui->LOG, &QPushButton::clicked, this, &MainWindow::handleLOGClick);
    connect(ui->ECHO, &QPushButton::clicked, this, &MainWindow::handleECHOClick);
    connect(ui->AWOS, &QPushButton::clicked, this, &MainWindow::handleAWOSClick);

    setupRadarDisplay();

    connect(ui->scale_selector_cb, &QComboBox::currentTextChanged, this, &MainWindow::on_scale_selector_cb_currentTextChanged);

    ui->scale_selector_cb->setCurrentText("24");
    on_scale_selector_cb_currentTextChanged("24");

    isBlinkVisible = true;
    dangerZoneNM = 6.0;

    alarmTimer = new QTimer(this);
    connect(alarmTimer,&QTimer::timeout,this,&MainWindow::runProximitySweep);
    alarmTimer->start(500);

    udpWindow = new UDPSetting(this);
    udpWindow->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    udpWindow->setWindowTitle("UDP Configuration");
    udpWindow->setGeometry(100,100,600,600);
    udpWindow->hide();

    tcpWindow = new TCPSetting(this);
    tcpWindow->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    tcpWindow->setWindowTitle("TCP Configuration");
    tcpWindow->setGeometry(100,100,600,600);
    tcpWindow->hide();

    if(tcpWindow){
        connect(tcpWindow,&TCPSetting::dataReceived,this,&MainWindow::processIncomingNMEA);
        connect(tcpWindow,&TCPSetting::dataReceived,this,&MainWindow::processIncomingAIS);
    }

    if(udpWindow){
        connect(udpWindow,&UDPSetting::dataReceived,this,&MainWindow::processIncomingNMEA);
        connect(udpWindow,&UDPSetting::dataReceived,this,&MainWindow::processIncomingAIS);
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    ui->gv_Radar->setGeometry(0, 50, this->width(), this->height() - 100);

    int bY = this->height() - 40;
    ui->DGPS->setGeometry(10, bY, 60, 26);
    ui->LOG->setGeometry(80, bY, 60, 26);
    ui->ECHO->setGeometry(150, bY, 60, 26);
    ui->AWOS->setGeometry(220, bY, 60, 26);
    ui->COMMS->setGeometry(this->width() - 80, bY, 60, 26);

    ui->scale_selector_cb->move(this->width() - 130, 10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculateChecksum(QString answer)
{
    int checksum = 0;
    for (int i = 0; i < answer.length(); ++i) {
        checksum ^=  answer.at(i).toLatin1();
    }
    return QString::number(checksum, 16).toUpper().rightJustified(2, '0');
}

void MainWindow::setupRadarDisplay()
{
    radarScene = new QGraphicsScene(this);
    ui->gv_Radar->setScene(radarScene);
    ui->gv_Radar->setRenderHint(QPainter::Antialiasing);
    ui->gv_Radar->setBackgroundBrush(Qt::black); // BG: black

    int radarRadius = 400;
    radarScene->setSceneRect(-radarRadius, -radarRadius, radarRadius * 2, radarRadius * 2);

    QPen ringPen(QColor(0, 150, 0));
    ringPen.setWidth(1);
    ringPen.setStyle(Qt::DashLine);

    QPen axisPen(QColor(0, 255, 0));
    axisPen.setWidth(2);

    // 2. Draw the Rings
    int numRings = 10;
    int ringSpacing = radarRadius / numRings;

    for (int i = 1; i <= numRings; ++i) {
        int r = i * ringSpacing;
        radarScene->addEllipse(-r, -r, r * 2, r * 2, ringPen);
    }

    // Crosshairs
    radarScene->addLine(0, -radarRadius, 0, radarRadius, axisPen); // Vertical Line
    radarScene->addLine(-radarRadius, 0, radarRadius, 0, axisPen); // Horizontal Line

    ui->gv_Radar->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gv_Radar->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gv_Radar->setMouseTracking(true); // IMPORTANT

    radarRangeNM = ui->scale_selector_cb->currentText().toDouble();
    if (radarRangeNM <= 0) radarRangeNM = 24.0;

    masterClock = new QTimer(this);
    connect(masterClock, &QTimer::timeout, this, &MainWindow::onMasterClock);
    masterClock->start(1000);

    QPen sweepPen(QColor(0, 255, 0));
    sweepPen.setWidth(2);
    sweeper = radarScene->addLine(0, 0, 0, -radarRadius, sweepPen);

    QColor dzColor(Qt::red);
    dzColor.setAlpha(40);
    dangerCircle = radarScene->addEllipse(0, 0, 0, 0, QPen(Qt::red, 2, Qt::SolidLine), QBrush(dzColor));
    dangerCircle->setZValue(5);

    currentAngle = 0.0;

    sweepTimer = new QTimer(this);
    connect(sweepTimer, &QTimer::timeout, this, &MainWindow::onSweeperTimer);
    sweepTimer->start(30);

    targetDataBox = radarScene->addText("");
    targetDataBox->setDefaultTextColor(Qt::cyan);

    targetDataBox = radarScene->addText("");
    targetDataBox->setZValue(20);
    targetDataBox->hide();

    radarScene->installEventFilter(this);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event) //Mouse tracking
{
    if (watched == radarScene && event->type() == QEvent::GraphicsSceneMouseMove) {
        QGraphicsSceneMouseEvent *mouseEvent = static_cast<QGraphicsSceneMouseEvent*>(event);
        QPointF pos = mouseEvent->scenePos();

        double pixelDist = qSqrt(qPow(pos.x(), 2) + qPow(pos.y(), 2));

        double rangeNM = (pixelDist / 300.0) * radarRangeNM;

        double angleRad = qAtan2(pos.x(), -pos.y());
        double angleDeg = qRadiansToDegrees(angleRad);
        if (angleDeg < 0) angleDeg += 360.0;

        cursorBearing_le->setText(QString("%1 deg").arg(angleDeg, 0, 'f', 1));
        cursorRange_le->setText(QString("%1 NM").arg(rangeNM, 0, 'f', 2));
    }

    else if (watched == radarScene && event->type() == QEvent::GraphicsSceneMousePress) {
        QGraphicsSceneMouseEvent *mouseEvent = static_cast<QGraphicsSceneMouseEvent*>(event);
        QPointF clickPos = mouseEvent->scenePos();

        QRectF hitBox(clickPos.x() - 10, clickPos.y() - 10, 20, 20);
        QList<QGraphicsItem*> hitItems = radarScene->items(hitBox);

        bool lockedOn = false;

        for (QGraphicsItem* item : hitItems) {
            if (item && !item->data(0).toString().isEmpty()) {
                QString targetName = item->data(0).toString();

                for(SimulatedTarget* ship : std::as_const(activeFleet)){
                    if(ship->getName() == targetName) {
                        selectedShip = ship;
                        lockedOn = true;

                        redrawAllTgt();
                        break;
                    }
                }
            }
            if (lockedOn) break;
        }

        if (!lockedOn) {
            qDebug() << "Clicked empty water. Clearing selection.";
            selectedShip = nullptr;
            targetDataBox->hide();
        }

        return true;
    }
    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::onMasterClock()
{
    qint64 now = QDateTime::currentMSecsSinceEpoch();

    for (int i = activeFleet.size() - 1; i >= 0; --i) {
        SimulatedTarget* ship = activeFleet[i];
        QString name = ship->getName();

        if (targetLastSeen.contains(name) && (now - targetLastSeen[name] > 5000)) {
            if (radarBlips.contains(ship)) {
                radarScene->removeItem(radarBlips[ship]);
                delete radarBlips[ship];
                radarBlips.remove(ship);
            }
            targetLastSeen.remove(name);
            activeFleet.removeAt(i);
            delete ship;
            continue;
        }

        double speedKts = ship->getSpeed();
        double courseDeg = ship->getCourse();

        if (speedKts > 0.0) {
            double distanceNM = speedKts / 3600.0;

            double courseRad = qDegreesToRadians(courseDeg);

            double deltaX = distanceNM * qSin(courseRad);
            double deltaY = distanceNM * qCos(courseRad);

            ship->setX(ship->getX() + deltaX);
            ship->setY(ship->getY() + deltaY);
        }
    }

    redrawAllTgt();
}

void MainWindow::onSweeperTimer()
{
    currentAngle += 2.0;

    if(currentAngle >= 360.0){
        currentAngle -= 360.0;
    }
    sweeper->setRotation(currentAngle);
}

void MainWindow::processIncomingNMEA(const QString &sentence)
{
    if (sentence.contains("!AIVDM")) {
        processIncomingAIS(sentence);
    }
    else if (sentence.contains("$RATTM")) {
        processIncomingTTM(sentence);
    }
    else if (sentence.contains("RMC")) { // $GPRMC, $GNRMC
        QStringList parts = sentence.split(',');
        if (parts.size() >= 10) {
            currentTelemetry.lat = parts[3] + " " + parts[4];
            currentTelemetry.lon = parts[5] + " " + parts[6];
            currentTelemetry.sog = parts[7];
            currentTelemetry.cog = parts[8];
        }
    }
    else if (sentence.contains("MWV")) { // $WIMWV
        QStringList parts = sentence.split(',');
        if (parts.size() >= 6) {
            QString angleStr = parts[1];
            QString ref = parts[2];
            QString speedStr = parts[3];

            currentTelemetry.windDir = angleStr;
            currentTelemetry.windSpeed = speedStr;

            QString formattedWind = speedStr + " kts @ " + angleStr + "°";
            if (ref == "T") {
                currentTelemetry.trueWind = formattedWind;
            } else if (ref == "R") {
                currentTelemetry.relWind = formattedWind;
            }

            updateTelemetryDisplay();
        }
    }
    else if (sentence.contains("MDA")) { // $WIMDA
        QStringList parts = sentence.split(',');
        if (parts.size() >= 11) {
            currentTelemetry.pressure = parts[3] + " B";
            currentTelemetry.airTemp = parts[5] + " °C";
            currentTelemetry.humidity = parts[9] + " %";

            updateTelemetryDisplay();
        }
    }
    else if (sentence.contains("DPT")) { // $SDDPT
        QStringList parts = sentence.split(',');
        if (parts.size() >= 2) {
            currentTelemetry.depth = parts[1];
        }
    }
    else if (sentence.contains("DBT")) { // $SDDBT
        QStringList parts = sentence.split(',');
        if (parts.size() >= 4) {
            currentTelemetry.depth = parts[3];
        }
    }
    else if (sentence.contains("VHW")) { // $VDVHW
        QStringList parts = sentence.split(',');
        if (parts.size() >= 6) {
            currentTelemetry.waterSpeed = parts[5];
        }
    }else if (sentence.contains("VBW")) { // $GPVBW
        QStringList parts = sentence.split(',');
        if (parts.size() >= 4 && parts[3] == "A") { // Ensure valid status
            currentTelemetry.waterSpeed = parts[1];
        } else if (parts.size() >= 2 && parts[1] != "") { // Fallback to raw value
            currentTelemetry.waterSpeed = parts[1];
        }
    }
    else if (sentence.contains("LOG") || sentence.contains("$VDVLW")) {
    }

    updateTelemetryDisplay();
}

void MainWindow::updateTelemetryDisplay() {
    QString text = "";
    if (currentActiveModule == "GPS") {

        double latDec = 0.0;
        if (currentTelemetry.lat.contains(" ")) {
            QStringList p = currentTelemetry.lat.split(' ');
            latDec = p[0].left(2).toDouble() + (p[0].mid(2).toDouble() / 60.0);
            if (p[1] == "S") latDec = -latDec;
        }

        double lonDec = 0.0;
        if (currentTelemetry.lon.contains(" ")) {
            QStringList p = currentTelemetry.lon.split(' ');
            lonDec = p[0].left(3).toDouble() + (p[0].mid(3).toDouble() / 60.0);
            if (p[1] == "W") lonDec = -lonDec;
        }

        text = QString("Latitude : %1\n"
                       "Longitude: %2\n"
                       "Bearing : %3 deg\n")
                   .arg(formatDecimalDegrees(latDec, false)) // false = Latitude
                   .arg(formatDecimalDegrees(lonDec, true))  // true = Longitude
                   .arg(currentTelemetry.cog);
    } else if (currentActiveModule == "LOG") {

        double stw = currentTelemetry.waterSpeed.toDouble();
        double sog = currentTelemetry.sog.toDouble();
        double cog = currentTelemetry.cog.toDouble();

        text = QString("Speed Over Ground : %1 knots\n"
                       "Course Over Ground : %2 deg\n"
                       "Speed Over Water : %3 knots")
                   .arg(sog, 0, 'f', 1)
                   .arg(cog, 0, 'f', 1)
                   .arg(stw, 0, 'f', 1);
    } else if (currentActiveModule == "ECHO") {
        text = QString("Depth: %1 meters").arg(currentTelemetry.depth);
    }else if (currentActiveModule == "AWOS") {
        QString tWind = currentTelemetry.trueWind.isEmpty() ? "---" : currentTelemetry.trueWind;
        QString rWind = currentTelemetry.relWind.isEmpty() ? "---" : currentTelemetry.relWind;

        text = QString("Relative Wind: %1\n"
                       "True Wind:     %2")
                   .arg(rWind)
                   .arg(tWind);
    } else if (currentActiveModule == "WIND") {
        text = QString("Wind Direction: %1 deg\nWind Speed: %2 knots")
        .arg(currentTelemetry.windDir).arg(currentTelemetry.windSpeed);
    }

    telemetryLabel->setText(text);
}

void MainWindow::handleGPSClick() {
    udpWindow->hide(); tcpWindow->hide();
    if(telemetryFrame->isVisible() && currentActiveModule == "GPS"){ telemetryFrame->hide(); return; }
    currentActiveModule = "GPS";
    updateTelemetryDisplay();
    telemetryFrame->move(20, this->height() - telemetryFrame->height() - 80);
    telemetryFrame->show(); telemetryFrame->raise();
}

void MainWindow::handleLOGClick() {
    ui->Config_Frame->hide(); udpWindow->hide(); tcpWindow->hide();
    if(telemetryFrame->isVisible() && currentActiveModule == "LOG"){ telemetryFrame->hide(); return; }
    currentActiveModule = "LOG";
    updateTelemetryDisplay();
    telemetryFrame->move(20, this->height() - telemetryFrame->height() - 80);
    telemetryFrame->show(); telemetryFrame->raise();
}

void MainWindow::handleECHOClick() {
    ui->Config_Frame->hide(); udpWindow->hide(); tcpWindow->hide();
    if(telemetryFrame->isVisible() && currentActiveModule == "ECHO"){ telemetryFrame->hide(); return; }
    currentActiveModule = "ECHO";
    updateTelemetryDisplay();
    telemetryFrame->move(20, this->height() - telemetryFrame->height() - 80);
    telemetryFrame->show(); telemetryFrame->raise();
}

void MainWindow::handleAWOSClick() {
    ui->Config_Frame->hide(); udpWindow->hide(); tcpWindow->hide();
    if(telemetryFrame->isVisible() && currentActiveModule == "AWOS"){ telemetryFrame->hide(); return; }
    currentActiveModule = "AWOS";
    updateTelemetryDisplay();
    telemetryFrame->move(20, this->height() - telemetryFrame->height() - 80);
    telemetryFrame->show(); telemetryFrame->raise();
}

void MainWindow::handleWINDClick() {
    ui->Config_Frame->hide(); udpWindow->hide(); tcpWindow->hide();
    if(telemetryFrame->isVisible() && currentActiveModule == "WIND"){ telemetryFrame->hide(); return; }
    currentActiveModule = "WIND";
    updateTelemetryDisplay();
    telemetryFrame->move(20, this->height() - telemetryFrame->height() - 80);
    telemetryFrame->show(); telemetryFrame->raise();
}

void MainWindow::on_scale_selector_cb_currentTextChanged(const QString &arg1)
{
    radarRangeNM = arg1.toDouble();
    redrawAllTgt();
}

void MainWindow::redrawAllTgt()
{
    double currentMaxRangeNM = ui->scale_selector_cb->currentText().toDouble();
    if (currentMaxRangeNM <= 0.0) currentMaxRangeNM = 24.0;

    double pixelsPerNM = 400.0 / currentMaxRangeNM;

    double dangerZoneNM = 6.0;
    double dzRadiusPixels = dangerZoneNM * pixelsPerNM;

    if (dangerCircle) {
        dangerCircle->setRect(-dzRadiusPixels, -dzRadiusPixels, dzRadiusPixels * 2, dzRadiusPixels * 2);
    }

    for(SimulatedTarget* ship : std::as_const(activeFleet)){
        if(radarBlips.contains(ship)){
            QGraphicsEllipseItem* dot = radarBlips[ship];

            double distNM = qSqrt(qPow(ship->getX(), 2) + qPow(ship->getY(), 2));

            if (distNM > currentMaxRangeNM) {
                dot->setVisible(false);
                dot->setOpacity(0.0);
            }
            else {
                dot->setVisible(true);
                dot->setOpacity(1.0);

                if (distNM <= dangerZoneNM) {
                    dot->setBrush(Qt::red);
                } else {
                    dot->setBrush(Qt::yellow);
                }
            }
            double screenX = ship->getX() * pixelsPerNM;
            double screenY = -(ship->getY() * pixelsPerNM);

            dot->setPos(screenX, screenY);
        }
    }

    if (targetDataBox) {

        if (selectedShip && radarBlips.contains(selectedShip) && radarBlips[selectedShip]->isVisible()) {

            QPointF dotPos = radarBlips[selectedShip]->pos();

            double ownLat = 0.0;
            double ownLon = 0.0;
            if (!currentTelemetry.lat.isEmpty()) { ownLat = currentTelemetry.lat.split(" ")[0].toDouble() / 100.0; }
            if (!currentTelemetry.lon.isEmpty()) { ownLon = currentTelemetry.lon.split(" ")[0].toDouble() / 100.0; }

            double targetLat = ownLat + (selectedShip->getY() / 60.0);
            double targetLon = ownLon + (selectedShip->getX() / (60.0 * qCos(qDegreesToRadians(ownLat))));

            // Format the pop-up data block
            QString infoHTML = QString(
                                   "<div style='background-color:rgba(0,40,0,0.9); color:cyan; border:1px solid cyan; padding:5px; font-family:monospace;'>"
                                   "<b>ID:</b> %1<br>"
                                   "<b>LAT:</b> %2<br>"
                                   "<b>LON:</b> %3<br>"
                                   "<b>SPD:</b> %4 kts<br>"
                                   "<b>CRS:</b> %5&deg;"
                                   "</div>"
                                   ).arg(selectedShip->getName())
                                   .arg(formatDecimalDegrees(targetLat, false)) //false = Latitude
                                   .arg(formatDecimalDegrees(targetLon, true))
                                   .arg(selectedShip->getSpeed(), 0, 'f', 1)
                                   .arg(selectedShip->getCourse(), 0, 'f', 1);

            targetDataBox->setHtml(infoHTML);
            targetDataBox->setPos(dotPos.x() + 15, dotPos.y() + 15);
            targetDataBox->show();

        } else {
            targetDataBox->hide(); //if clicked on empty space
        }
    }
}

QString MainWindow::aisToBinary(const QString &answer)
{
    QString binaryResult = "";
    for (int i = 0; i <answer.length();++i){
        int asciiCode = answer[i].unicode();
        int decimalCode = asciiCode-48;
        if(decimalCode > 48) decimalCode -= 8;
        binaryResult += QString::number(decimalCode , 2).rightJustified(6,'0');
    }
    return binaryResult;
}

int MainWindow::binaryToSignInt(const QString &binaryStr)
{
    if (binaryStr.isEmpty()) return 0;

    bool isNegative = (binaryStr[0] == '1');
    if (!isNegative){
        return binaryToLong(binaryStr);
    }

    QString inverted = "";
    for (int i = 0 ; i < binaryStr.length(); ++i){
        inverted += (binaryStr[i] == '1') ? '0' : '1';
    }
    return -(binaryToLong(inverted) + 1);
}

void MainWindow::processIncomingAIS(const QString &sentence)
{
    if(!sentence.contains("!AIVD")) return ;

    QStringList parts = sentence.split(',');
    if (parts.size()<6) return;

    QString answer = parts[5];
    QString binaryAnswer = aisToBinary(answer);

    if (binaryAnswer.length() < 168) return;

    int msgType = binaryToLong(binaryAnswer.mid(0,6));

    if (msgType == 1 || msgType == 2 || msgType == 3){
        long mmsi = binaryToLong(binaryAnswer.mid(8,30));
        qDebug()<< "MMSI: " << mmsi ;

        double speedKts = binaryToLong(binaryAnswer.mid(50, 10)) / 10.0;

        double courseDeg = binaryToLong(binaryAnswer.mid(116, 12)) / 10.0;

        double longitude = binaryToSignInt(binaryAnswer.mid(61,28))/ 600000.0;
        double latitude = binaryToSignInt(binaryAnswer.mid(89,27))/ 600000.0;

        double ownLat = 49.25;
        if (currentTelemetry.lat.contains(" ")) {
            QStringList p = currentTelemetry.lat.split(' ');
            if (p[0].length() >= 4) {
                double deg = p[0].left(2).toDouble();
                double min = p[0].mid(2).toDouble();
                ownLat = deg + (min / 60.0);
                if (p[1] == "S") ownLat = -ownLat;
            }
        }

        double ownLon = -123.80;
        if (currentTelemetry.lon.contains(" ")) {
            QStringList p = currentTelemetry.lon.split(' ');
            if (p[0].length() >= 5) {
                double deg = p[0].left(3).toDouble();
                double min = p[0].mid(3).toDouble();
                ownLon = deg + (min / 60.0);
                if (p[1] == "W") ownLon = -ownLon;
            }
        }

        double tgtY = (latitude - ownLat)*60.0;
        double ownLatRad = qDegreesToRadians(ownLat);
        double tgtX = (longitude - ownLon) * 60.0 * qCos(ownLatRad);

        QString tgtID = QString::number(mmsi);
        SimulatedTarget* foundShip = nullptr;

        for (SimulatedTarget* ship : std::as_const(activeFleet)){
            if(ship->getName() == tgtID){
                foundShip = ship;
                break;
            }
        }

        if(foundShip){
            foundShip->setX(tgtX);
            foundShip->setY(tgtY);
            foundShip->setSpeed(speedKts);
            foundShip->setCourse(courseDeg);
        }else{
            foundShip = new SimulatedTarget(tgtID, tgtX, tgtY, speedKts, courseDeg);
            activeFleet.append(foundShip);
        }

        if(!radarBlips.contains(foundShip)){
            QGraphicsEllipseItem *blip = radarScene->addEllipse(-3,-3,6,6,QPen(Qt::NoPen),QBrush(Qt::red));
            blip->setZValue(10);

            blip->setVisible(false);
            blip->setOpacity(0.0);

            radarBlips.insert(foundShip,blip);
        }

        // ====================================================================
        // NEW TACTICAL COLLISION ENGINE LOGIC (CPA / TCPA)
        // ====================================================================

        double mySOG = currentTelemetry.sog.toDouble();
        double myCOG = currentTelemetry.cog.toDouble();

        CollisionData alertData = CPACalculator::calculateCPA(
            ownLat, ownLon, mySOG, myCOG,
            latitude, longitude, speedKts, courseDeg
            );

        if (alertData.isDiverging) {
            qDebug() << "AIS Target" << tgtID << "is moving away. SAFE.";
        } else {
            qDebug() << "AIS Target" << tgtID << "- CPA:" << alertData.cpaNM << "NM in" << alertData.tcpaMin << "min";

            // ALARM TRIGGER: If CPA is < 1.0 NM and TCPA is < 15.0 minutes
            if (alertData.cpaNM < 1.0 && alertData.tcpaMin < 15.0) {
                qDebug() << "!!! AIS COLLISION WARNING: MMSI" << tgtID << "!!!";

                alertBoxLabel->setText(QString(" ⚠ COLLISION WARNING: AIS [%1] ⚠\nCPA: %2 NM in %3 min")
                                           .arg(tgtID)
                                           .arg(alertData.cpaNM, 0, 'f', 1)
                                           .arg(alertData.tcpaMin, 0, 'f', 1));
                alertBoxLabel->setStyleSheet("color: white; background-color: darkred; font-weight: bold; font-size: 14px; border-radius: 5px;");

                alertBox->show();
                alertBox->adjustSize();
                QPoint pos = this->mapToGlobal(QPoint(this->width() - alertBox->width() - 30, 50));
                alertBox->move(pos);
                this->activateWindow();
                this->setFocus();
            }
        }
        // ====================================================================

        redrawAllTgt();
    }
}

long MainWindow::binaryToLong(const QString &binaryStr)
{
    if (binaryStr.isEmpty()) return 0;

    long result = 0;
    for (int i = 0; i < binaryStr.length(); ++i ){
        result = (result << 1) + (binaryStr[i] == '1' ? 1:0);
    }
    return result;
}

void MainWindow::runProximitySweep()
{
    isBlinkVisible = !isBlinkVisible;
    bool anyInZone = false;
    bool newBreach = false;
    QString alertText = "";

    for (SimulatedTarget* ship : std::as_const(activeFleet))
    {
        if(radarBlips.contains(ship)){
            QGraphicsEllipseItem* dot = radarBlips.value(ship);

            double xNM = ship->getX();
            double yNM = ship->getY();

            double distanceFromShip = qSqrt(qPow(xNM,2)+qPow(yNM,2));

            if(distanceFromShip <= dangerZoneNM){
                dot->setVisible(isBlinkVisible);
                anyInZone = true;

                if (!alertedShips.contains(ship)) {
                    alertedShips.insert(ship);
                    newBreach = true;
                    qDebug() << "SYSTEM ALERT: Target" << ship->getName() << "breached" << dangerZoneNM << "NM danger zone at" << distanceFromShip << "NM";
                }
                alertText += ship->getName() + " ";

            }else{
                dot->setVisible(true);
                alertedShips.remove(ship);
            }
        }
    }

    if (anyInZone) {
        alertBoxLabel->setText(QString(" DANGER: [%1] BREACHED ZONE ").arg(alertText.trimmed()));

        if (newBreach) {
            alertBox->show();
            alertBox->adjustSize();
            QPoint pos = this->mapToGlobal(QPoint(this->width() - alertBox->width() - 30, 50));
            alertBox->move(pos);
            this->activateWindow();
            this->setFocus();
        }

        if (isBlinkVisible) {
            alertBoxLabel->setStyleSheet("color: red; background-color: yellow; font-weight: bold; font-size: 14px; border-radius: 5px;");
        } else {
            alertBoxLabel->setStyleSheet("color: white; background-color: darkred; font-weight: bold; font-size: 14px; border-radius: 5px;");
        }
    } else {
        if (alertBox->isVisible()) alertBox->hide();
    }
}

void MainWindow::processIncomingTTM(QString rawData)
{
    QStringList lines = rawData.split("\n", Qt::SkipEmptyParts);

    for (QString line : lines) {
        QStringList parts = line.trimmed().split(",");

        if (parts.size() < 4 || !parts[0].contains("RATTM")) continue;

        int rawId = parts[1].toInt();
        QString searchName = "TTM_" + QString::number(rawId);


        if (parts.size() >= 13 && parts[12] == "L") {
            for (int i = 0; i < activeFleet.size(); ++i) {
                if (activeFleet[i]->getName() == searchName) {
                    SimulatedTarget* deadShip = activeFleet[i];

                    if (radarBlips.contains(deadShip)) {
                        radarScene->removeItem(radarBlips[deadShip]);
                        delete radarBlips[deadShip];
                        radarBlips.remove(deadShip);
                    }

                    targetLastSeen.remove(searchName);
                    activeFleet.removeAt(i);
                    delete deadShip;

                    break;
                }
            }
            continue;
        }

        double rangeNM = parts[2].toDouble();
        double bearingDeg = parts[3].toDouble();

        double speedKts = 0.0;
        double courseDeg = 0.0;
        if (parts.size() >= 7) {
            speedKts = parts[5].toDouble();
            courseDeg = parts[6].toDouble();
        }

        double bearingRad = qDegreesToRadians(bearingDeg);
        double tgtX_NM = rangeNM * qSin(bearingRad);
        double tgtY_NM = rangeNM * qCos(bearingRad);

        SimulatedTarget* existingTTM = nullptr;
        for(SimulatedTarget* ship : std::as_const(activeFleet)){
            if(ship->getName() == searchName ){
                existingTTM = ship;
                break;
            }
        }

        if(existingTTM){
            existingTTM->setSpeed(speedKts);
            existingTTM->setCourse(courseDeg);

        } else {
            SimulatedTarget* newTTM = new SimulatedTarget(searchName, tgtX_NM, tgtY_NM, speedKts, courseDeg);
            activeFleet.append(newTTM);

            QGraphicsEllipseItem* dot = radarScene->addEllipse(-3, -3, 6, 6, QPen(Qt::NoPen), QBrush(Qt::yellow));
            dot->setZValue(10);
            dot->setVisible(false);
            dot->setOpacity(0.0);

            dot->setData(0, newTTM->getName());

            radarBlips.insert(newTTM, dot);
        }
        targetLastSeen[searchName] = QDateTime::currentMSecsSinceEpoch();
    }

    redrawAllTgt();
}

void MainWindow::on_COMMS_clicked(){

    if (ui->Config_Frame->isVisible()) {
        ui->Config_Frame->hide();
        return;
    }

    QPoint btnPos = ui->COMMS->mapTo(this, QPoint(0, 0));

    int newX = btnPos.x() + ui->COMMS->width() - ui->Config_Frame->width();
    int newY = btnPos.y() - ui->Config_Frame->height() - 5;

    ui->Config_Frame->move(newX, newY);
    ui->Config_Frame->raise();
    ui->Config_Frame->show();
}

void MainWindow::on_TCP_config_clicked()
{
    ui->Config_Frame->hide();

    tcpWindow->show();
    tcpWindow->raise();
    tcpWindow->activateWindow();

    QTimer::singleShot(10, this, [this]() {
        QPoint globalBtnPos = ui->COMMS->mapToGlobal(QPoint(0, 0));
        int targetX = globalBtnPos.x() + ui->COMMS->width() - tcpWindow->frameGeometry().width();
        int targetY = globalBtnPos.y() - tcpWindow->frameGeometry().height() - 20;
        tcpWindow->move(targetX, targetY);
    });
}

void MainWindow::on_UDP_config_clicked()
{
    ui->Config_Frame->hide();

    udpWindow->show();
    udpWindow->raise();
    udpWindow->activateWindow();

    QTimer::singleShot(10, this, [this]() {
        QPoint globalBtnPos = ui->COMMS->mapToGlobal(QPoint(0, 0));
        int targetX = globalBtnPos.x() + ui->COMMS->width() - udpWindow->frameGeometry().width();
        int targetY = globalBtnPos.y() - udpWindow->frameGeometry().height() - 20;
        udpWindow->move(targetX, targetY);
    });
}

void MainWindow::on_AWOS_clicked()
{

}
