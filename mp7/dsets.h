#ifndef DSETS_H
#define DSETS_H

#include <vector>
using namespace std;

class DisjointSets
{
private:
  vector<int> arr_;

public:
  //Creates n unconnected root nodes at the end of the vector.
  void addelements(int num);

  //This function should compress paths and works as described in lecture.
  int find(int elem);

  //This function should be implemented as union-by-size.
  void setunion(int a, int b);

  int size(int elem);
};

#endif
