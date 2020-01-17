#include "potd.h"
string getFortune(const string &s){
  if (s.length()%5 == 0) {
    return "you thirsty";
  }
  if (s.length()%5 == 1) {
    return "please grab a sprite";
  }
  if (s.length()%5 == 2) {
    return "my cribs lurkin";
  }
  if (s.length()%5 == 3) {
    return "don't die tonight";
  }
  if (s.length()%5 == 4) {
    return "I just wanna dance with you baby";
  }
}
