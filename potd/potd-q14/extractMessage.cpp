/**
 * @file
 * Contains the implementation of the extractMessage function.
 */

#include <iostream> // might be useful for debugging
#include <assert.h>
#include "extractMessage.h"

using namespace std;


int pow(int a ){
  if (a==0)
  return 1;
  int result=1;
for(int i =0; i<a;i++){
result*=2;

}
return result;
}

char *extractMessage(const char *message_in, int length) {
   // length must be a multiple of 8
   assert((length % 8) == 0);

   // allocate an array for the output
   char *message_out = new char[length];

	// TODO: write your code here
    int *messageInValue = new int[length];
    int *messageOutValue = new int [length];
    int numberOfBlock=length/8;
    for(int i =0; i< length;i++){
      messageInValue[i]=(int)message_in[i];
}
    for(int j=0;j<numberOfBlock;j++){ //block number
       for(int k=0; k<8;k++){ //bit position
         int result=0;
         for(int l=0;l<8;l++){// number position
          if((messageInValue[l+j*8]&1)!=0)
          result+=pow(l);
          messageInValue[l+j*8]=messageInValue[l+j*8]>>1;
        }
          messageOutValue[k+j*8]=result;
       }


    }

    for(int s=0;s<length;s++){
        message_out[s]=(char)messageOutValue[s];

    }



	return message_out;
}
