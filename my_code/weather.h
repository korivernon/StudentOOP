#ifndef WEATHER_H
#define WEATHER_H

#include <string>

struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la), longitude(lo) {}
};

class Weather {
    friend std::ostream& operator <<(std::ostream& os, const Weather& w);
 public:
    Weather(std::string nm, GPS loc); //loc signifies the locations
    std::string get_name(); //this allows us to use get_name in the weather class
 private:
    std::string station_nm;
    GPS my_loc;
};


#endif
