#include "Pattern.h"
#include <string>
#include <iostream>
#include <map>
#include <iterator>
using namespace std;
bool wordPattern(std::string pattern, std::string str) {
  map<string, int> stringMap;  //str
  map<char, int> charMap; //pattern
  string temp="";
  int count=0;
  string result1="";
  string result2="";

  for(int i =0; i < str.length();i++){
    if(i==str.length()-1)
     temp+=str[i];
    if(str[i]==' '||i==str.length()-1){
     if(stringMap.find(temp)==stringMap.end()){
     stringMap.insert(pair<string, int>(temp,count));
     count++;
   }
     result2+= to_string(stringMap[temp]);
     temp="";
   }
     else
      temp+=str[i];
  }

  count=0;
  for(int i =0; i < pattern.length();i++){
    if(charMap.find(pattern[i])==charMap.end()){
    charMap.insert(pair<char, int>(pattern[i],count));
    count++;
  }
  result1+= to_string(charMap[pattern[i]]);
  }

cout<<"pattern : "<<result1<<endl;
cout<<"string : "<<result2<<endl;



return result1.compare(result2) == 0;

  }
