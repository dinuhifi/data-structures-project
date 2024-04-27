#include <iostream>
#include <vector>
#include <stdlib.h>

# define RANK -1

using namespace std;

class DisjointSet {
    private:
        struct Node {
            int data;
            int rank = RANK;
        };
    vector<Node*> nodes;
    public:
        DisjointSet() {
            
        }
        void makeSet(int);
        void unionSets(int, int);
        Node* findSet(Node*);
        int search(int);
};

int main() {
    return 0;
}

void DisjointSet::makeSet(int data) {

    Node* newNode = new Node();
    newNode->data = data;
    newNode->rank = 0;
    nodes.push_back(newNode);

}

void DisjointSet::unionSets(int data1, int data2) {
    
    

    // if (node1->rank >= node2->rank) {
    //     node1->rank = node1->rank + node2->rank;
    //     node2->rank = node1->data;
    // } else {
    //     node2->rank = node2->rank + node1->rank;
    //     node1->rank = node2->data;
    // }
}

DisjointSet::Node* DisjointSet::findSet(Node* node) {
    if (node->rank <= RANK) {
        return node;
    }
    return findSet(nodes[node->rank]);
}

// {1}, {2}, {3}, {1,2}