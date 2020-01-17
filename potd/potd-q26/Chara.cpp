#include "Chara.h"

string Chara::getStatus() const{
  if(q.empty())
  return "Empty";
  if(q.size()<=3)
  return "Light";
  if(q.size()<=6&&q.size()>=4)
  return "Moderate";
  if(q.size()>6)
  return "Heavy";
}
void Chara::addToQueue(string name){
  q.push(name);

}
string Chara::popFromQueue(){
    string temp= q.front();
    q.pop();
    return temp;
}
