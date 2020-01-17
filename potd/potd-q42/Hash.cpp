#include "Hash.h"
#include <string>

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	for(unsigned i = 0 ; i < str.length();i++){
		b_hash *= 33 ;
		b_hash += str[i];
	}
	return b_hash % M;
}

std::string reverse(std::string str)
{
    std::string output = "";

		for(int  i = str.length()-1 ; i >=0 ;i--){
			output+=str[i];

		}

	return output;
}
