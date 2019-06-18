#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

// calling constructor using definition
Complex::Complex(double real, double imag): real(real) , imag(imag){}

ostream& operator<< (ostream& os, const Complex& c) {
    os << "Real: " << c.real << ", Imaginary: " << c.imag << endl;;
    return os;
}

istream& operator>> (istream& is, Complex& c) {
    is >> c.real;
    is >> c.imag;
    return is;
}
Complex::operator bool() const {
    return(real!=0 || imag!=0);
}

//pre increment
Complex& Complex::operator++() {
    ++real;
    return *this; //returns a pointer to itself. this = "self's" address
}

//post increment
Complex Complex::operator++(int dummy) {
    Complex temp = *this; //syntax for post increment
    real++;
    return temp; //can't return this - you're returning before you change it.
    
}

bool operator== (const Complex& c1, const Complex& c2) {
    if (c2.get_real() == c2.get_real() && c1.get_imag() == c2.get_imag()) {
        return true;
    } else {
        return false;
    }
}

bool operator!= (const Complex& c1, const Complex& c2) {
    if (c2.get_real() != c2.get_real() && c1.get_imag() != c2.get_imag()) {
        return true;
    } else {
        return false;
    }
}

Complex operator+ (const Complex& c1, const Complex& c2) {
    
    Complex res(c1.get_real()+c2.get_real(),c1.get_imag()+c2.get_real());
    return res;
}
Complex operator- (const Complex& c1, const Complex& c2) {
    
    Complex res(c1.get_real()-c2.get_real(),c1.get_imag()-c2.get_real());
    return res;
}

double Complex::get_real() const {return real;}

double Complex::get_imag() const {return imag;}

Complex Complex::operator* (const int i) {
    Complex prod;
    prod.real = real*i;
    prod.imag = imag*i;
    return prod;
}

