#include "Node.h"

using namespace std;

void Node::sortList(Node **head) {

}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
