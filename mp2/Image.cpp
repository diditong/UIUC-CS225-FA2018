#include "Image.h"

//Lighten an Image by increasing the luminance of every pixel by 0.1.
void Image::lighten()
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x, y);
      if (pixel.l <= 0.9)
      {
        pixel.l += 0.1;
      }
      else
        pixel.l=1.0;
    }
  }
}

//Lighten an Image by increasing the luminance of every pixel by amount.
void 	Image::lighten (double amount)
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x, y);
      if (pixel.l <= (1.0-amount))
      {
        pixel.l += amount;
      }
      else
        pixel.l=1.0;
    }
  }
}

//Darken an Image by decreasing the luminance of every pixel by 0.1.
void 	Image::darken ()
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x, y);
      if (pixel.l >= 0.1)
      {
        pixel.l -= 0.1;
      }
      else
        pixel.l=0.0;
    }
  }
}
//Darkens an Image by decreasing the luminance of every pixel by amount.
void 	Image::darken (double amount)
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x, y);
      if (pixel.l >= (amount))
      {
        pixel.l -= amount;
      }
      else
        pixel.l=0.0;
    }
  }
}
//Saturates an Image by increasing the saturation of every pixel by 0.1.
void 	Image::saturate ()
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x, y);
      if (pixel.s <= 0.9)
      {
        pixel.s += 0.1;
      }
      else
        pixel.s=1.0;
    }
  }
}

//Saturates an Image by increasing the saturation of every pixel by amount.
void 	Image::saturate (double amount)
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x, y);
      if (pixel.s <= (1.0-amount))
      {
        pixel.s += amount;
      }
      else
        pixel.s=1.0;
    }
  }
}
//Desaturates an Image by decreasing the saturation of every pixel by 0.1.
void 	Image::desaturate ()
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x, y);
      if (pixel.s >= 0.1)
      {
        pixel.s -= 0.1;
      }
      else
        pixel.s=0.0;
    }
  }
}
//Desaturates an Image by decreasing the saturation of every pixel by amount.
void 	Image::desaturate (double amount)
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x, y);
      if (pixel.s >= amount)
      {
        pixel.s -= amount;
      }
      else
        pixel.s=0.0;
    }
  }
}

//Turns the image grayscale.
void 	Image::grayscale ()
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x, y);
      pixel.s = 0;
    }
  }
}
//Rotates the color wheel by degrees.
void 	Image::rotateColor (double degrees)
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x, y);
      double temp = pixel.h+degrees;
      if (temp>=360)
      {
        temp-=360;
      }
      else if (temp<=0)
        temp+=360;
      pixel.h = temp;
    }
  }
}
//Illinify the image.
void 	Image::illinify ()
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x, y);
      pixel.h < 287 && pixel.h > 113.5 ? pixel.h = 216 : pixel.h = 11;
    }
  }
}

//Scale the Image by a given factor.
void 	Image::scale (double factor)
{
  PNG * temp = new PNG(*this);

  unsigned tempwidth = (unsigned) width()*factor;
  unsigned tempheight = (unsigned) height()*factor;
  resize(tempwidth,tempheight);
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & curPixel = temp->getPixel(x/factor,y/factor);
      getPixel(x, y).h=curPixel.h;
      getPixel(x, y).s=curPixel.s;
      getPixel(x, y).l=curPixel.l;
      getPixel(x, y).a=curPixel.a;
    }
  }

  delete temp;
  temp = NULL;
}
//Scales the image to fit within the size (w x h).
void 	Image::scale (unsigned w, unsigned h)
{
  double factorw= w/width();
  double factorh= h/height();
  factorw = factorh;
  scale(factorw);
}
