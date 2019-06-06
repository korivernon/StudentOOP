#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) : station_nm(nm), my_loc(loc) { //you must declare the name of the string and you must initialize a constructor. 
    
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

ostream& operator<<(ostream& os, const GPS& loc){
    os << " Latitude: " << loc.latitude << " Longitude: "<< loc.longitude; //use the exact names as used in the object; use double arrow to print out every object
    return os;
};

ostream& operator<<(ostream& os, const Weather& w) { //to ensure access, copy and paste to reduce animosity
    //int r = w.get_rating(); no need to do this
    // w.set_rating(47); we cannot set a rating because set rating is declared as a constant
    os << "Station Name: " << w.station_nm << ": rating " << w.rating << w.my_loc;
    return os;
}
