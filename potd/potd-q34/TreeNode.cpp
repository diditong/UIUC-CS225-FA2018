#include "TreeNode.h"
#include <cmath>
#include <iostream>

int getHeightBalance(TreeNode* root) {
  int leftH=getHeight(root->left_);
  int rightH=getHeight(root->right_);
  return leftH-rightH;
}

int getHeight(TreeNode* root){
  if(root==NULL)
  return -1;
  else
  return 1+ max (getHeight(root->left_),getHeight(root->right_));
}

int max(int a, int b ){
  return a < b ? b : a;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
