#include "CPACalculator.h"

CollisionData CPACalculator::calculateCPA(
    double ownLat, double ownLon, double ownSOG, double ownCOG,
    double tgtLat, double tgtLon, double tgtSOG, double tgtCOG)
{
    CollisionData result;

    // SPHERICAL MATH
    double lat1 = qDegreesToRadians(ownLat);
    double lon1 = qDegreesToRadians(ownLon);
    double lat2 = qDegreesToRadians(tgtLat);
    double lon2 = qDegreesToRadians(tgtLon);

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    double a = qPow(qSin(dLat / 2.0), 2) + qCos(lat1) * qCos(lat2) * qPow(qSin(dLon / 2.0), 2);
    double c = 2.0 * qAtan2(qSqrt(a), qSqrt(1.0 - a));
    result.distanceNM = EARTH_RADIUS_NM * c;

    // Formula for Bearing
    double y = qSin(dLon) * qCos(lat2);
    double x = qCos(lat1) * qSin(lat2) - qSin(lat1) * qCos(lat2) * qCos(dLon);
    double bearingRad = qAtan2(y, x);
    result.bearingDeg = qRadiansToDegrees(bearingRad);
    if (result.bearingDeg < 0) result.bearingDeg += 360.0;


    double bRad = qDegreesToRadians(result.bearingDeg);
    double targetX = result.distanceNM * qSin(bRad);
    double targetY = result.distanceNM * qCos(bRad);

    double ownRad = qDegreesToRadians(ownCOG);
    double ownVx = ownSOG * qSin(ownRad);
    double ownVy = ownSOG * qCos(ownRad);

    double tgtRad = qDegreesToRadians(tgtCOG);
    double tgtVx = tgtSOG * qSin(tgtRad);
    double tgtVy = tgtSOG * qCos(tgtRad);

    double relVx = tgtVx - ownVx;
    double relVy = tgtVy - ownVy;

    // Relative speed squared
    double relSpeedSq = (relVx * relVx) + (relVy * relVy);

    if (relSpeedSq < 0.001) {
        result.tcpaMin = 0.0;
        result.cpaNM = result.distanceNM;
        return result;
    }

    // Calculate time to closest approach in HOURS, then convert to MINUTES
    double tcpaHours = -(targetX * relVx + targetY * relVy) / relSpeedSq;
    result.tcpaMin = tcpaHours * 60.0;

    if (result.tcpaMin < 0) {
        // Target has already passed us, it is moving away
        result.isDiverging = true;
        result.cpaNM = result.distanceNM; // Closest point is right now
    } else {
        // Target is getting closer. Calculate exact distance at the future TCPA time
        double cpaX = targetX + (relVx * tcpaHours);
        double cpaY = targetY + (relVy * tcpaHours);
        result.cpaNM = qSqrt((cpaX * cpaX) + (cpaY * cpaY));
    }

    return result;
}
