#include "intersperse.h"
using namespace std;
#include <iostream>
#include <algorithm>
std::vector<int> zigZag(std::vector<int> v1, std::vector<int> v2){
      sort (v1.begin(), v1.end());
      sort (v2.begin(), v2.end());
      vector<int> result;
      int i = v1.size()-1;
      int j = v2.size()-1;
      while(i >= 0 && j >= 0)
      {
         result.push_back(v1[i]);
         result.push_back(v2[j]);
         i--;
         j--;
      }
      if(i==-1)
     {
       while(j>=0){
        result.push_back(v2[j]);
        j--;
     }
     }
     if(j==-1)
    {
      while(i>=0){
       result.push_back(v1[i]);
       i--;
    }
    }

return result;

}
