#include "SimulatedTarget.h"

SimulatedTarget::SimulatedTarget(QString name,double startX,double startY, double course,double speed)
{
    tgtname = name;
    currentX = startX;
    currentY = startY;
    currentCourse = course;
    currentSpeedKnots = speed;
}

void SimulatedTarget::updatePosition(double secondPassed)
{
    // Convert speed from Knots (NM/Hour) to NM/Second
    double speedPerSecond = currentSpeedKnots / 3600.0;
    double distanceTraveled = speedPerSecond * secondPassed;

    // Convert Course to Radians
    double courseRad = qDegreesToRadians(currentCourse);

    // Standard Navigation Math (North is 0 degrees)
    currentX += distanceTraveled * qSin(courseRad);
    currentY += distanceTraveled * qCos(courseRad);
}

void SimulatedTarget::setX(double newX){currentX = newX;}
void SimulatedTarget::setY(double newY){currentY = newY;}
