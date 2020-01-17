#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;


MyColorPicker::MyColorPicker(double in_hue): hue1(0), hue2(180), increment_hue(in_hue)
{
  /*nohting*/
}

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y)
{
  /* @todo [Part 3] */
  HSLAPixel pixel1(hue1, 1, 0.5);
  HSLAPixel pixel2(hue2, 1, 0.5, 0.8);

  hue1 += increment_hue;
  hue2 += 2*increment_hue;


  if (hue1 >= 360) { hue1 -= 360; }
  if (hue2 >= 360) { hue2 -= 360; }

  if (x % 10 < 5 || y % 20 < 5)
  {
    return pixel1;
  }
  else
    return pixel2;
}
