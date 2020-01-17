#include <vector>
#include "BTreeNode.h"

using namespace std;
BTreeNode* find(BTreeNode* root, int key) {
     int i=0;
     while ( i < root->elements_.size()  && key > root-> elements_[i]) {
        i++;
    }
    if(root-> elements_[i]==key)
    return root;
    if(root->is_leaf_)
    return NULL;
    else{
      return find(root->children_[i],key);
    }
}
