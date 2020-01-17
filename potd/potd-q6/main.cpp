#include<iostream>
#include"q6.h"
#include<string>
using namespace potd;
using namespace std;

int main(){

student s1;
cout<<s1.get_name()<<" is in grade "<<s1.get_grade()<<endl;
graduate(s1);
cout<<s1.get_name()<<" is in grade "<<s1.get_grade()<<endl;



  return 0;
}
