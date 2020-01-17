#include <iostream>
#include <string>
using namespace std;

#include "square.h"

Square::Square() {
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}

void Square::setName(string newName) {
  name = newName;
}

Square & Square::operator=(const Square & other){
name=other.name;

*lengthptr=*other.lengthptr;

return *this;
}


Square Square::operator+(const Square & other){
  Square *temp = new Square();

temp->name=this->name+other.name;
*(temp->lengthptr)=this->getLength()+other.getLength();


return *temp;
}




void Square::setLength(double newVal) {
  *lengthptr = newVal;
}

string Square::getName() const {
  return name;
}

double Square::getLength() const {
  return *lengthptr;
}

Square::Square(const Square & other) {
    name = other.getName();
    lengthptr = new double;
    *lengthptr = other.getLength();
}

Square::~Square() {
    delete lengthptr;
}
