#include "Stack.h"

// `int size()` - returns the number of elements in the stack (0 if empty)
int Stack::size() const {
  return count;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Stack::isEmpty() const {
  return count==0;
}

// `void push(int val)` - pushes an item to the stack in O(1) time
void Stack::push(int value) {
   if(count==0){
     Node * temp=new Node();
     temp->data=value;
     temp->next=NULL;
     head_=temp;
   }
   else {
     Node * temp=new Node();
     temp->data=value;
     temp->next=head_;
     head_=temp;
}
count++;
}

// `int pop()` - removes an item off the stack and returns the value in O(1) time
int Stack::pop() {
  int temp1;
  if(count==0)
  return -1;

  else{
    Node * temp=head_;
    temp1=head_->data;
    head_=head_->next;
    delete temp;
    temp=NULL;
  }
  count--;
return temp1;

}
