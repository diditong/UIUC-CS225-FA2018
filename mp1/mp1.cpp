#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <string>


using namespace cs225;


void rotate(std::string inputFile, std::string outputFile)
{
  // Load in.png
  PNG* original = new PNG();
  original->readFromFile(inputFile);
  unsigned width = original->width();
  unsigned height = original->height();

  // Create out.png
  PNG* output = new PNG(width,height);

  //rotate
  for (unsigned y = 0; y < height; y++)
  {
      for (unsigned x = 0; x < width; x++)
      {
          HSLAPixel * currOutPixel = output->getPixel(x, y);
          // currOutPixel->h = original->getPixel(width-1-x, height-1-y)->h;
          // currOutPixel->s = original->getPixel(width-1-x, height-1-y)->s;
          // currOutPixel->l = original->getPixel(width-1-x, height-1-y)->l;
          // currOutPixel->a = original->getPixel(width-1-x, height-1-y)->a;
          *currOutPixel = *original->getPixel(width-1-x, height-1-y);
      }
  }

  // Save the output file
  output->writeToFile(outputFile);

  // Clean up memory
  delete output;
  delete original;
}

PNG myArt(unsigned int width, unsigned int height)
{
  PNG png(width, height);
//  PNG* output = & png;
  //HSLAPixel *pixel1= new HSLAPixel(-200, saturation, 0.5);
//  HSLAPixel *pixel2= new HSLAPixel(262, 0.3, 0.7);
  //HSLAPixel *pixel3= new HSLAPixel(197, 0.4, 0.6);

  for (unsigned y = 0; y < height; y++)
  {
      for (unsigned x = 0; x < width; x++)
      {

         if ((x+y< width/2)||(x+y>width*1.5))
         {
           png.getPixel(x, y)->h = 60+x%360 ;
           png.getPixel(x, y)->s = 0.001+(0.0006*y);
           png.getPixel(x, y)->l += 0.6;
         }
         else
           png.getPixel(x, y)->l += 0.01+0.001*x;
      }
  }

  //delete pixel1;


  return png;
}
