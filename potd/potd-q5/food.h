#include<string>
using namespace std;

#ifndef FOOD_H
#define FOOD_H


namespace cs225{

class food{
public:
  food();
  string get_name();
  void set_name(string );
  int get_quantity();
  void set_quantity(int );
private:
  int quantity_;
  string name_;
};

}

#endif
