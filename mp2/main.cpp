#include "Image.h"
#include "StickerSheet.h"

int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  Image base, output, st1, st2, st3, st4;
  base.readFromFile("siebel.png");
  st1.readFromFile("uiucCS.png");
  st2.readFromFile("i.png");
  st3.readFromFile("illini.png");
  st4.readFromFile("0e0w.png");


  st2.scale(0.3);
  st3.scale(0.3);
  st4.scale(0.18);

  StickerSheet sticker(base, 4);
  sticker.addSticker(st1, 0, 0);
  sticker.addSticker(st2,950,580);
  sticker.addSticker(st3,890,520);
  sticker.addSticker(st4,590,490);

  base = sticker.render();
  base.writeToFile("myImage.png");


  return 0;
}
