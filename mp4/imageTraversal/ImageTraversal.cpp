#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}
double ImageTraversal::getCalculateDelta(const HSLAPixel & p1, const HSLAPixel & p2)
{
  return calculateDelta(p1,p2);
}


/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator()
{
  /** @todo [Part 1] */
  curr_ = Point (-1,-1);
}
ImageTraversal::Iterator::Iterator(ImageTraversal * trav, Point curr)
:traversal(trav), curr_(curr)
{
  //curr_ = traversal.peek();
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  if (!traversal->empty()) {
    curr_ = traversal->pop();
    traversal->add(curr_);
    curr_ = traversal->peek();
  }
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return curr_;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  if ( (curr_.x != other.curr_.x)  && (curr_.y != other.curr_.y) )
  {
    return true;
  }
  return false;
}
