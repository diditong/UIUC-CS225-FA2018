#include "Friend.h"
using namespace std;
#include <queue>
#include <iostream>
#include <algorithm>

int find(unsigned long x, std::vector<int>& parents) {
   // your code
   int si = parents.size()+x;
 return si;
}


int findCircleNum(std::vector<std::vector<int>>& M) {
  // for(unsigned long i = 0; i < M.size(); i++){
  //   for(unsigned long j = 0; j < M[i].size(); j++){
  //     cout<<M[i][j];
  //   }
  //   cout<<endl;
  // }
    // your code
    vector<int> result;

    result.assign (M.size(),-1);
    int visited[M.size()];

    visited[0]=1;
    for(unsigned long i = 0; i < M.size(); i++){
      for(unsigned long j = 0; j < M[i].size(); j++){
        if(M[i][j]==1 && i!=j  ){
         if(result[i]==-1){
         result[j]=i;
         visited[j]=1;
       }
         else {
         result[j]=result[i];
         visited[j]=1;
       }
     }
    }

}
    int count=0;
    for(unsigned long i = 0 ; i < result.size() ; i++){
      if(result[i]==-1||result[i]==i)
      count++;
    }
    return count;
}
