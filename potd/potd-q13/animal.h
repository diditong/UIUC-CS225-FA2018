#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
using namespace std;
class Animal{
private:
  string type_;

public:
  string food_;
  string getType();
  void setType(string );
  string getFood();
  void setFood(string);
  virtual void print();
  Animal();
  Animal(string, string);










};





#endif
