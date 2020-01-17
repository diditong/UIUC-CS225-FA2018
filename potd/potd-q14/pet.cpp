#include<iostream>

#include"pet.h"

using namespace std;

string Pet::getFood(){
return food_;

}
void Pet::setFood(string f){
  food_=f;
}
string Pet::getName(){
  return name_;
}
void Pet::setName(string n){
  name_=n;
}
string Pet::getOwnerName(){
  return owner_name_;
}
void Pet::setOwnerName(string o){
  owner_name_=o;
}
string Pet::print(){
  string a ="My name is "+name_;
  return a;
}
Pet::Pet():Animal("cat","fish"){

  name_ = "Fluffy"; owner_name_= "Cinda" ;
}
Pet::Pet(string y, string f, string n,string o):Animal(y,f){

  name_=n;

  owner_name_=o;
}
