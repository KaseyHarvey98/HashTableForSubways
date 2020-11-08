/******************************************************************************
  Title          : gps.cpp
  Author         : Kasey Harvey
  Created on     : April 6, 2019
  Description    : Implementation of GPA class
  Purpose        : Encapsulates GPS points
  Build with     : no building
******************************************************************************/
#include "gps.h"
#include <cmath>
using namespace std;

const double R = 6372.8;       // radius of the earth
const double TO_RAD= M_PI / 180.0; // conversion of degrees to rads
double haversine ( double lat1 , double lon1 , double lat2 , double lon2 ) {
    lat1         = TO_RAD * lat1;
    lat2         = TO_RAD * lat2;
    lon1         = TO_RAD * lon1;
    lon2         = TO_RAD * lon2;
    double dLat  = (lat2 - lat1)/2; 
    double dLon  = (lon2 - lon1)/2; 
    double a     = sin(dLat);
    double b     = sin(dLon);
    return 2* R * asin(sqrt(a*a + cos(lat1)*cos(lat2)*b*b));
}
bool isNegative(double num){
    if (num < 0) return true;
    return false;
}

GPS::GPS( double lon, double lat )throw (BadPoint){
    if (isNegative(lon)|| isNegative(lat)){
        catch (BadPoint GPS);
    }

    longitude = lon;
    latitude  = lat;
}

GPS::GPS( const GPS & location){
    longitude = location.longitude;
    latitude  = location.latitude ;
}

 double distance_between( GPS point1, GPS point2){
    return haversine(point1.latitude, point1.longitude, point2.latitude, point2.longitude);

}


 ostream & operator<< ( ostream & out, GPS point ){
     out << point.longitude << point.latitude;
     return out;
}
