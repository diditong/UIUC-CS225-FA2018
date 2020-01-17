#include "TreeNode.h"
#include <iostream>


TreeNode * getIOP(TreeNode* target){
  TreeNode * result = target->right_;
  while(result->left_!=NULL){
    result=result->left_;
}
    return result;

}
TreeNode * deleteNode(TreeNode* root, int key) {
if(root==NULL) return root;
else if(key<root->val_) root->left_=deleteNode(root->left_,key);
else if(key>root->val_) root->right_=deleteNode(root->right_,key);

else{
  if(root->left_==NULL&&root->right_==NULL)
  {
    delete root;
    root=NULL;
  }

  else if(root->left_==NULL){
          TreeNode * temp1= root;
          root = root->right_;
          delete temp1;


  }

  else if(root->right_==NULL){
      TreeNode * temp2= root;
      root=root->left_;
      delete temp2;

  }

  else if(root->left_!=NULL&&root->right_!=NULL){
      TreeNode *IOP = getIOP(root);
      root->val_=IOP->val_;
      root->right_=deleteNode(root->right_,IOP->val_);

}

}

  return root;
}







void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
