#include <iostream>
#include "llist.h"

using namespace std;


/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    if (!nd) os  << "nullptr";
    else {
        os << "data: " << nd->data << " next: " << nd->next; //pointer to a node that you're passing; memory access is through the arrow.
    }
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
    if (!head) {
        Node* next = ;
    }
    else {
        add_at_end(head->next,d); // recursion
    }
    
    
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    return nullptr;
}
