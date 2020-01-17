#include "potd.h"
#include <iostream>
#include<string>

using namespace std;

string stringList(Node *head) {
  int i=0;
  string result;
   if(head==NULL)
   return "Empty list";
   else
   {
     while(head!=NULL)
     {
       result+= "Node "+to_string(i)+": "+to_string(head->data_) ;
       if(head->next_!=NULL)
       result+=" -> ";
       i++;
       head=head->next_;
     }

   }
   return result;
}
