#include <cassert>
#include <iostream>
#include "../my_code/weather.h"

using namespace std;

int main() {
    GPS location = GPS(46.3,67.2);
    Weather irkutsk = Weather("Irkutsk",location);
    cout << irkutsk << endl; // if you don't specify to the compiler what to do, it will throw A LOT of errors
}
