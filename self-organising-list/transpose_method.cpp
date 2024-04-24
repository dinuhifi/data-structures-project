// Implementation of Self Oranizing List using Linked List

#include <iostream>
#include <stdlib.h>
using namespace std;

class List {
    struct Node {
        int data;
        int count = 0;
        Node *next;
    } *head;
    public:
        List() {
            head = NULL;
        }
        void insert(int);
        void display();
        void search(int);
        void searchAndTranspose(int);
};