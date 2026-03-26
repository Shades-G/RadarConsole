#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QDebug>
#include "QtMath"
#include "utility"
#include "LOG/CLOG.h"
#include "ECHO/CECHO.h"
#include "AWOS/CMWV.h"
#include "AWOS/CXDR.h"
#include "IBS/CIBS.h"
#include "AIS/CAIS.h"
#include "SimulatedTarget/SimulatedTarget.h"
#include "TCPSetting.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupDatabase();

    ui->scale_selector->setCurrentText("12");
    on_scale_selector_currentTextChanged("12");

    setupRadarDisplay();

    ui->GPS_Frame->hide();
    ui->AWOS_Frame->hide();
    ui->COMMS_Frame->hide();

    isBlinkVisible = true;
    dangerZoneNM = 6.0;

    alarmTimer = new QTimer(this);
    connect(alarmTimer,&QTimer::timeout,this,&MainWindow::runProximitySweep);

    alarmTimer->start(500);



    m_MemoryCreation();

    connect(objECHO,&CECHO::nmeaSentenceReady,udpWindow,&UDPSetting::sendData);
    connect(objECHO,&CECHO::nmeaSentenceReady,tcpWindow,&TCPSetting::sendData);
    connect(objMWV,&CMWV::nmeaSentenceReady,udpWindow,&UDPSetting::sendData);
    connect(objMWV,&CMWV::nmeaSentenceReady,tcpWindow,&TCPSetting::sendData);
    connect(objXDR,&CXDR::nmeaSentenceReady,udpWindow,&UDPSetting::sendData);
    connect(objXDR,&CXDR::nmeaSentenceReady,tcpWindow,&TCPSetting::sendData);
    connect(objLOG,&CLOG::nmeaSentenceReady,udpWindow,&UDPSetting::sendData);
    connect(objLOG,&CLOG::nmeaSentenceReady,tcpWindow,&TCPSetting::sendData);
    connect(objIBS, &CIBS::nmeaSentenceReady, udpWindow, &UDPSetting::sendData);
    connect(objIBS, &CIBS::nmeaSentenceReady, tcpWindow, &TCPSetting::sendData);
    connect(objAIS, &CAIS::nmeaSentenceReady, udpWindow, &UDPSetting::sendData);
    connect(objAIS, &CAIS::nmeaSentenceReady, tcpWindow, &TCPSetting::sendData);

    if(objIBS){
        connect(objIBS, &CIBS::nmeaSentenceReady , this , &MainWindow::processIncomingNMEA);
    }


    void dataRecieved(const QString &sentence);

    if(tcpWindow){
        connect(tcpWindow,&TCPSetting::dataReceived,this,&MainWindow::processIncomingNMEA);
        connect(tcpWindow,&TCPSetting::dataReceived,this,&MainWindow::processIncomingAIS);
    }

    if(udpWindow){
        connect(udpWindow,&UDPSetting::dataReceived,this,&MainWindow::processIncomingNMEA);
        connect(udpWindow,&UDPSetting::dataReceived,this,&MainWindow::processIncomingAIS);

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::m_MemoryCreation()
{
    objCRMCView = new CRMCView(this);
    objCRMCView->setGeometry(200,0,600,600);
    objCRMCView->hide();

    objGLL = new GLL(this);
    objGLL->setGeometry(200,0,600,600);
    objGLL->hide();

    objGGA = new GGA(this);
    objGGA-> setGeometry(200,0,600,600);
    objGGA->hide();

    objZDA = new ZDA(this);
    objZDA->setGeometry(200,0,600,600);
    objZDA->hide();

    objLOG = new CLOG(this);
    objLOG->setGeometry(100,0,600,600);
    objLOG->hide();

    objECHO = new CECHO(this);
    objECHO->setGeometry(100,0,600,600);
    objECHO->hide();

    objMWV = new CMWV(this);
    objMWV->setGeometry(200,0,600,600);
    objMWV->hide();

    objXDR = new CXDR(this);
    objXDR->setGeometry(200,0,600,600);
    objXDR->hide();

    udpWindow = new UDPSetting(this);
    udpWindow->setGeometry(200,0,600,600);
    udpWindow->hide();

    tcpWindow = new TCPSetting(this);
    tcpWindow->setGeometry(200,0,600,600);
    tcpWindow->hide();

    objIBS = new CIBS(this);
    objIBS->setGeometry(200,0,600,600);
    objIBS->hide();

    objAIS = new CAIS(this);
    objAIS->setGeometry(200,0,600,600);
    objAIS->hide();
}

void MainWindow::on_GPS_PB_clicked()
{
    ui->AWOS_Frame->hide();
    ui->gv_Radar->show();
    ui->scale_selector->show();
    tcpWindow->hide();
    udpWindow->hide();
    objXDR->hide();
    objMWV->hide();
    objAIS->hide();
    objLOG->hide();
    ui->COMMS_Frame->hide();
    objECHO->hide();
    objIBS->hide();
    ui->GPS_Frame->show();

}

void MainWindow::on_LOG_PB_clicked()
{
    ui->GPS_Frame->hide();
    ui->AWOS_Frame->hide();
    ui->COMMS_Frame->hide();
    ui->scale_selector->hide();
    objCRMCView->hide();
    tcpWindow->hide();
    udpWindow->hide();
    objZDA->hide();
    objMWV->hide();
    objXDR->hide();
    objAIS->hide();
    objGGA->hide();
    objGLL->hide();
    objECHO->hide();
    objIBS->hide();
    objLOG->show();
    ui->gv_Radar->hide();
}

void MainWindow::on_ECHO_PB_clicked()
{
    ui->GPS_Frame->hide();
    ui->AWOS_Frame->hide();
    ui->COMMS_Frame->hide();
    ui->scale_selector->hide();
    objCRMCView->hide();
    objZDA->hide();
    ui->gv_Radar->hide();
    tcpWindow->hide();
    udpWindow->hide();
    objGGA->hide();
    objAIS->hide();
    objXDR->hide();
    objMWV->hide();
    objGLL->hide();
    objIBS->hide();
    objLOG->hide();
    objECHO->show();

}

void MainWindow::on_RMC_PB_clicked()
{
    objGLL->hide();
    objGGA->hide();
    tcpWindow->hide();
    udpWindow->hide();
    ui->scale_selector->hide();
    ui->gv_Radar->hide();
    objXDR->hide();
    objMWV->hide();
    objCRMCView->show();
    objZDA->hide();
}

void MainWindow::on_AWOS_PB_clicked()
{
    ui->GPS_Frame->hide();
    ui->COMMS_Frame->hide();
    ui->scale_selector->hide();
    objZDA->hide();
    ui->gv_Radar->hide();
    objGGA->hide();
    tcpWindow->hide();
    udpWindow->hide();
    objAIS->hide();
    objGLL->hide();
    objLOG->hide();
    objECHO->hide();
    objIBS->hide();
    ui->AWOS_Frame->show();
}

void MainWindow::on_GLL_PB_clicked()
{
    objCRMCView->hide();
    tcpWindow->hide();
    ui->scale_selector->hide();
    udpWindow->hide();
    objGLL->show();
    objGGA->hide();
    ui->gv_Radar->hide();
    objMWV->hide();
    objXDR->hide();
    objZDA->hide();
}

void MainWindow::on_GGA_PB_clicked()
{
    objGGA->show();
    objXDR->hide();
    ui->gv_Radar->hide();
    objGLL->hide();
    objMWV->hide();
    ui->scale_selector->hide();
    tcpWindow->hide();
    udpWindow->hide();
    objCRMCView->hide();
    objZDA->hide();

}

void MainWindow::on_ZDA_PB_clicked()
{
    objZDA->show();
    objGLL->hide();
    objMWV->hide();
    ui->scale_selector->hide();
    ui->gv_Radar->hide();
    tcpWindow->hide();
    udpWindow->hide();
    objXDR->hide();
    objCRMCView->hide();
    objGGA->hide();
}


void MainWindow::on_MWV_PB_clicked()
{
    ui->GPS_Frame->hide();
    tcpWindow->hide();
    udpWindow->hide();
    ui->scale_selector->hide();
    ui->COMMS_Frame->hide();
    objXDR->hide();
    ui->gv_Radar->hide();
    objMWV->show();

}

void MainWindow::on_XDR_PB_clicked()
{
    ui->GPS_Frame->hide();
    ui->COMMS_Frame->hide();
    objMWV->hide();
    ui->scale_selector->hide();
    ui->gv_Radar->hide();
    tcpWindow->hide();
    udpWindow->hide();
    objXDR->show();

}

void MainWindow::on_COMMS_PB_clicked()
{
    ui->AWOS_Frame->hide();
    ui->GPS_Frame->hide();
    objAIS->hide();
    ui->scale_selector->hide();
    ui->gv_Radar->hide();
    objGLL->hide();
    objMWV->hide();
    objXDR->hide();
    objGGA->hide();
    objECHO->hide();
    objLOG->hide();
    udpWindow->hide();
    tcpWindow->hide();
    objIBS->hide();
    ui->COMMS_Frame->show();
}

void MainWindow::on_UDP_PB_clicked()
{
    udpWindow->show();
    ui->gv_Radar->hide();
    ui->scale_selector->hide();
    tcpWindow->hide();
}

void MainWindow::on_TCP_PB_clicked()
{
    tcpWindow->show();
    ui->scale_selector->hide();
    ui->gv_Radar->hide();
    udpWindow->hide();
}

void MainWindow::on_IBS_PB_clicked()
{
    ui->GPS_Frame->hide();
    ui->scale_selector->hide();
    ui->AWOS_Frame->hide();
    ui->COMMS_Frame->hide();
    objCRMCView->hide();
    ui->gv_Radar->hide();
    objZDA->hide();
    tcpWindow->hide();
    udpWindow->hide();
    objGGA->hide();
    objXDR->hide();
    objMWV->hide();
    objGLL->hide();
    objIBS->hide();
    objLOG->hide();
    objAIS->hide();
    objECHO->hide();
    objIBS->show();
}


void MainWindow::on_AIS_PB_clicked()
{
    ui->GPS_Frame->hide();
    ui->AWOS_Frame->hide();
    ui->scale_selector->hide();
    ui->COMMS_Frame->hide();
    objCRMCView->hide();
    objZDA->hide();
    tcpWindow->hide();
    ui->gv_Radar->hide();
    udpWindow->hide();
    objGGA->hide();
    objXDR->hide();
    objMWV->hide();
    objGLL->hide();
    objIBS->hide();
    objLOG->hide();
    objECHO->hide();
    objIBS->hide();
    objAIS->show();
}

QString MainWindow::calculateChecksum(QString answer)
{
    int checksum = 0;
    // XOR every character in the string
    for (int i = 0; i < answer.length(); ++i) {
        checksum ^=  answer.at(i).toLatin1();
    }
    // Return as a 2-character hex string (e.g., "4A")
    return QString::number(checksum, 16).toUpper().rightJustified(2, '0');
}

void MainWindow::setupRadarDisplay()
{
    radarScene = new QGraphicsScene(this);
    ui->gv_Radar->setScene(radarScene);
    ui->gv_Radar->setRenderHint(QPainter::Antialiasing); //antialiasing (no pixeling)
    radarScene->setBackgroundBrush(Qt::black);//BG:Black

    int radarRadius = 300;
    radarScene->setSceneRect(-radarRadius,-radarRadius,radarRadius * 2, radarRadius * 2);

    QPen ringPen(QColor(0,150,0));
    ringPen.setWidth(1);
    ringPen.setStyle(Qt::DashLine);

    QPen axisPen(QColor(0,255,0));
    axisPen.setWidth(2);

    int numRings = 5; // 5 range rings is standard
    int ringSpacing = radarRadius / numRings;

    for (int i = 1; i <= numRings; ++i) {
        int r = i * ringSpacing;
        // addEllipse takes (x, y, width, height).
        // Since center is 0,0, top-left corner of the bounding box is -r, -r
        radarScene->addEllipse(-r, -r, r * 2, r * 2, ringPen);
    }

    // 5. Draw the Crosshairs (North/South, East/West)
    radarScene->addLine(0, -radarRadius, 0, radarRadius, axisPen); // Vertical line
    radarScene->addLine(-radarRadius, 0, radarRadius, 0, axisPen); // Horizontal line

    // Optional: Keep the view centered and stop it from adding scrollbars
    ui->gv_Radar->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gv_Radar->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    double radarRangeNM = 12.0;

    // Spawn "Test Ship" at 2 NM East, 3 NM South, steering 045 degrees at a fast 60 knots
    activeFleet.append(new SimulatedTarget("Test Ship",2.0,-3.0,45.0,60.0));

    masterClock = new QTimer(this);
    connect(masterClock, &QTimer::timeout, this, &MainWindow::onMasterClock);
    masterClock->start(1000);

    QPen sweepPen(QColor(0,255,0));
    sweepPen.setWidth(2);

    sweeper = radarScene->addLine(0,0,0,-300,sweepPen);

    currentAngle = 0.0;

    sweepTimer = new QTimer(this);
    connect(sweepTimer,&QTimer::timeout, this , &MainWindow::onSweeperTimer);
    sweepTimer->start(30);

    radarScene->installEventFilter(this); //report clicks
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    return QMainWindow::eventFilter(watched,event);
}

void MainWindow::onMasterClock()
{
    //qDebug() <<"master clock ticked"<< activeFleet.size();
    double scale = 300.0/radarRangeNM;

    for (SimulatedTarget* ship : activeFleet){

        if (!radarBlips.contains(ship)){

            QGraphicsEllipseItem *blip = radarScene->addEllipse(-3,-3,6,6,QPen(Qt::NoPen),QBrush(Qt::red));

            blip->setZValue(10);

            radarBlips.insert(ship,blip);

        }

        double screenX = ship->getX() * scale;
        double screenY = -(ship->getY() * scale);

        radarBlips[ship]->setPos(screenX,screenY);
    }
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
    // The Traffic Cop: strictly routes data, does zero math!
    if (sentence.contains("!AIVDM")) {
        processIncomingAIS(sentence);
    }
    else if (sentence.contains("$RATTM")) {
        processIncomingTTM(sentence);
    }
}
void MainWindow::on_scale_selector_currentTextChanged(const QString &arg1)
{
    radarRangeNM = arg1.toDouble();
    redrawAllTgt();
}

void MainWindow::redrawAllTgt()
{
    if(radarRangeNM <= 0){
        radarRangeNM = 12.0;
    }

    double scale = 300.0/radarRangeNM;

    for (SimulatedTarget* ship : std::as_const(activeFleet))  {
        if(radarBlips.contains(ship)){
            double screenX = ship->getX() * scale;
            double screenY = -(ship->getY() * scale);

            //qDebug() << "DRAWING SHIP:" << ship->getName() << "| PIXELS -> X:" << screenX << " Y:" << screenY;

            radarBlips[ship]->setPos(screenX,screenY);
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
    qDebug() << "Message Type " << msgType;

    if (msgType == 1 || msgType == 2 || msgType == 3){
        long mmsi = binaryToLong(binaryAnswer.mid(8,30));
        qDebug()<< "MMSI: " << mmsi ;

        QString lonBinary = binaryAnswer.mid(61, 28);
        QString latBinary = binaryAnswer.mid(89, 27);

        double longitude = binaryToSignInt(binaryAnswer.mid(61,28))/ 600000.0;
        qDebug()<< "Lon: " << longitude ;

        double latitude = binaryToSignInt(binaryAnswer.mid(89,27))/ 600000.0;
        qDebug()<< "Lat: " << latitude ;

        logTargetToDB(QString::number(mmsi), latitude , longitude , 0.0 , "AIS");

        qDebug() << "Lon Binary:" << lonBinary << "-> Degrees:" << longitude;
        qDebug() << "Lat Binary:" << latBinary << "-> Degrees:" << latitude;


        double ownLat = 49.25;
        double ownLon = -123.80;

        double tgtY = (latitude - ownLat)*60.0;

        double ownLatRad = qDegreesToRadians(ownLat);
        double tgtX = (longitude - ownLon) * 60.0 * qCos(ownLatRad);

        qDebug() << "TARGET X (NM):" << tgtX << "TARGET Y (NM):" << tgtY;

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
        }else{
            foundShip = new SimulatedTarget(tgtID,tgtX,tgtY,0,0);
            activeFleet.append(foundShip);
        }

        if(!radarBlips.contains(foundShip)){
            QGraphicsEllipseItem *blip = radarScene->addEllipse(-3,-3,6,6,QPen(Qt::NoPen),QBrush(Qt::red));
            blip->setZValue(10);
            radarBlips.insert(foundShip,blip);
        }

        redrawAllTgt();
        qDebug() << "------Target Plotted! ---";
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

    for (SimulatedTarget* ship : std::as_const(activeFleet))
    {
        if(radarBlips.contains(ship)){
            QGraphicsEllipseItem* dot = radarBlips.value(ship);

            double xNM = ship->getX();
            double yNM = ship->getY();

            double distanceFromShip = qSqrt(qPow(xNM,2)+qPow(yNM,2));

            //qDebug() << "SWEEP:" << ship->getName() << "is" << distanceFromShip << "NM away.";

            if(distanceFromShip <= dangerZoneNM){
                dot->setVisible(isBlinkVisible);
            }else{
                dot->setVisible(true);
            }
        }
    }
}


void MainWindow::setupDatabase()
{
    vdrDatabase = QSqlDatabase::addDatabase("QSQLITE");

    QString dbPath = QDir::currentPath() + "/radar_vdr_log.db";
    vdrDatabase.setDatabaseName(dbPath);

    if(!vdrDatabase.open()){
        qDebug() << "DataBase not Open" << vdrDatabase.lastError().text();
        return ;
    }

    qDebug()<<"Database online";

    QSqlQuery query(vdrDatabase);
    QString createTableSQL = "CREATE TABLE IF NOT EXISTS target_logs (id INTEGER PRIMARY KEY AUTOINCREMENT, timestamp DATETIME DEFAULT CURRENT_TIMESTAMP , tgt_id TEXT , latitude REAL , longitude REAL , speed REAL , source_type TEXT )";

    if(!query.exec(createTableSQL)){
        qDebug() << "FAILED TO CREATE TABLE " << query.lastError().text() ;
    }else{
        qDebug()<<"VDR Target Loading Table Complete";
    }
}

void MainWindow::logTargetToDB(const QString &tgt_id, double lat, double lon, double speed, const QString &sourceType)
{
    QSqlQuery query(vdrDatabase);
    query.prepare("INSERT INTO target_logs(tgt_id , latitude , longitude , speed , source_type) VALUES (:id , :lat,:lon, :speed, :type )");

    query.bindValue(":id",tgt_id);
    query.bindValue(":lat", lat);
    query.bindValue(":lon", lon);
    query.bindValue(":speed", speed);
    query.bindValue(":type", sourceType);
    query.exec();

    if(!query.exec()){
        qDebug()<< "VDR Error: " << query.lastError().text();
    }
}

void MainWindow::processIncomingTTM(QString nmeaString)
{
    QStringList parts = nmeaString.split(",");
    if (parts.size() <12 || !parts[0].contains("RATTM")) return;

    QString tgtNum = parts[1];
    double rangeNM = parts[2].toDouble();
    double bearingDeg = parts[3].toDouble();
    double speedKnots = parts[5].toDouble();

    // x = sine , y = cos
    double bearingRad = qDegreesToRadians(bearingDeg);
    double tgtX =  rangeNM * qSin(bearingRad);
    double tgtY = rangeNM * qCos(bearingRad);

    bool tgtFused = false;
    double correlationThresholdNM = 0.5;

    for(SimulatedTarget* ship :std::as_const(activeFleet)){
        if (ship->getName().startsWith("TTM")) continue;
        double dist = qSqrt(qPow(ship->getX() -  tgtX, 2) + qPow(ship->getY() - tgtY,2));
        if(dist <= correlationThresholdNM){
            qDebug()<<"Merged TTM "<<tgtNum << "with AIS "<< ship->getName();

            ship->setX(tgtX);
            ship->setY(tgtY);

            logTargetToDB(ship->getName(), 0.0 , 0.0 , speedKnots , "FUSED");

            if(radarBlips.contains(ship)){
                radarBlips[ship]->setBrush(Qt::darkBlue);
            }

            tgtFused = true;
            break;
        }
    }

    if(!tgtFused){
        QString searchName = ("TTM" + tgtNum);
        SimulatedTarget* existingTTM = nullptr;

        for(SimulatedTarget* ship : std::as_const(activeFleet)){
            if(ship->getName() == searchName ){
                existingTTM = ship;
                break;
            }
        }

        if(existingTTM){
            existingTTM->setX(tgtX);
            existingTTM->setY(tgtY);

            logTargetToDB(existingTTM->getName(), 0.0,0.0,speedKnots,"TTM_UPDATE");
        }else{
            qDebug()<<" NEW TRACK :"<< searchName;

            logTargetToDB(searchName,0.0,0.0,speedKnots,"TTM_NEW");

            SimulatedTarget* newTTM = new SimulatedTarget(searchName, tgtX,tgtY,0,0);
            activeFleet.append(newTTM);

            QGraphicsEllipseItem* dot = radarScene->addEllipse(-3,-3,6,6,QPen(Qt::NoPen),QBrush(Qt::yellow));
            dot->setZValue(10);
            radarBlips.insert(newTTM,dot);
        }
    }
    redrawAllTgt();

}
