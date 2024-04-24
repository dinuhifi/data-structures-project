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
        void searchAndMoveToFront(int);
};

int main() {
    List list;
    int choice, data;
    while(1) {
        getchar();
        getchar();
        system("cls");
        cout << "1. Insert\n2. Display\n3. Search\n4. Search & Move to Front\n5. Search & Count\n6.Search & Transpose\n7. Exit\nEnter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list.insert(data);
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Enter data to search: ";
                cin >> data;
                list.search(data);
                break;
            case 4:
                cout << "Enter data to move to front: ";
                cin >> data;
                list.searchAndMoveToFront(data);
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}

// Method to insert into the linked list
void List::insert(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
}

// Method to display the linked list
void List::display() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Method to search for a data in the linked list
void List::search(int data) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == data) {
            cout << "Data found\n";
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    cout << "Data not found\n";
}

// Method to search for a data in the linked list and move it to front
void List::searchAndMoveToFront(int data) {
    Node* temp = head;
    Node* prev = NULL;
    while(temp) {
        if(temp->data == data) {
            if(prev) {
                prev->next = temp->next;
                temp->next = head;
                head = temp;
            }
            cout << "Data moved to front\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}