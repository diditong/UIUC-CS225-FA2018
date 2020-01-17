#ifndef MyColorPicker_H
#define MyColorPicker_H

#include "ColorPicker.h"
#include "../cs225/HSLAPixel.h"
#include "../Point.h"

using namespace cs225;

/**
 * A color picker class using your own color picking algorithm
 */
class MyColorPicker : public ColorPicker {
public:
  MyColorPicker(double in_hue);
  HSLAPixel getColor(unsigned x, unsigned y);

private:
  double hue1, hue2;
  double increment_hue;
};

#endif
