#ifndef BAR_H
#define BAR_H
#include "foo.h"
using namespace std;

namespace potd{

  class bar{

private:
  foo *f_;
  void copy_(const bar&);
  void destroy_();

public:
bar(string );
bar(const bar&);
~bar();
bar& operator=(const bar&);
string get_name();



};

}
#endif
