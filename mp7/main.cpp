#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "cs225/PNG.h"

using namespace std;



int main()
{
  SquareMaze m;
  m.makeMaze(70, 100);
  std::cout << "MakeMaze complete" << std::endl;

  PNG* creative = m.drawCreativeMaze();
  creative->writeToFile("creative.png");
  delete creative;
  std::cout << "drawCreativeMaze complete" << std::endl;

  return 0;
}
