#include<string>
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
namespace potd{
class student{

public:
 string get_name();
 int get_grade();
 void set_name(string);
 void set_grade(int);
 student();

 private:
   string name_;
   int grade_;

};

}






#endif
