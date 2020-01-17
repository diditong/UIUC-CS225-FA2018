/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>
/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
  mirror(this->root);
}
template <typename T>
void BinaryTree<T>::mirror(Node* subRoot)
{
  if (subRoot == NULL)
  {
    return;
  }
  if (subRoot->left == NULL && subRoot->right == NULL)
  {
    return;
  }
  mirror(subRoot->left);
  mirror(subRoot->right);
  Node * temp1 = subRoot->left;
  subRoot->left = subRoot->right;
  subRoot->right = temp1;
}
/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    return isOrderedIterative(root);
}
template <typename T>
bool BinaryTree<T>::isOrderedIterative(Node* subRoot) const
{
  if (subRoot == NULL)
    return true;
  if (subRoot->left == NULL && subRoot->right == NULL )
    return true;

  stack<Node*> st;
  stack<int> st2;
  Node * current = subRoot;
  while (st.empty()!= true || st2.empty()== true)
  {
    while (current!=NULL)
    {
      st.push(current);
      current = current->left;
    }
    if (current == NULL && st.empty()!= true)
    {
      Node * tempN = st.top();
      st2.push(tempN->elem);
      st.pop();
      current = tempN->right;
    }
    if (st.empty() == true && current!=NULL)
    {
      st.push(current);
      current = current->left;
    }
  }

  int temp;
  bool flag = true;
  while (st2.empty()!=true)
  {
    temp = st2.top();
    st2.pop();
    if (st2.empty()==true)
    {
      break;
    }
    if (temp < st2.top())
    {
      flag = false;
      st2.pop();
      break;
    }
  }
  return flag;
}


/**hile (current!=NULL)
  {
    st.push(current->elem);
    current = current->left;
  }
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    return isOrderedRecursive(root);
}
template <typename T>
bool BinaryTree<T>::isOrderedRecursive(Node* subRoot) const
{
  //base case
  if (subRoot == NULL)
    return true;
  if (subRoot->left == NULL && subRoot->right == NULL )
    return true;
  //recursive check
  if (subRoot->right == NULL)
  {
    if (subRoot->left->elem <= subRoot->elem && isOrderedRecursive(subRoot->left)==true)
      return true;
    else
      return false;
  }
  if (subRoot->left == NULL)
  {
    if (isOrderedRecursive(subRoot->right)==true && subRoot->elem <= subRoot->right->elem )
      return true;
    else
      return false;
  }
  else
  {
    if (isOrderedRecursive(subRoot->right)==true && isOrderedRecursive(subRoot->left)==true && subRoot->left->elem <= subRoot->elem && subRoot->elem <= subRoot->right->elem)
      return true;
    else
      return false;
  }
}

/**
 * creates vectors of all the possible paths from the root of the tree to any leaf
 * node and adds it to another vector.
 * Path is, all sequences starting at the root node and continuing
 * downwards, ending at a leaf node. Paths ending in a left node should be
 * added before paths ending in a node further to the right.
 * @param paths vector of vectors that contains path of nodes
 */
template <typename T>
void BinaryTree<T>::printPaths(vector<vector<T> > &paths) const
{
    vector<T>  temp;
    printPaths(root,temp, paths);
}

template <typename T>
void BinaryTree<T>::printPaths(const Node * subRoot,vector<T> temp, vector<vector<T> > &paths)const
{
  //base case
  if (subRoot == NULL)
    return;
  //recursively add to the pathstemp.push_back(subRoot->elem);
  temp.push_back(subRoot->elem);
  if (subRoot->left==NULL && subRoot->right == NULL)
  {
    paths.push_back(temp);
  }
  printPaths(subRoot->left,temp,paths);
  printPaths(subRoot->right,temp,paths);

  temp.pop_back();
}

/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{

    return sumDistances(root,0);
}
template <typename T>
int BinaryTree<T>::sumDistances(Node* subRoot, unsigned result) const
{
  if(subRoot==NULL)
    {return 0;}

  return result+sumDistances(subRoot->left,result+1)+sumDistances(subRoot->right,result+1);
}
