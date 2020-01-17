
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.

  PNG new_png;

  new_png.readFromFile("love.png");

  FloodFilledImage FFimage(new_png);
  BFS bfs1(new_png, Point(0, 0), 0.05);
  BFS bfs2(new_png, Point(200, 100), 0.05);
  MyColorPicker myCP(0.1);
  RainbowColorPicker rainbowCP(0.05);
  HSLAPixel color;
  color.h = 180;
  color.s = 0.5;
  color.l = 0.5;
  color.a = 1;
  SolidColorPicker solidCP(color);

  FFimage.addFloodFill( bfs1, myCP);
  FFimage.addFloodFill( bfs2, rainbowCP);
  FFimage.addFloodFill( bfs2, solidCP);
  Animation animation = FFimage.animate(1000);

  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");



  return 0;
}
