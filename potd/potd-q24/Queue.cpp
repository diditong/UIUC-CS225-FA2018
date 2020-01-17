#include "Queue.h"

//Queue::Queue() { }

// `int size()` - returns the number of elements in the stack (0 if empty)
int Queue::size() const {
  return count;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
  return count==0;
}
// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value) {
   if(count==0){
    Node * temp=new Node();
    temp->data=value;
    temp->next=NULL;
    head_=tail_=temp;
   }
   else{
     Node * temp=new Node();
     temp->data=value;
     tail_->next=temp;
     tail_=temp;
   }
   count++;
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
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
