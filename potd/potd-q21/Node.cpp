#include "Node.h"
#include<iostream>
#include <vector>
using namespace std;

Node *listIntersection(Node *first, Node *second) {
  if(first==NULL || second==NULL)
    return NULL;
  if(first->next_==NULL&&second->next_==NULL)
  {
    if(first->data_==second->data_){
      Node * a = new Node();
      a->data_=first->data_;
      a->next_=NULL;
      return a;
    }
    else
    return NULL;
  }
  vector<int> v1;
  vector<int> v2;

while(first!=NULL || second!=NULL){
  if(first!=NULL){
    v1.push_back(first->data_);
    first=first->next_;
  }
  if(second!=NULL)
  {
    v2.push_back(second->data_);
    second=second->next_;
  }
}
Node * temp;
Node * prev;
Node * result =new Node();
temp=result;

for(unsigned i = 0 ; i < v1.size(); i++){
  for(unsigned j = 0 ; j < v2.size(); j++){
    if(v1.at(i)==v2.at(j)){
     temp->data_=v1.at(i);
     prev=temp;
     temp->next_=new Node();
     temp=temp->next_;
     break;
   }}}
prev->next_=NULL;
return result;
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
