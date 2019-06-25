const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

class MyVec {
public:
    class Iterator {
        /*
         * This class supports ranged for loops.
         * It includes:
         * Iterator(int*)
         * operator++
         * operator*
         * operator!=
         * */
        friend bool operator!=(Iterator& rhs, Iterator& lhs) {
            return rhs.iptr != lhs.iptr; //you want to check and see if the rhs is not equal to the left hand side
        }
        /*
         REDUNDANT - NEVER GETTING CALLED
         
        friend bool operator==(Iterator& rhs, Iterator& lhs){
            return rhs.iptr == lhs.iptr; //you want to check and see if the rhs is equal to the left hand side
        }
         */
    public:
        Iterator(int* ip) : iptr(ip) {}
        
        Iterator& operator++() {
            (iptr)++; //no dereference because you are going to end up returning the pointer
            return *this;
        }
        
        int operator*() { return *iptr; }
        
    private:
        int* iptr; //you want to return the dereferenced iptr
    };

    MyVec();
    
    MyVec(int sz, int val=0);
    
    // copy control:
    MyVec(const MyVec& v2);
    ~MyVec();
    MyVec& operator=(const MyVec& v2);
    
    void push_back(int val);
    int size() const { return sz; }
    int operator[](int i) const;
    int& operator[](int i);
    Iterator begin() const;
    Iterator end() const;
private:
    void copy(const MyVec& v2);
    int* data;
    int sz;
    int capacity;
};


void print_vector(const MyVec& v);

bool operator==(MyVec& v1, MyVec& v2);
bool operator!=(MyVec& v1, MyVec& v2);

