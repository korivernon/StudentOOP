#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    
    friend void print_bst(const Bst<T>& bst, int level=0) //you are calling the const reference bst, initially starting at level 0
    {
        indent(level); //this places spaces so that it's easier to see our tree
        level++; //the level increments at each level
        std::cout << "data --> " << bst.data << std::endl; // the data will be called by calling std.data
        indent(level + 1); //why are we incrementing +1 here? --> A: We are showing the next level of the tree L and R sides
        std::cout << "left: ";
        if (!bst.left) std::cout << "nullptr"<< std::endl; //if there is nothing to the left then output nullptr
        else {
            std::cout << std::endl;
            indent(level); //indent the level
            print_bst(*bst.left,level); //recursively call the bst to print.
        }
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr" <<std::endl; //you are going to output the nullptr if there is nothing to the right
        else {
            std::cout << std::endl;
            indent(level); //indent the level
            print_bst(*bst.right,level); //recursively call the level.
        }
        std::cout << std::endl;
    }
    /*
    friend T min(Bst<T>& bst)
    {
        if (!bst.left) {
            return bst.data;
        }
        else {
            return min(*bst.left);
        }
    }
    */
    public:
    Bst(T d, Bst* p=nullptr,Bst* l=nullptr,Bst* r=nullptr) : data(d),parent(p),left(l),right(r) {} //constructor
    
    T min() {
        if (!left) {
            return data;
        }
        else {
            return left -> min();
        }
    }
    
    T max() {
        if (!right) {
            return data;
        }
        else {
            return right -> max();
        }
    }
    
    Bst<T>* search(T d) {
        if (d == data ) return this; //note
        else if (d < data) {
            if (!left) {
                return nullptr;
            }
            else {
                return left -> search(d);
            }
        }
        else {
            if (!right) {
                return nullptr;
            }
            else {
                return right -> search(d);
            }
        }
    }
    
    Bst<T>* insert(const T d) {
        if (d == data) return nullptr;
        else if (d < data) {
            //insert to the left
            if (!left) {
                //if there is nothing to the left
                left = new Bst(d, this); //create a new node then insert it to the left
                return left; //insert the tree to the left by returning it.
            }
            else {
                //recursively call and call insert onto left.
                return left -> insert(d);
                //return (*left).insert(d); //don't do this bc --?
            }
        }
        else {
            //insert to the right
            if (!right) {
                right = new Bst(d, this);
                return right;
            }
            else {
                return right ->insert(d); //insert thte tree to the right by returning it.
            }
        }
    }
    
    T predecessor(T d) {
        Bst<T>* node = search(d);

        if (node->left) {
            return node->left->max(); //call the next maximum of the right
        }
        else {
            Bst<T>* parent = node->parent; //parent node bst node pointer type
            while (parent) {
                if (parent->data < d) {
                    //if the parent
                    return parent->data;
                }
                parent = parent->parent; //set the parent equal to the parent.
            }
            return d; //if you get back the value itself then just return the
        }
    }
    
    T successor(T d) {
        Bst<T>* node = search(d);
        if (node->right) {
            return node->right->min(); //return the minimum of the right
        }
        else {
            Bst<T>* parent = node->parent;
            while (parent) {
                if (parent->data > d) {
                    break;
                }
                parent = parent -> parent; //return the parent of the parent data
                }
            return parent->data;
        }
    }
    
    T get_val() const {
        return data;
        }
    
    private:
        T data;
        Bst* parent;
        Bst* left;
        Bst* right;
};

/*
template <typename T>
Bst<T>* find(const T d) const { //there has to be another parameter
    //this takes nothing.. how am IIII oh
    if (d == data ) return data;
    else if (d < data) {
        if (left) {
            return left -> find(d); //continue to search to the left
        }
        else {
            return left;
        }
    }
    else {
        if (right) {
            return right->find(d);
        }
        else {
            return right;
        }
    }
}
*/

//template <typename T>
//void print_bst(const Bst<T>& bst) {
//void print_bst(Bst<int> bst) {
//    std::cout << "data: " << bst.data << "; left: ";
//
//    if (!bst.left) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.left);
//    }
//    std::cout << "; right: ";
//    if (!bst.right) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.right);
//    }
//    std::cout << std::endl;
//}

