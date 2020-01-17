#include <vector>
#include "BTreeNode.h"

using namespace std ;



vector<int> traverse(BTreeNode* root) {
   vector<int> v;
    traverse(root,v);
     return v;
}

void traverse(BTreeNode* root,vector<int> &v){
  if(root->is_leaf_){
  for(int j =0; j < root->elements_.size() ; j ++)
    v.push_back(root->elements_[j]);

    return;
  }
  else{
    for(int i =0; i<root->children_.size(); i++){
      traverse(root->children_[i],v);
      if (i < root->elements_.size())
      v.push_back(root->elements_[i]);
    }
  }

}
