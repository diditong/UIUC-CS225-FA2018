#include<iostream>
#include"thing.h"
#include<string>
using namespace std;
namespace potd{
Thing::Thing(int size){

  properties_=new string[size];
  values_ = new string[size];
  props_ct_=0;
  props_max_=size;
}
Thing::Thing(const Thing &orig){
this->props_ct_=orig.props_ct_;
this->props_max_=orig.props_max_;
this->properties_=new string[orig.props_max_];
for(int i=0; i <orig.props_ct_;i++ )
this->properties_[i]=orig.properties_[i];

this->values_=new string[orig.props_max_];
for(int i=0; i <orig.props_ct_;i++)
this->values_[i]=orig.values_[i];
}

void Thing::_copy(const Thing &orig){
  this->props_ct_=orig.props_ct_;
  this->props_max_=orig.props_max_;
  this->properties_=new string[orig.props_max_];
  for(int i=0; i <orig.props_ct_;i++ )
  this->properties_[i]=orig.properties_[i];

  this->values_=new string[orig.props_max_];
  for(int i=0; i <orig.props_ct_;i++)
  this->values_[i]=orig.values_[i];

}

void Thing::_destroy(){
delete []properties_;
delete []values_;
}

Thing& Thing::operator=(const Thing& other){
_destroy();
  this->props_ct_=other.props_ct_;
  this->props_max_=other.props_max_;
  this->properties_=new string[other.props_max_];
  for(int i=0; i <other.props_ct_;i++ )
  this->properties_[i]=other.properties_[i];

  this->values_=new string[other.props_max_];
  for(int i=0; i <other.props_ct_;i++)
  this->values_[i]=other.values_[i];
return *this;
}

Thing::~Thing(){

this->_destroy();

}

int Thing::set_property(string name, string value){
for(int i=0; i <this->props_ct_;i++){
 if(this->properties_[i]==name){
this->values_[i]=value;
return i;
}
}//find if something exist
if (props_ct_>=props_max_)
return -1;


this->properties_[props_ct_]=name;
this->values_[props_ct_]=value;

return props_ct_++;
//insert if not full


}

string Thing::get_property(string name){
for(int i=0;i<props_ct_;i++ ){
  if(this->properties_[i].compare(name)==0)
  return this->values_[i];
}
return "";

}
}
