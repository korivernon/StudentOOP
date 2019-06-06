#include <iostream>
#include "pointers.h"

using namespace std;

void inc_by_value(int n) {
    n++;
}


void inc_with_pointer(int* iptr) {
    ++(*iptr);
}


void inc_with_reference(int& n) {
    n++;
}


Thing** create_array_of_things(int n) {
    Thing** thingsarray = new Thing*[n]; //  this allocates memory and creates an array of things
    for(int i=0; i<n;i++){
        thingsarray[i] = new Thing(i);
    }
    return thingsarray;
}

void print_all_things(Thing** things, int n) {
    for(int i=0; i<n;i++){
        cout << things[i] -> val <<" "; // you are printing everything out from the pointer
                                        // inside of things array
    }
    cout << endl; //end the line
}

void double_all_things(Thing** things, int n) {
    for(int i = 0; i < n ; i++){
        things[i] -> val *=2; //this doubles every value by accesing it, then it changes
                             //the value by multiplting it by two; this can also be done by
                            // *(things[i]).val = i
    }
}

void delete_all_things(Thing** things, int n) {
    for(int i = 0; i < n; i++) {
        delete things[i];
    }
    delete[] things;
}


void assignTA(Student* s, Student* ta) {
    s -> ta = ta; //takes the student and uses the TA to assign
}

void printTAs(vector<Student*> student) {
    for (Student* students : student) {
        if (students -> ta == nullptr) {
            cout << students -> name << " has no TA" << endl;
        }
        else {
            cout << students->name << " has TA " << students ->ta->name << endl;
        }
    }
}

