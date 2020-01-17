#include "Node.h"
#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;


Node * copy_(Node * orig){
if(orig==NULL)
return NULL;

Node * a=new Node();
a->data_=orig->data_;
a->next_=copy_(orig->next_);
return a;
}


Node *listSymmetricDifference(Node *first, Node *second) {
  if(first==NULL && second==NULL)
     return NULL;
     if(first==NULL||second==NULL){
       if(first!=NULL)
       return copy_(first);
       if(second!=NULL)
       return copy_(second);

     }

  if(first->next_==NULL&&second->next_==NULL)
  {
    if(first->data_==second->data_){
      return NULL;
    }
    else{
      Node *b = new Node(*first);
      b->next_= new Node(*second);
      return  b;
    }

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

sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());

for(int i =0;i<v1.size();i++){
  int temp=v1.at(i);
  for(int j = i+1; j < v1.size();j++){
  if(v1.at(j)==temp){
  v1.erase(v1.begin()+j);
  j--;
}
}
}

for(int i =0;i<v2.size();i++){
  int temp=v2.at(i);
  for(int j = i+1; j < v2.size();j++){
  if(v2.at(j)==temp){
  v2.erase(v2.begin()+j);
  j--;
}
}
}

for(int i =0;i<v1.size();i++){
  cout<<v1.at(i)<<" ";
}
cout<<endl;
for(int i =0;i<v2.size();i++){
  cout<<v2.at(i)<<" ";
}


Node * temp;
Node * prev;
Node * result =new Node();
result->next_=NULL;
temp=result;
prev=temp;
bool modified = false;
for(unsigned i = 0 ; i < v1.size(); i++){
  bool single = true;

  for(unsigned j = 0 ; j < v2.size(); j++){
    if(v1.at(i)==v2.at(j)){
     single=false;
     break;
   }
     }
     if(single)
     {
       modified=true;

       temp->data_=v1.at(i);
       prev=temp;
       temp->next_=new Node();
       temp=temp->next_;

     }
 }

   for(unsigned j = 0 ; j < v2.size(); j++){
     bool single = true;

     for(unsigned i = 0 ; i< v1.size(); i++){
         if(v2.at(j)==v1.at(i)){
         single=false;
         break;
       }
     }
     if(single){

       modified=true;
       temp->data_=v2.at(j);
       prev=temp;
       temp->next_=new Node();
       temp=temp->next_;
     }
   }


if(!modified)
return NULL;
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
