#include <iostream>
#include <unordered_map>

class DisjointSet {
private:
    struct Node {
        int data;
        int rank;
        Node* parent;
    };

public:
    std::unordered_map<int, Node*> nodes;
    void makeSet(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->rank = 0;
        newNode->parent = newNode;
        nodes[data] = newNode;
    }

    Node* findSet(Node* node) {
        if (node != node->parent) {
            node->parent = findSet(node->parent);
        }
        return node->parent;
    }

    void unionSets(int data1, int data2) {
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
};

int main() {
    DisjointSet ds;

    // Example usage
    ds.makeSet(1);
    ds.makeSet(2);
    ds.makeSet(3);
    ds.makeSet(4);
    ds.makeSet(5);

    ds.unionSets(1, 2);
    ds.unionSets(3, 4);
    ds.unionSets(4, 5);

    std::cout << "Are 1 and 5 in the same set? " << (ds.findSet(ds.nodes[1]) == ds.findSet(ds.nodes[5])) << std::endl;

    ds.unionSets(2, 5);
    ds.unionSets(1, 3);

    std::cout << "Are 2 and 5 in the same set? " << (ds.findSet(ds.nodes[2]) == ds.findSet(ds.nodes[5])) << std::endl;
    std::cout << "Are 1 and 3 in the same set? " << (ds.findSet(ds.nodes[1]) == ds.findSet(ds.nodes[3])) << std::endl;
    return 0;
}