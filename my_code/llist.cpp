#include <iostream>
#include "llist.h"

using namespace std;


/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    if (!nd) os  << "null";
    else {
        os << " data: " << nd->data << " --> "; //pointer to a node that you're passing; memory access is through the arrow.
    }
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
    if (!head) {
        head = new Node(d,nullptr);
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
    os << curr;
    if (curr) {
        print_list(os,curr->next); //recursively calling print_list to
        //output the current and you are calling the next item
        //each next pointer is the head of the list
    } else {
        os << endl;
    }
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
    head = new Node(d, head);
    }


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if (!head) return nullptr;
    else if (!head->next) return head;
    else return last(head->next);
}

/*
 * These are coming:
 */

/*
 * Delete the first node and attach head to the 2nd node:
 * */
bool del_head(Node*& head) {
    if (!head) {
        return false;
    }
    else {
        Node* temp = head;
        head = head ->next;
        delete temp;
    }
    return true;
}

/*
 * Delete the last node and set prev->next to nullptr:
 LOL I CAN'T DO THIS WITHOUT MAKING IT A POINTER TING... PLEASE HELP
 * */
bool del_tail(Node*& curr){
    if (!curr) {
        return false;
    }
    else {
        if (curr->next == nullptr) {
            delete curr;
            curr = nullptr;
        }
        else {
            del_tail(curr->next);
        }
    }
    return true;
}

///MY CODE///
//bool del_tail(Node*& prev_next){
//    prev_next = prev_next -> next;
//    delete prev_next;
//    return true;
//}

/*
 * Duplicate the entire list -- you must not share memory!
 * */
Node* duplicate(Node* head) {
    //this does not share memory
    head->next = new Node(*head->next);
    // this shares memory
    // copy = copy->next = new Listnode;
    return head;
}

/*
 * Reverse the list: return a brand new list with everything reversed.
 * */
// yeah so i dont know how to do this one! help please
Node* reverse(Node* curr, Node* new_next){
    if (curr == nullptr) return new_next;
    else {
        new_next = new Node(curr->data,new_next);
        return reverse(curr->next,new_next);
        //the current->next is the beginning elem
        //the Node(curr->data) is the data inside the next elem,
        //the new_next is the next elem
    }
}
//put list2 onto the end of list1
Node* join(Node*& list1, Node* list2) {
    last(list1) -> next = list2;
    return list1;
}
