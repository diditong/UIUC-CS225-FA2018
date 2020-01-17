#include"student.h"
namespace potd{
string student::get_name(){
 return name_;

}

int student::get_grade(){

return grade_;
}

void student::set_name(string n){
  name_=n;
}

void student::set_grade(int g){
  grade_=g;
}

student::student(){
 name_="Sally";
 grade_=5;

}
}
