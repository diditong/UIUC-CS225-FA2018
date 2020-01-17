// your code here!
#include<iostream>
#include"potd.h"
#include <math.h>
using namespace std;
namespace potd{
int *raise(int *arr){
  int size = 0, temp = 0;
  while (temp != -1)
  {
    temp = arr[size];
    size++;
  }

  int * newArray = new int[size];
  for (int i = 0; i < size-2; i++)
  {
    newArray[i] = pow (arr[i],arr[i+1]);
  }

  newArray[size-2] = arr[size-2];
  newArray[size-1] = -1;

  return &newArray[0];
}
}
