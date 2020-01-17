/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include <algorithm>
#include <cmath>
template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node * temp = t->right;
    t->right = temp->left;
    t->height = getHeight(t);
    temp->left = t;
    temp->height = getHeight(temp);
    t = temp;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node * temp = t->left;
    t->left = temp->right;
    t->height = getHeight(t);
    temp->right = t;
    temp->height = getHeight(temp);
    t = temp;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
int AVLTree<K, V>::getHeight(Node* subRoot)
{
  if (subRoot == NULL)
    return -1;
  return 1+fmax(getHeight(subRoot->left),getHeight(subRoot->right));
}

template <class K, class V>
int AVLTree<K, V>::getB(Node* node)
{
  if(node == NULL)
    return 0;
  return heightOrNeg1(node->right) - heightOrNeg1(node->left);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if (subtree == NULL)
      return;

    if (getB(subtree) == -2)
    {
      if (getB(subtree->left) == -1)
      {
        rotateRight(subtree);
      }
      else if (getB(subtree->left) == 1)
      {
        rotateLeftRight(subtree);
      }
    }
    if (getB(subtree) == 2)
    {
      if (getB(subtree->right) == 1)
      {
        rotateLeft(subtree);
      }
      else if (getB(subtree->right) == -1)
      {
        rotateRightLeft(subtree);
      }
    }
    subtree->height = getHeight(subtree);
}


template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if (subtree == NULL)
    {
      subtree = new Node(key,value);
    }
    else if (key < subtree->key)
    {
      insert(subtree->left, key, value);
    }
    else
    {
      insert(subtree->right, key, value);
    }
  rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right, key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree = NULL;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here

            //find IOP
            Node * temp = subtree->left;
            while (temp->right != NULL)
            {
              temp = temp->right;
            }

            swap(temp,subtree);
            remove(subtree->left,key);

        } else {
            /* one-child remove */
            // your code here
            if (subtree->left != NULL && subtree->right == NULL)
            {
              Node * temp = subtree->left;
              delete subtree;
              subtree = temp;
            }
            else
            {
              Node * temp = subtree->right;
              delete subtree;
              subtree = temp;
            }
        }
    }
    rebalance(subtree);
}
