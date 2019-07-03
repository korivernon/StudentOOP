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
    void roar() {
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

class Sheep: public Animal {
public:
    void roar() {
        cout << "Baaaaaaaaah" << endl;
    }
};

int main() {
    Tiger t;
    t.roar();
    Sheep s;
    s.roar();
    Animal* aptr = &t;
    aptr -> roar(); //we have a pointer we can't access it.
    aptr = &s; //when called on a pointer without virtual, it sees what it's pointed to
    aptr->roar();
    //if a function is pure virtual, the base function CANNOT be created. 
    
}
