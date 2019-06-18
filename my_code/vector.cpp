#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
    for(int i=0; i < v.size();i++) {
        cout << v[i] << ' ';
    }
}


MyVec::MyVec() {
    sz = 0;
    capacity = DEF_CAPACITY;
    data = new int[DEF_CAPACITY];
}

MyVec::MyVec(const MyVec& v2) {
    capacity = v2.capacity;
    sz = v2.size();
    int* data = new int[capacity];
    for (int i = 0; i < size(); i++){
        data[i] = v2.data[i];
    }
}

MyVec::~MyVec(){
    delete [] data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
    if (&v2 != this) {
        delete [] data;
        capacity = v2.capacity;
    }
    return *this; //delete the current object if the address is mot equal; return *this at the end.
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
    return true;
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
    if (sz == capacity) {
        capacity *= 2; //extend array size.
        int* new_data = new int[capacity];
        
        for (int i = 0; i < size() ; i++ ) {
            new_data[i]=data[i]; //copying over to new array
            
        }
        delete[] data;
    }
    data[sz++] = val; //increment the size of the vector
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
    return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
    return data[i];
}
/* Q: What did we gain with our wrapper with the c style arrays that we have?
 * A: We added a wrapper so that we can expand.
 * • SA Vector is To a Pointer as a Pointer is to a Reference.
 * Q: How do you find the length of a C-Style Array?
 * Q: What did we gain with the vector?
 * A: With a vector we gained the ability to ask for size and grow in size.
 * Q: Why don't compilers do range-checking?
 * A: It takes time.
 * Q: What is a reference?
 * A: A wrapper around the reference.
 * P: Liskov Substitution Principle:
 */
