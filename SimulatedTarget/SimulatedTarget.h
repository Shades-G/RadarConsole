#ifndef SIMULATEDTARGET_H
#define SIMULATEDTARGET_H

#include <QString>
#include <QtMath>

class SimulatedTarget
{
public:
    SimulatedTarget(QString name, double startX , double startY, double course , double speed);

    void updatePosition(double secondPassed);

    QString getName() const {return tgtname;}
    double getX() const {return currentX;}
    double getY() const {return currentY;}
    double getCourse() const {return currentCourse;}
    double getSpeed() const {return currentSpeedKnots;}
    void setY(double newY);
    void setX(double newX);
    void setSpeed(double newSpeed);
    void setCourse(double newCourse);

private:
    QString tgtname;
    double currentX;
    double currentY;
    double currentCourse;
    double currentSpeedKnots;
};

#endif // SIMULATEDTARGET_H
