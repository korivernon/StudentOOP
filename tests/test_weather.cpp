#include <cassert>
#include <iostream>
#include <fstream>
#include "../my_code/weather.h"
#include <string>

using namespace std;

//string get_input_file(){
//    string filenm;
//    cout << "Input the name of the new readings file: \n";
//    cin  >> filenm;
//    return filenm;
//}

void get_wreadings(string filenm, Weather& w) {
    ifstream rfile(filenm);
    
//    while(!rfile) {
//        cout << "Could not read input file: " << filenm << endl;
//        rfile.open(get_input_file());
//    }
    if (!rfile) {
        cout << "Could not read input file: " << filenm << endl;
        exit(1);
    }
    
    int m, d, y;
    double temp, hum, ws;
    while (rfile >> m >> d >> y >> temp >> hum >> ws) {
        WReading wr = WReading(Date(d, m, y), temp, hum, ws);
        w.add_reading(wr);
    }
    rfile.close();
}


int main() {
    cout << d << endl;
    Weather irkutsk = Weather("Irkutsk", GPS(46.3, 67.2));
    //get_wreadings(get_input_file(), irkutsk);
    
    string filenm;
    cout << "Input the name of the new readings file:\n";
    cin >> filenm;
    
    get_wreadings(filenm, irkutsk);
    
    cout << irkutsk << endl;
}
