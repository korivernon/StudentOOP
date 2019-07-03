
#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

//In this function you are calling it when you raise a negative number.
template <typename T>
class NoNeg : public exception {
public:
    NoNeg(T n) : badnum(n) {}
    
    const char* what() const throw() {
        return "Argument cannot be negative. ";
    }
private:
    T badnum;
};
class Sin {public:double operator()(double r) {return sin(r);}};
class HSin {public:double operator()(double n) {return sinh(n);}};
class Power {public:double operator()(double b, double p) {return pow(b,p);}};
class Hypotn {public:double operator()(double left, double right) {return hypot(left,right);}};
class Cuber {public:double operator()(double n) {return cbrt(n);}};
class Cube {public:double operator()(double n) {return n*n*n;}};
class Fib {
public:
    Fib() {
        for (long long int i = 0; i<MAX_FIB; i++) {
            memo[i] = NOT_CAL;
        }
    }
    
    long long int operator()(long long int n) {
        if (n < 0) throw (NoNeg <long long int> (n));
        if (memo[n] != NOT_CAL) return memo[n];

        
        long long int ret = NOT_CAL;
        if (n<=1) return 1;
        else {
            ret = (operator()(n-1) + operator()(n-2));
            memo[n] = ret;
            return ret;
        }
    }
    const int MAX_FIB = 100;
    const long long int NOT_CAL = -1;
private:
    long long int* memo = new int long long[MAX_FIB];
    
};
class LN {
public:
    double operator()(double n) {
        if (n < 0) throw (NoNeg <int> (n));
        else if (0 < n && n < 100) return log(n);
        else return 1;
    }
};
// using lambda...

double square_func(double d, function<double(double)> f) {return f(d) * f(d);}
double tan_func(double d, function<double(double)> f){return f(d) + f(d);}
double cube_f(double d, function<double(double)> f){return f(d)*f(d)*f(d);}
double hypotn(double d, double c, function<double(double)> f){return hypot(4,3);}

int main() {
    // first functors:
    Sin sine = Sin();
    double d = sine(PI / 2);
    cout << "sin pi / 2 == " << d << endl;
    d = sine(0);
    cout << "sin 0 == " << d << endl;
    //FIBONACI
    Fib fib = Fib();
    long long int FIB_NUM;
    cout << "What number do you want to take the fibonaci sum to?: ";
    cin >> FIB_NUM;
    long long int f;
    try {
        f = fib(FIB_NUM);
        cout << "fib(" << FIB_NUM << ") = " << f << endl;
    }
    catch (NoNeg<long long int> T){
        cerr << "Got a Negative Number for FIB NUM sum"<<endl;
    }
    int counter = 0;
    cout<<"\n\n\n\n\n";
    cout<< "Kori's Functions\n";
    cout << "\nFunction " << ++counter <<endl;
    cout << "~~~~~~~~~~~ "<<endl;
    HSin hsine = HSin();
    d = hsine(PI/2);
    cout << "hsin of pi/2 == " << d << endl;
    // SEPARATION
    cout << "\nFunction " << ++counter <<endl;
    cout << "~~~~~~~~~~~ "<<endl;
    Power power = Power();
    d = power(2,5);
    cout << "\nThe power of 2 to the 5th power is: " << d << endl;
    // SEPARATION
    cout << "\nFunction " << ++counter <<endl;
    cout << "~~~~~~~~~~~ "<<endl;
    cout<< "Input a number to take the natural log of it: ";
    int num;
    cin >> num;
    LN ln = LN();
    //Try and except block to handle exceptions for negative numbers
    try {
        d = ln(num);
        cout << "The natural Log of " << num << ": " << d << endl;
    }
    catch (NoNeg<int> T) {
        cerr << "Got a negative number for ln: " << endl;
    }
    // SEPARATION
    cout << "\nFunction " << ++counter <<endl;
    cout << "~~~~~~~~~~~ "<<endl;
    Hypotn hypot = Hypotn();
    d = hypot(3,4);
    cout << "The hypotenuse of the sides 3 and 4 is: " << d << endl;
    // SEPARATION
    cout << "\nFunction " << ++counter <<endl;
    cout << "~~~~~~~~~~~ "<<endl;
    Cuber cuber = Cuber();
    d = cuber(4);
    cout << "The Cubed root of 4 is: " << d << endl;
    // SEPARATION
    cout << "\nFunction " << ++counter <<endl;
    cout << "~~~~~~~~~~~ "<<endl;
    Cube cube = Cube();
    d = cube(4);
    cout << "The Cube of 4 is: " << d << endl;
    cout<<"End of Kori's Functions\n";
    cout<<"\n\n\n\n\n";
    
    counter = 0;
    // then lambdas -- use several functions from cmath here:
    d = square_func(0, [](double arg) { return sin(arg);});
    cout << "Square of sin 0 = " << d << endl;
    // -->
    d = square_func(1, [](double arg) { return sin(arg);});
    cout << "Square of sin 1 = " << d << endl;
    // -->
    cout << "\nFunction " << ++counter <<endl;
    cout << "~~~~~~~~~~~ "<<endl;
    d = tan_func(1, [](double my_input ){ return tan(my_input);});
    cout << "(LAMBDA) tan of 1 PLUS tan of 1" << d << endl;
    // -->
    cout << "\nFunction " << ++counter <<endl;
    cout << "~~~~~~~~~~~ "<<endl;
    d = cube_f(4, [](double my_input) {return my_input;});
    cout << "(LAMBDA) 4 cubed: " << d << endl;
    // -->
    cout << "\nFunction " << ++counter << endl;
    cout << "~~~~~~~~~~~ "<<endl;
    d = hypotn(4,3,[](double my_input) {return my_input;});
    cout <<"(LAMBDA) Hypoteneuse of 3 and 4 is: " << d << endl;

}
