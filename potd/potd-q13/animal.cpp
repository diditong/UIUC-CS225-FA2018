#include <iostream>
#include "animal.h"
#include <string>
using namespace std;

string Animal::getType(){

return type_;
}
void Animal::setType(string newType){
type_=newType;

}
string Animal::getFood(){
return food_;

}
void Animal::setFood(string newFood){
food_=newFood;

}
void Animal::print(){
cout<<"I am a "<<this->type_<<"."<<endl;

}
Animal::Animal(){
type_="cat";
food_="fish";


}
Animal::Animal(string a , string b){

type_=a;
food_=b;
}
