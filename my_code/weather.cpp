#include <iostream>
#include <string>
#include <vector>
#include "weather.h"
#include <math.h>

using namespace std;

/*
 * A constructor for weather class.
 * */
Weather::Weather(string nm, GPS loc) : station_nm(nm), my_loc(loc) { //you must declare the name of the string and you must initialize a constructor.
}
string Weather::get_name() const {
    return station_nm;
}
int Weather::get_rating() const {
    return rating;
}
void Weather::set_rating(int new_rating) {
    rating = new_rating;
}
void Weather::add_reading(WReading wr) {
    wreadings.push_back(wr);
}
double WReading::get_tempF() {
    return (temperature*(9/5)+32);}
// HI = 0.5 * {T + 61.0 + [(T-68.0)*1.2] + (RH*0.094)}

double WReading::get_heat_index(){
    return ((0.5*(get_tempF()*61+(get_tempF()-68)*1.2)));
}

double WReading::get_wind_chill(){
    return (35.74+get_tempF()*(0.6216)-35.75*(pow(windspeed,0.16)+0.4275*get_tempF()*pow(windspeed,0.16)));
}

ostream& operator<<(ostream& os, const GPS& loc){
    os << "Latitude: " << loc.latitude << ", Longitude: "<< loc.longitude; //use the exact names as used in the object; use double arrow to print out every object
    return os;
};

ostream& operator <<(ostream& os, const Date& dt){
    os << dt.day << "/" << dt.month << "/" << dt.year;
    return os;
};

Date::Date(int d, int m, int y) { // you have to set the member variables to the values.
    if ((d < 1) || (d > 31)) throw (d);
    if ((m < 1) || (m > 12)) throw (m);
    if ((y < 1) || (y > 2019)) throw (y);// how to handle exceptions
    day = d;
    month = m;
    year = y;
}

ostream& operator<<(ostream& os,const WReading& wr){
    os << " Date: " << wr.date << "; Temperature: °F " <<  wr.temperature << "; Humidity: " << wr. humidity << "; Windspeed: " << wr.windspeed << " MPH ";
    return os;
};

ostream& operator<<(ostream& os, const Weather& w) { //to ensure access, copy and paste to reduce animosity
    //int r = w.get_rating(); no need to do this
    // w.set_rating(47); we cannot set a rating because set rating is declared as a constant
    os << "Station Name: " << w.station_nm << endl;
    os << "Rating: " << w.rating << endl;
    os << "Loacation: " << w.my_loc << endl;
    for(WReading wr: w.wreadings) {
        os << "    " << wr << endl;
    }
    return os;
}
