#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node **head, Node *insert) {

   if(*head==NULL||(*head)->data_>=insert->data_){
     insert->next_=*head;
     *head=insert;

   }
else{
  Node * temp = *head;
     while(temp->next_!=NULL&&temp->next_->data_<insert->data_){
       temp=temp->next_;
}
       insert->next_=temp->next_;
       temp->next_=insert;






     }



}
