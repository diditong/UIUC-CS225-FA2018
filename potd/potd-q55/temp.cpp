#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
int par[2005];
int _rank[2005];

void init(int n)
{
  //cout<<"seg fault1"<<endl;
    for(int i=0;i < n;i++){
    par[i] = i;
    _rank[i] = 0;
  }
}
int find(int x) {

    if(par[x]!=x) par[x]=find(par[x]);
   return par[x];

}

void unite(int x,int y) {

    int xx=find(x);
    int yy=find(y);
    if(xx != yy) par[xx] = yy;
}

// returns true if a counterexample is found
bool bugLife(int numBugs, vector<int> &b1, vector<int> &b2) {

    init(numBugs);
    bool flag = false;
    //cout<<"numBugs"<<numBugs<<endl;
    for(int i = 0; i < b1.size(); i++) {
    int x = b1[i];
    int y = b2[i];
    if(!flag){
      int xx=find(x);
      int yy=find(y);
    if(xx == yy)
      flag = true;

    if(_rank[x]) unite(_rank[x], y);
    else _rank[x] = y;
    if(_rank[y]) unite(_rank[y], x);
    else _rank[y] = x;
  }
  }
    return flag;

}
