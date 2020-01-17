#include "TreeNode.h"
#include <queue>
#include <algorithm>
using namespace std;
TreeNode* findLastUnbalanced(TreeNode* root) {
  TreeNode * result=NULL;
  queue <TreeNode * > q;
  q.push(root);
  while(!q.empty()){
    TreeNode * temp = q.front();
    if(!isAVL(temp))
    result=temp;
    if(temp->left_!=NULL)
    q.push(temp->left_);
    if(temp->right_!=NULL)
    q.push(temp->right_);
    q.pop();
  }
   return result;
}


bool isAVL(TreeNode* root) {
  if(root==NULL)
  return true;
  if(getHeightBalance(root)>=2)
  return false;
  else
  return isAVL(root->left_)&&isAVL(root->right_);
}
int getHeight(TreeNode* root){
  if(root==NULL)
  return -1;
  else
  return 1+ max (getHeight(root->left_),getHeight(root->right_));
}
int getHeightBalance(TreeNode* root) {
  int leftH=getHeight(root->left_);
  int rightH=getHeight(root->right_);
  return abs(leftH-rightH);
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
