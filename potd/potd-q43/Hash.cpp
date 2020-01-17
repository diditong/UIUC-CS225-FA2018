#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Hash.h"
#include <map>
using namespace std;
unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	for (int i = 0; i < (int) str.length(); ++i)
	{
		b_hash = b_hash * 33 + str[i];
	}
	return b_hash % M;
}

float hash_goodness(std::string str, int M)
{
	 map<unsigned long, string> myMap;
   map<unsigned long, string>::iterator it;
  // std::vector<int>* vector = new std::vector<int>(M);	// Hint: This comes in handy
		int permutation_count = 0;
		float goodness = 0;
		double collisions = 0;
		do {
		if (permutation_count == M) break;
		// Code for computing the hash and updating the array
		unsigned long x = bernstein(str, M);
		it = myMap.find(x);
	if(it != myMap.end()) {
			//bernstein already in map
			collisions++;
	}
	else
		myMap.insert(pair<unsigned long, string>(x, str));
    permutation_count++;
	}while(std::next_permutation(str.begin(), str.end()));

	//Code for determining goodness
//cout<<countCollisions(*vector);
  goodness=collisions/M;

	return goodness;
}
