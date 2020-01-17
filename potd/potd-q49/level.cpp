#include "MinHeap.h"

vector<int> lastLevel(MinHeap & heap)
{

  vector<int> lastLv;
   unsigned i = 1;
   while(i*2 <= heap.elements.size()) i*=2;
   for(;i < heap.elements.size();i++) lastLv.push_back(heap.elements[i]);
   return lastLv;
}
