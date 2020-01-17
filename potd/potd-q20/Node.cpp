#include "Node.h"
#include<iostream>
#include <algorithm>
using namespace std;


Node *listUnion(Node *first, Node *second) {
  if(first==NULL && second!=NULL)
    return new Node(*second);
  if(first!=NULL && second ==NULL)
    return new Node(*first);
  if(first==NULL && second ==NULL)
    return NULL;
    if(first->next_==NULL && second->next_ ==NULL){
      Node * a = first;
      first->next_=second;
      return a;
    }
int size=first->getNumNodes();
  int *array = new int[size];
   int a;
  for( a=0; a< size;a++){
    if(first==NULL)
    break;
    array[a]=first->data_;
    first=first->next_;
}
for(int b=a;b<size;b++){
   if(second==NULL)
     break;
  array[b]=second->data_;
  second=second->next_;
}

sort(array,array+size);
Node * result=new Node();
result->data_=array[0];
Node * temp = result;


for(int i=1; i< size;i++){
    if(array[i]!=array[i-1]){

      temp->next_=new Node();
      temp->next_->data_=array[i];
      temp=temp->next_;
}
}
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
