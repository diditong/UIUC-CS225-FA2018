/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
  if (first[curDim] < second[curDim])
    return true;
  else if (first[curDim] > second[curDim])
    return false;
  else
     return first < second;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
  double dis_curr = 0, dis_pot = 0;
  for (int i = 0; i < Dim; i++)
  {
    dis_curr += (target[i]-currentBest[i])*(target[i]-currentBest[i]);
    dis_pot += (target[i]-potential[i])*(target[i]-potential[i]);
  }

  if (dis_curr < dis_pot)
    return false;
  else if (dis_curr > dis_pot)
    return true;
  else
    return potential < currentBest;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    // Check if there was no new Points.
    if (newPoints.empty()) {
        root = nullptr;
        size = 0;
        return;
    }
    // Make a copy of newPoints to allow partition to maipulate.
    vector<Point<Dim>> tmp = newPoints;
    // Start from the root with demention = 0.
    constructKDTree(tmp, 0, tmp.size() - 1, 0, root);
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree& other) {
    _copy(root, other->root);
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree& rhs) {
    _delete(root);
    _copy(rhs->root);
    return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
    _delete(root);
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    Point<Dim> tmp = query;
    Point<Dim> nearestNeighbor = root->point;
    fnn(root, tmp, nearestNeighbor, 0);
    return nearestNeighbor;
}

// helper function for findNearestNeighbor
template <int Dim>
void KDTree<Dim>::fnn(KDTreeNode * node, Point<Dim> & query,
                         Point<Dim> & curBest, int curDim) const
{
    // Base Case
    if (!node) return;
    // If query's dimention is less than current Point's, go left. Otherwise, go right.
    KDTreeNode * targetChild = smallerDimVal(query, node->point, curDim) ? node->left : node->right;
    int nextDim = (curDim + 1) % Dim;
    fnn(targetChild, query, curBest, nextDim);
    // If current node is closer, replace curBest with the current Point.
    if (shouldReplace(query, curBest, node->point))
        curBest = node->point;
    // Current best distance squared value.
    double distCurBest = 0;
    for (int i = 0; i < Dim; i++)
        distCurBest += (curBest[i] - query[i]) * (curBest[i] - query[i]);
    // If the differnce of current dimention is less than currnet best, check the other children.
    if ((node->point[curDim] - query[curDim]) * (node->point[curDim] - query[curDim]) <= distCurBest) {
        if (targetChild == node->left)
            fnn(node->right, query, curBest, nextDim);
        else
            fnn(node->left, query, curBest, nextDim);
    }
}

template <int Dim>
void KDTree<Dim>::constructKDTree(vector<Point<Dim>> & newPoints,
                                  int left, int right, int curDim, KDTreeNode *& subroot)
{
    // Base Case
    if (left > right) return;
    size_t median = (left + right) / 2;
    // Get the median Point using QuickSelect
    Point<Dim> midPoint = quickSelectMedian(newPoints, left, right, median, curDim);
    subroot = new KDTreeNode(midPoint);
    int nextDim = (curDim + 1) % Dim;
    // Construct left child
    constructKDTree(newPoints, left, median - 1, nextDim, subroot->left);
    // Construct right child
    constructKDTree(newPoints, median + 1, right, nextDim, subroot->right);
}

template <int Dim>
Point<Dim> KDTree<Dim>::quickSelectMedian(vector<Point<Dim>> & points,
                                          int left, int right, size_t k, int curDim)
{
    if (left == right) return points[left];
    size_t pivot = (left + right) / 2;
    pivot = partition(points, left, right, pivot, curDim);
    if (k == pivot)
        return points[k];
    else if (k < pivot)
        return quickSelectMedian(points, left, pivot - 1, k, curDim);
    else
        return quickSelectMedian(points, pivot + 1, right, k, curDim);
}

template <int Dim>
size_t KDTree<Dim>::partition(vector<Point<Dim>> & points,
                              int left, int right, size_t pivot, int curDim)
{
    Point<Dim> p = points[pivot];
    swap(points[pivot], points[right]);
    size_t idx = left;
    for (int i = left; i < right; i++)
        if (smallerDimVal(points[i], p, curDim)) {
            swap(points[idx], points[i]);
            idx++;
        }
    swap(points[right], points[idx]);
    return idx;
}

template <int Dim>
void KDTree<Dim>::_copy(KDTreeNode *& node, KDTreeNode *& otherNode)
{
    // Base Case
    if (!otherNode) return;
    // Copy the node.
    node = new KDTreeNode(otherNode->point);
    // Copy the left child.
    _copy(root->left, otherNode->left);
    // Copy the right child.
    _copy(root->right, otherNode->right);
}

template <int Dim>
void KDTree<Dim>::_delete(KDTreeNode * node)
{
    // Base Case
    if (!node) return;
    // Delete the left child.
    _delete(node->left);
    // Delete the right child.
    _delete(node->right);
    // Delete the node.
    delete node;
}
