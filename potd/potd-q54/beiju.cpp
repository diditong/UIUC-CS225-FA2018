#include <iostream>
#include <string>
using namespace std ;

string beiju(string input) {
    string result="";
    bool flag= false;
    string middleText="";
    for(int i = 0 ; i < input.length(); i ++){
      if(input[i]!='[' && input[i] != ']')
       {
         result+=input[i];
       }

     if(input[i]=='['){
         int j=1;
         middleText="";
         while((i+j)<input.length() && input[i+j]!='[' && input[i+j] != ']'){
           middleText+=input[i+j];
           j++;
         }

         result = middleText + result;

        i+=j;
          i--;
     }



}

return result;
}

// string middle(string input){
//   string result="";
//
// }
