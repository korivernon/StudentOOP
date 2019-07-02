//
//  functor.cpp
//  studentoop_test
//
//  Created by Kori Vernon on 7/2/19.
//  Copyright © 2019 Kori Vernon. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

class Sine {
    double operator()(double n) {
        return sin(n);
    }
};

class Cos {
    double operator()(double n) {
        return cos(n);
    }
};

//memo-ization --> technique of calculating the value and storing it in a memo ... similar to yield
//yield gives us a generator... we can keep on generating numbers and not have to recalculate
class Fib {
public:
    Fib() {
        for (long long int i = 0; i<MAX_FIB; i++) {
            memo[i] = NOT_CAL;
        }
    }
    long long int operator()(long long int n) {
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
