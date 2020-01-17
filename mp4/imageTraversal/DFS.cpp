#include <iterator>
#include <cmath>
#include <list>
#include <stack>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"

/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance)
{
  /** @todo [Part 1] */
  tolerance_ = tolerance;
  start_ = start;
  png_ = png;

  //Create a 2d board to mark if a point has been added
  board = new bool* [png.width()];
  for (unsigned i = 0; i < png.width(); i++) {
    board[i] = new bool[png.height()];
  }
  for (unsigned i = 0; i < png.width(); i++) {
    for (unsigned j = 0; j < png.height(); j++) {
      board[i][j] = false;
    }
  }

  Pstack.push(start_);
  board[start_.x][start_.y] = true;
}
DFS::~DFS()
{
  for (unsigned i = 0; i < png_.width(); i++)
  {
    delete [] board[i];
  }
  delete [] board;
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  ImageTraversal *it = new DFS(png_, start_, tolerance_);
  return ImageTraversal::Iterator(it, start_);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  //Point p = Point (-1,-1);
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point)
{
  /** @todo [Part 1] */
  if(point.x+1 < png_.width() && board[point.x+1][point.y]==false)
  {
    Point right(point.x+1, point.y);
    if(getCalculateDelta(png_.getPixel(start_.x, start_.y), png_.getPixel(right.x, right.y)) < tolerance_)
      {
        Pstack.push(right);
        board[right.x][right.y] = true;
      }
  }
  if(point.y+1 < png_.height() && board[point.x][point.y+1]==false)
  {
    Point below(point.x, point.y+1);
    if(getCalculateDelta(png_.getPixel(start_.x, start_.y), png_.getPixel(below.x, below.y)) < tolerance_)
      {
        Pstack.push(below);
        board[below.x][below.y] = true;
      }
  }
  if (point.x >= 1 && board[point.x-1][point.y]==false)
  {
    Point left(point.x-1, point.y);
    if(getCalculateDelta(png_.getPixel(start_.x, start_.y), png_.getPixel(left.x, left.y)) < tolerance_)
      {
        Pstack.push(left);
        board[left.x][left.y] = true;
      }
  }
  if (point.y >= 1 && board[point.x][point.y-1]==false)
  {
    Point up(point.x, point.y-1);
    if(getCalculateDelta(png_.getPixel(start_.x, start_.y), png_.getPixel(up.x, up.y)) < tolerance_)
      {
        Pstack.push(up);
        board[up.x][up.y] = true;
      }
  }
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop()
{
  /** @todo [Part 1] */
  Point temp = Pstack.top();
  Pstack.pop();
  return temp;
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  if (Pstack.empty()==true)
  {
    return Point (-1,-1);
  }
  return Pstack.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return Pstack.empty();
}
