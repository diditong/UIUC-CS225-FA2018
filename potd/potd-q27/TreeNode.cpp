#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
  if(this==NULL)
  return -1;
  else {
  return 1+max(this->left_->getHeight(),this->right_->getHeight());
  }
}

int max(int a, int b){
  return a < b ? b : a;
}
