#include "Node.h"
#include<iostream>

using namespace std;

void mergeList(Node *first, Node *second) {
  Node *cur1 =first;
  Node *cur2 =second;
  Node* temp1;
  Node* temp2;
  while(cur1!=NULL&&cur2!=NULL){
   temp1=cur1->next_;
   temp2=cur2->next_;
   cur1->next_=cur2;
   cur2->next_=temp1;
   cur1=temp1;
   cur2=temp2;
}

}


Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
