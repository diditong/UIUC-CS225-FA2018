#include <vector>
#include "dsets.h"

//Creates n unconnected root nodes at the end of the vector.
void DisjointSets::addelements(int num)
{
  //arr_.resize(num, -1);
  if (arr_.empty())
  {
    arr_.assign(num, -1);
    return;
  }
  for (int i = 0; i < num; i++)
  {
    arr_.push_back(-1);
  }
}

//This function should compress paths and works as described in lecture.
int DisjointSets::find(int elem)
{
  if (arr_[elem] < 0)
    return elem;
  else
    return find(arr_[elem]);
}

//This function should be implemented as union-by-size.
void DisjointSets::setunion	(int a, int b)
{
  int root1 = find(a);
  int root2 = find(b);
  int newSize = arr_[root1] + arr_[root2];

  if (arr_[root1] <= arr_[root2])
  {
    arr_[root2] = root1;
    arr_[root1] = newSize;
  }
  else
  {
    arr_[root1] = root2;
    arr_[root2] = newSize;
  }
}

int DisjointSets::size(int elem)
{
    return -1*arr_[find(elem)];
}
