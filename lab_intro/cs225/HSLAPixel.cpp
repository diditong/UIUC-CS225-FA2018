/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#include "HSLAPixel.h"
#include <cmath>
#include <iostream>
using namespace std;

namespace cs225
{
  HSLAPixel::HSLAPixel () //default
    {
      h = 0.0; //Hue value for the new pixel, in degrees [0, 360).
      s = 0.0; //Saturation value for the new pixel, [0, 1].
      l = 1.0; //Luminance value for the new pixel, [0, 1].
      a = 1.0; //Opaque implies that the alpha component of the pixel is 1.0.
    }
  HSLAPixel::HSLAPixel (double hue, double saturation, double luminance)
    {
      h = hue;
      s = saturation;
      l = luminance;
      a = 1.0;
    }
  HSLAPixel::HSLAPixel (double hue, double saturation, double luminance, double alpha)
    {
      h = hue;
      s = saturation;
      l = luminance;
      a = alpha;
  }
}
