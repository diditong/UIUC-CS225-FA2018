#include<iostream>

using namespace std;

class Sphere{
public :
Sphere();
Sphere(double r);
double getVolume();
double getRadius();
private:
  double r_;

};

Sphere::Sphere(double r){
  r_=r;
  }

double Sphere::getRadius(){
return r_;

}

double Sphere::getVolume(){

  return (4*r_*r_*r_*3.14159)/3.0;
}

Sphere *CreateUnitSphere(){

  Sphere s(1);
  return &s;
}

int main (){
Sphere *s = CreateUnitSphere();
cout<<s->getRadius()<<endl;
cout<<s->getVolume()<<endl;
return 0;

}
