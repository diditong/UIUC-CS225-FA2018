#include <vector>
#include <string>
#include "Hash.h"
#include <algorithm>
using namespace std;

int hashFunction(string s, int M) {
   // Your Code Here
   //hash function to sum up the ASCII characters of the letters of the string
   int sum=0;
   for (int i=0;i<s.length();i++){
     sum+=(int)s[i];
   }
   return sum%M;
 }

int countCollisions (int M, vector<string> inputs) {
	int collisions = 0;
  vector<int> output;
  for(int i=0;i<inputs.size();i++){
    output.push_back(hashFunction(inputs[i],M));
  }
  sort (output.begin(), output.end());
  for(int i = 0 ; i < output.size()-1;i++){
    if(output[i]==output[i+1]){
     collisions++;
     output.erase(output.begin()+i);
     i--;

  }
  }
	return collisions;
}
