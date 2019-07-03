//
//  dynamicvsstatic.cpp
//  studentoop_test
//
//  Created by Kori Vernon on 7/3/19.
//  Copyright © 2019 Kori Vernon. All rights reserved.
//

#include <iostream>
using namespace std;

class Animal { public:
    virtual void roar() {
        //dynamic binding.. the compiler only knows this is an animal pointer
        cout << "Huh?"<< endl ;
    }
};

class Tiger: public Animal
{ public:
    void roar() {
        cout << "Grrrrrrrrrrr!" << endl ;

    }
};

int main() {
    Tiger t;
    t.roar();
    Animal* aptr = &t;
    aptr -> roar(); //we have a pointer we can't access it.
}
