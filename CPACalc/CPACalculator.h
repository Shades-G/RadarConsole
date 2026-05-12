#ifndef CPACALCULATOR_H
#define CPACALCULATOR_H

#include <QtMath>

struct CollisionData {
    double distanceNM = 0.0; // Current distance to target
    double bearingDeg = 0.0; // Current bearing to target
    double cpaNM = 0.0;      // Closest Point of Approach (Distance)
    double tcpaMin = 0.0;    // Time to CPA (Minutes)
    bool isDiverging = false;// True if the ship is moving away from us
};

class CPACalculator
{
public:
    static CollisionData calculateCPA(
        double ownLat, double ownLon, double ownSOG, double ownCOG,
        double tgtLat, double tgtLon, double tgtSOG, double tgtCOG);

private:
    // Earth radius in Nautical Miles for maritime calculations
    constexpr static const double EARTH_RADIUS_NM = 3440.065;
};

#endif // CPACALCULATOR_H
