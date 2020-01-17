#include <string>
#include "pet.h"

using namespace std;

// Put your constructor code here!
Pet::Pet(){
name="Rover";
birth_year=2017;
type="dog";
owner_name="Cinda";
}
Pet::Pet(string newName,int newBirth_year,string newType,string newOwnwe_name){
  name=newName;
  birth_year=newBirth_year;
  type=newType;
  owner_name=newOwnwe_name;

}
void Pet::setName(string newName) {
  name = newName;
}

void Pet::setBY(int newBY) {
  birth_year = newBY;
}

void Pet::setType(string newType) {
  type = newType;
}

void Pet::setOwnerName(string newName) {
  owner_name = newName;
}

string Pet::getName() {
  return name;
}

int Pet::getBY() {
  return birth_year;
}

string Pet::getType() {
  return type;
}

string Pet::getOwnerName() {
  return owner_name;
}
