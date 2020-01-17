#include <vector>
#include "BTreeNode.h"

using namespace std;

std::vector<int> traverse(BTreeNode* root) {
  std::vector<int> v;
  if (root == NULL) return v;

  std::vector<int> elements = root->elements_;
  std::vector<BTreeNode*> children = root->children_;
  bool leaf = root->is_leaf_;

  if (leaf) {
    for (unsigned i = 0; i < elements.size(); i++)
      v.push_back(elements[i]);
    return v;
  }
  else {
    for (unsigned i = 0; i < children.size(); i++) {
      traverse(children[i],v);
      if (i < elements.size()) v.push_back(elements[i]);
    }
    return v;
  }
}
std::vector<int> traverse(BTreeNode *root, std::vector<int> &v) {
  if ( root == NULL) return v;

  std::vector<int> elements = root->elements_;
  std::vector<BTreeNode*> children = root->children_;
  bool leaf = root->is_leaf_;
  if (leaf) {
    for (unsigned i = 0; i < elements.size(); i++) {
      v.push_back(elements[i]);
    }
    return v;
  }
  else {
    for (unsigned i = 0; i < children.size(); i++) {
      traverse(children[i],v);
      if (i < elements.size())
       v.push_back(elements[i]);
    }
    return v;
  }
}
