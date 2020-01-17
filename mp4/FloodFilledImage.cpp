#include "cs225/PNG.h"
#include <list>
#include <iostream>
#include <iterator>

#include "colorPicker/ColorPicker.h"
#include "imageTraversal/ImageTraversal.h"

#include "Point.h"
#include "Animation.h"
#include "FloodFilledImage.h"

using namespace cs225;

/**
 * Constructs a new instance of a FloodFilledImage with a image `png`.
 *
 * @param png The starting image of a FloodFilledImage
 */
FloodFilledImage::FloodFilledImage(const PNG & png) {
  /** @todo [Part 2] */
  png_ = png;
}

/**
 * Adds a flood fill operation to the FloodFillImage.  This function must store the operation,
 * which will be used by `animate`.
 *
 * @param traversal ImageTraversal used for this FloodFill operation.
 * @param colorPicker ColorPicker used for this FloodFill operation.
 */
void FloodFilledImage::addFloodFill(ImageTraversal & traversal, ColorPicker & colorPicker) {
  /** @todo [Part 2] */
  traversal_.push(&traversal);
  colorPicker_.push(&colorPicker);
}

/**
 * Creates an Animation of frames from the FloodFill operations added to this object.
 *
 * Each FloodFill operation added by `addFloodFill` is executed based on the order
 * the operation was added.  This is done by:
 * 1. Visiting pixels within the image based on the order provided by the ImageTraversal iterator and
 * 2. Updating each pixel to a new color based on the ColorPicker
 *
 * While applying the FloodFill to the image, an Animation is created by saving the image
 * after every `frameInterval` pixels are filled.  To ensure a smooth Animation, the first
 * frame is always the starting image and the final frame is always the finished image.
 *
 * (For example, if `frameInterval` is `4` the frames are:
 *   - The initial frame
 *   - Then after the 4th pixel has been filled
 *   - Then after the 8th pixel has been filled
 *   - ...
 *   - The final frame, after all pixels have been filed)
 */
Animation FloodFilledImage::animate(unsigned frameInterval)  {
  Animation animation;
  /** @todo [Part 2] */
  int count = 1;
  ImageTraversal * trav_temp;
  ColorPicker * CP_temp;

  while(traversal_.empty() == false)
  {
    animation.addFrame(png_);
    trav_temp = traversal_.front();
    CP_temp = colorPicker_.front();

    for (const Point & p : *trav_temp)
    {
      png_.getPixel(p.x, p.y) = CP_temp->getColor(p.x, p.y);
      if(count % frameInterval == 0)
      {
        animation.addFrame(png_);
      }
      count++;
    }

    animation.addFrame(png_);
    traversal_.pop();
    colorPicker_.pop();
  }
  return animation;
}
