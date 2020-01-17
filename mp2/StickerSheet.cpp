#include "StickerSheet.h"


//Constructor & Destructor
StickerSheet::StickerSheet (const Image &picture, unsigned max)
{
  stickerMax_ = max;
  stickerCount_ = 0;
  base_ = picture;
  stickers_ = new Image*[max];
  x_ = new unsigned*[max];
  y_ = new unsigned*[max];
  for (unsigned i = 0; i < max; i++)
  {
    stickers_[i] = NULL;
    x_[i] = NULL;
    y_[i] = NULL;
  }
}

StickerSheet::~StickerSheet ()
{
  _destroy();
}

StickerSheet::StickerSheet (const StickerSheet &other)
{
  _copy(other);
}

//Helper functions
void StickerSheet::_copy(const StickerSheet & other)
{
  stickerMax_ = other.stickerMax_;
  stickerCount_ = other.stickerCount_;
  base_ = other.base_;
  stickers_ = new Image*[stickerMax_];
  x_ = new unsigned*[stickerMax_];
  y_ = new unsigned*[stickerMax_];

  for (unsigned i = 0; i < stickerMax_; i++)
  {
    stickers_[i] = new Image();
    x_[i] = new unsigned();
    y_[i] = new unsigned();
  }
  for (unsigned i = 0; i < stickerMax_; i++)
  {
    if(other.stickers_[i] == NULL) //if stickers_ pts to NULL
    {
      delete stickers_[i];
      stickers_[i] = NULL;
      delete x_[i];
      x_[i] = NULL;
      delete y_[i];
      y_[i] = NULL;
      continue;
    }
    *stickers_[i] = *(other.stickers_[i]);
    *x_[i] = *(other.x_[i]);
    *y_[i] = *(other.y_[i]);
  }
}

void StickerSheet::_destroy()
{
  for (unsigned i = 0; i < stickerMax_; i++)
  {
    if (stickers_[i] != NULL)
    {
      delete stickers_[i];
      stickers_[i] = NULL;
    }
    if (x_[i] != NULL)
    {
      delete x_[i];
      x_[i] = NULL;
    }
    if (y_[i] != NULL)
    {
      delete y_[i];
      y_[i] = NULL;
    }
  }
    if (stickers_ != NULL)
    {
      delete [] stickers_; // need []?
      stickers_ = NULL;
    }
    if (x_ != NULL)
    {
      delete [] x_;
      x_ = NULL;
    }
    if (y_ != NULL)
    {
      delete [] y_;
      y_ = NULL;
    }
}


//Member Functions
const StickerSheet& StickerSheet::operator= (const StickerSheet &other)
{
  _destroy();
  _copy(other);
  return *this;
}



void StickerSheet::changeMaxStickers (unsigned max)
{

  Image ** temp = new Image*[max];
  unsigned ** tempx = new unsigned*[max];
  unsigned ** tempy = new unsigned*[max];
  for (unsigned i = 0; i < max; i++)
  {
    temp[i] = NULL;
    tempx[i] = NULL;
    tempy[i] = NULL;
  }
  if (stickerCount_ < max)
  {
    for (unsigned a = 0; a < stickerCount_; a++)
    {
      temp[a] = stickers_[a];
      tempx[a] = x_[a];
      tempy[a] = y_[a];
    }
  }
  else
  {
    unsigned tempCount = max;
    for(unsigned b = 0; b < max;b++)
    {
      if (stickers_[b]==NULL)
        tempCount--;
      temp[b] = stickers_[b];
      tempx[b] = x_[b];
      tempy[b] = y_[b];
    }
    for (unsigned c = max; c < stickerMax_; c++)
    {
      delete stickers_[c];
      delete x_[c];
      delete y_[c];
    }
    stickerCount_ = tempCount;
  }

  delete stickers_;
  delete x_;
  delete y_;
  stickers_ = temp;
  x_ = tempx;
  y_ = tempy;
  stickerMax_ = max;
}

int StickerSheet::addSticker (Image &sticker, unsigned x, unsigned y)
{
  if (stickerMax_ <= stickerCount_)
  {
    std::cout << "Reached max num of stickers" << '\n';
    return -1;
  }
  if (stickerCount_ == 0)
  {
    stickers_[0] = new Image(sticker);
    x_[0] = new unsigned(x);
    y_[0] = new unsigned(y);
    stickerCount_++;
  }
  else
  {
    for (unsigned i = 0; i < stickerMax_; i++)
    {
      if (stickers_[i] == NULL)
      {
       stickers_[i] = new Image(sticker);
       x_[i] = new unsigned(x);
       y_[i] = new unsigned(y);
       break;
      }
    }
    stickerCount_++;
  }
  return stickerCount_-1;
}

bool StickerSheet::translate (unsigned index, unsigned x, unsigned y)
{
  if (stickers_[index] == NULL || index > stickerCount_-1)
    return false;
    x_[index] = new unsigned(x);
    y_[index] = new unsigned(y);
  return true;
}

void StickerSheet::removeSticker (unsigned index)
{
  delete stickers_[index];//may need to use another method
  delete x_[index];
  delete y_[index];
  stickers_[index] = NULL;
  x_[index] = NULL;
  y_[index] = NULL;
  stickerCount_--;
}

Image *	StickerSheet::getSticker (unsigned index) const
{
  if(index > stickerCount_-1)
    return NULL;
  return stickers_[index];
}

Image StickerSheet::render () const
{
  //Find the size of the generated picture
  unsigned picWidth = base_.width();
  unsigned picHeight = base_.height();
  unsigned tempCount = stickerCount_;
  for (unsigned i = 0; i < stickerMax_; i++)
  {
    if (stickers_[i] == NULL)
    {
      tempCount ++;
      continue;
    }
    if (stickers_[i]->width() + *x_[i] > picWidth)
    {
      picWidth = stickers_[i]->width()+*x_[i];
    }
    if (stickers_[i]->height() + *y_[i] > picHeight)
    {
      picHeight = stickers_[i]->height() + *y_[i];
    }
  }

  //Create the picture
  Image pic = base_;
  pic.resize(picWidth,picHeight);
  unsigned stCount = stickerCount_;
  for (unsigned i = 0; i < stickerMax_; i++)
  {
    if (stickers_[i]==NULL)
    {
      stCount ++;
      continue;
    }
    unsigned stWidth = stickers_[i]->width()+ *x_[i];
    unsigned stHeight = stickers_[i]->height() + *y_[i];
    for (unsigned y =*y_[i] ; y < stHeight; y++)
    {
      for (unsigned x = *x_[i]; x < stWidth; x++)
      {
        if ((stickers_[i]->getPixel(x-*x_[i],y-*y_[i])).a != 0)
        {
          pic.getPixel(x,y) = stickers_[i]->getPixel(x-*x_[i],y-*y_[i]);
        }
      }
    }
  }
  return pic;
}
