#ifndef PET_H
#define PET_H
#include "animal.h"
using namespace std;
class Pet :public Animal{

public:
string getFood();
void setFood(string);
string getName();
void setName(string);
string getOwnerName();
void setOwnerName(string);
string print();
Pet();
Pet(string, string, string,string);

private:
  string name_;
  string owner_name_;

};


#endif
