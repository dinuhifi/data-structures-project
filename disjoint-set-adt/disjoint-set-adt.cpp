#include <iostream>
#include <unordered_map>
using namespace std;

class DisjointSet {
    private:
        struct Node {
            int data;
            int rank;
            Node* parent;
        };
        unordered_map<int, Node*> nodes;

    public:
        Node* getNode(int data) {
            return nodes[data];
        }
        void makeSet(int);
        Node* findSet(Node*);
        void unionSets(int, int);
};

int main() {
    DisjointSet ds;
    
    int choice, data, data1, data2;
    while (true) {
        
        getchar();
        getchar();
        system("cls");
        
        cout << "Menu:" << endl;
        cout << "1. Make Set" << endl;
        cout << "2. Union Sets" << endl;
        cout << "3. Find Set" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter data: ";
                cin >> data;
                ds.makeSet(data);
                break;
            }
            case 2: {
                cout << "Enter data 1: ";
                cin >> data1;
                cout << "Enter data 2: ";
                cin >> data2;
                ds.unionSets(data1, data2);
                break;
            }
            case 3: {
                cout << "Enter data: ";
                cin >> data;
                cout << "Parent of " << data << " is " << ds.findSet(ds.getNode(data))->parent->data << endl;
                break;
            }
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
    return 0;
}

void DisjointSet::makeSet(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->rank = 0;
        newNode->parent = newNode;
        nodes[data] = newNode;
}

DisjointSet::Node* DisjointSet::findSet(Node* node) {
        if (node != node->parent) {
            node->parent = findSet(node->parent);
        }
        return node->parent;
}

void DisjointSet::unionSets(int data1, int data2) {
        Node* node1 = nodes[data1];
        Node* node2 = nodes[data2];

        Node* parent1 = findSet(node1);
        Node* parent2 = findSet(node2);

        if (parent1 == parent2) {
            return;
        }

        if (parent1->rank >= parent2->rank) {
            parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank + 1 : parent1->rank;
            parent2->parent = parent1;
        } else {
            parent1->parent = parent2;
        }
    }