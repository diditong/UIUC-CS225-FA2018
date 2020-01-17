/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#ifndef STICKERSHEET_H_
#define STICKERSHEET_H_
#include "cs225/PNG.h"
#include "Image.h"
#include <iostream>
using namespace cs225;

class StickerSheet
{
private:
  unsigned stickerMax_;
  unsigned stickerCount_;
  Image base_;
  Image ** stickers_;
  unsigned ** x_;
  unsigned ** y_;
  //Helper function
  void _copy(const StickerSheet &other);
  void _destroy();

public:
  StickerSheet (const Image &picture, unsigned max);
  //Initializes this StickerSheet with a base picture and the ability to hold a
  //max number of stickers (Images) with indices 0 through max - 1. More...

  ~StickerSheet ();
  //Frees all space that was dynamically allocated by this StickerSheet. More...

  StickerSheet (const StickerSheet &other);
  //The copy constructor makes this StickerSheet an independent copy of the source. More...

  const StickerSheet & 	operator= (const StickerSheet &other);
  //The assignment operator for the StickerSheet class. More...

  void 	changeMaxStickers (unsigned max);
  //Modifies the maximum number of stickers that can be stored on this StickerSheet
  //without changing existing stickers' indices. More...

  int 	addSticker (Image &sticker, unsigned x, unsigned y);
  //Adds a sticker to the StickerSheet, so that the top-left of the sticker's Image
  //is at (x, y) on the StickerSheet. More...

  bool 	translate (unsigned index, unsigned x, unsigned y);
  //Changes the x and y coordinates of the Image in the specified layer. More...

  void 	removeSticker (unsigned index);
  //Removes the sticker at the given zero-based layer index. More...

  Image * 	getSticker (unsigned index) const;
  //Returns a pointer to the sticker at the specified index, not a copy of it. More...

  Image 	render () const;
  //Renders the whole StickerSheet on one Image and returns that Image. More...
};

#endif
