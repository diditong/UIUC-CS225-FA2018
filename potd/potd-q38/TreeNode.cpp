#include "TreeNode.h"
#include <algorithm>


void rightRotate(TreeNode* root) {
TreeNode* temp1 = root;
TreeNode* temp2 = root->left_->right_;
root=root->left_;
root->parent_ = temp1->parent_;
root->right_=temp1;
temp1->parent_=root;
temp1->left_=temp2;
temp2->parent_=temp1;

}


void leftRotate(TreeNode* root) {
  TreeNode* temp1 = root;
  TreeNode* temp2 = root->right_->left_;
  root=root->right_;
  root->parent_ = temp1->parent_;
  root->left_=temp1;
  temp1->parent_=root;
  temp1->right_=temp2;
  temp2->parent_=temp1;


}



void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
