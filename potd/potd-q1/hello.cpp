#include "hello.h"
#include <iostream>
using namespace std;
#include <string>

string hello(){
int age =19;
string name ="Haowei Liu";
string ans=  "Hello world! My name is " + name  + " and I am " + to_string(age) + " years old.";
return ans;
}
