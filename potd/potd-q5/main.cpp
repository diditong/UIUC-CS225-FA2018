#include<iostream>
#include"q5.h"
using namespace std;

int main(){

food *food1= new food();
food &food=food1;
cout<<"You have "<<food1->get_quantity()<<" "<<food1->get_name() <<endl;
increase_quantity(food1);
cout<<"You have "<<food1->get_quantity()<<" "<<food1->get_name()<<endl;

}
