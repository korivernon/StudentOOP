#include <cassert>
#include <iostream>
#include "../my_code/tvector.h"

using namespace std;

template <typename T>
int copy_vector(MyVec<T> v) {
    MyVec<T> local_v = v;
    return local_v.size();
}

const int VEC_SZ = 20;


int main() {
    MyVec<int> iv = MyVec<int>();
    cout<<"~~~~~~~~works~~~~~~~~~"<<endl;
    for (int i = 0; i < VEC_SZ; i++) {
        iv.push_back(i);
        cout << iv[i]<<endl;
        copy_vector(iv);
    }

    assert(iv[VEC_SZ - 1] == VEC_SZ - 1);
    cout<<"~~~~~~~~~works~~~~~~~~"<<endl;
    for (int i = 0; i < iv.size(); i++) {
        iv[i] *= 2;
        cout<<iv[i]<<endl;
    }
    assert(iv[VEC_SZ - 1] == 38);
    cout<<iv[VEC_SZ-1]<<" = 38"<<endl;
    MyVec<int> v3;
    cout<<"~~~~~~~~works~~~~~~~~~"<<endl;
    for (int i = 9; i < 100; i += 9) {
        v3.push_back(i);
        cout<<v3[i]<<endl;
    }
    assert(v3[1] == 18);
    print_vector(v3);
    cout<<"~~~~~~~~~works~~~~~~~~"<<endl;
    MyVec<int> v2 = iv;
    assert(v2 == iv);
    print_vector(v2);
    cout<<"~~~~~~~~~~works~~~~~~~"<<endl;
    v2 = v3;
    assert(v2 == v3);
    print_vector(v2);
    print_vector(v3);
    cout<<"~~~~~~~~works~~~~~~~~~"<<endl;
    cout<<"testing..."<<endl;
    for (int i = 0; i < v3.size(); i++) {
        assert((v3[i] % 9) == 0);
        cout<<v3[i]<< " ";
    }
    cout<<endl;
    cout<<"testing 'Hello'"<<endl;
    MyVec<string> sv = MyVec<string>(10,"Hello");
    for (int i = 0; i < sv.size(); i++) {
        assert(sv[i] == "Hello");
    }
    print_vector(sv);
    cout<<"test done "<<endl;
}
