#include <vector>
#include "Primes.h"

std::vector<int> *genPrimes(int M) {
    std::vector<int> *v = new std::vector<int>();


    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[M];
    memset(prime, true, sizeof(prime));

    for (int p=2; p<M; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=M; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p=2; p<=M; p++){
       if (prime[p])
          v->push_back(p);
}


    return v;
}
