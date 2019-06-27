/*
 * Let's use the *Standard Template Library*!
 * First, we will include the headers we need:
 * */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/*
 * print_vec to print vectors
 NOTES: Specify the auto-reference to the item within the container.
 * */
template <typename T>
void print_vec(const string& name, vector <T> container) {
    cout<< name << ": ";
    for (T& item: container) {
        cout << item << " ";
    }
    cout<<endl;
    cout<<endl;
}

/*
 * Let's make a template for a `print_list` that can handle
 * lists of any type:
 * Templates are the C++ feature that enable generic programming.
 * */
template <typename T>
void print_list(const string& name, list <T> container) {
    cout<< name << ": ";
    for (T& item: container) {
        
        cout << item << " ";
    }
    cout << endl;
    cout << endl;
}

/*
 * But, we can go even more generic, and make a `print` that can print
 * *containers* of any sequential type:
 * */
template <typename T>
void print(const string& name, T container) {
    cout<< name << ": ";
    for( auto& item: container) {
        //auto is more widely used in more situations.
        //without auto we have to have a second template type.
        cout << item << " ";
    }
    cout<<endl;
    cout<<endl;
}


/*
 * A Cat class just so we can show these work on our types:
 * */
class Cat {
    friend ostream& operator<<(ostream& os, const Cat& cat) {
        os << "meow ";
        return os;
    }
};

/*
 * We could pass this `is_odd()` function in to a `find_if()`,
 * or pass a *lambda* instead.
 * */
bool is_odd(int n) { return (n % 2) != 0; }

/*
 * Or, we could have a *functor*!
 * */

/*
 * Our main will exercise some STL capabilities.
 * */
int main() {
    int bjarnelen = 17;
    int dennislen = 14;

    char s[]  = "Bjarne Stroustrup";
    char s2[] = "Dennis Ritchie";

    cout << "C++ creator: " << s << "\n";
    cout<<endl;
    cout << "C creator, 4th letter: " << s2[3] << "\n";
    cout<<endl;

    /*
     * Let's do some things with a `vector`.
     * We will create it with a half-open range, and then sort it.
     * */
    vector<char> cvec(s2, s2 + dennislen);
    //DONE - Kori
    print_vec("cvec", cvec);
    
    sort(cvec.begin(), cvec.end());
    //DONE - Kori
    print_vec("sorted cvec", cvec);

    /*
     * Create a `char` list:
     * */
    list<char> clist(s, s + bjarnelen);
    list<char> clist2 = clist;
    list<char> clist3(s2, s2 + dennislen);
    /*
     * The STL provides us with a `reverse()` functions that
     * reverses an iterable structure:
     * */
    reverse(clist.begin(), clist.end());
    print_list("clist reversed", clist);
    print_list("clist2 not reversed", clist2);

    /*
     * But even after `clist` is reversed, `clist` and
     * `clist2` are still permutations of each other:
     * */
    cout << "Is clist a permutation of clist2? "
        << is_permutation(clist.begin(), clist.end(), clist2.begin())
        << endl; ;
    cout << "Is clist a permutation of clist3? "
        << is_permutation(clist.begin(), clist.end(), clist3.begin())
        << endl; ;

    /*
     * Testing a list of Cats:
     * */
    Cat catptr[] = { Cat(), Cat(), Cat() };
    list<Cat> catlist(catptr, catptr + 3);
    //this prints a list of type cat
    print_list("Cat list", catlist);

    /*
     * Testing an int list:
     * */
    int ilen = 8;
    int iptr[] = { 16, 32, 64, 128, 2, 4, 8, 17 };
    list<int> ilist(iptr, iptr + ilen);
    /*
     * Our print can work for lists as well as vectors:
     * */
    //DONE
    print("print: ilist", ilist);
    print("print: sorted cvec", cvec);
    /*
     * `sort()` does not work for lists, since they aren't random access.
     * Thus lists have their own `sort()` method, called below:
     * This *won't* work: `sort(ilist.begin(), ilist.end());`
     * */
    ilist.sort();
    print("ilist sorted", ilist);

    /*
     * Let's experiment with *iterators* a bit!
     * */

    /*
     * Here we are going to pass `is_odd()` to `find_if()`.
     * */

    /*
     * Here we are going to pass functor `IsOdd` to `find_if()`.
     * */

    /*
     * Here we are going to pass a *lambda* to `find_if()`.
     * The lambda starts with `[]`. The point here is to show
     * that this form and the one above are identical in effect.
     * */
    // cout << "First lambda odd number in list is: " << *if_iter3 << endl;
}
