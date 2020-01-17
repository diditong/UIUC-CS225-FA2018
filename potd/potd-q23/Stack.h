#ifndef _STACK_H
#define _STACK_H

#include <cstddef>

class Stack {
public:
  int size() const;
  bool isEmpty() const;
  void push(int value);
  int pop();

private:
  int count;
  struct Node{
    int data;
    struct Node * next;
  };

  Node* head_;

};

#endif
