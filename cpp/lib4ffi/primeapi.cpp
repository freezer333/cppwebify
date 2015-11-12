////////
//
//https://github.com/TooTallNate/ref-array
//"type": "shared_library",
////////
#include <iostream>
#include <stdio.h>
#include <functional>

#include "arbiter.h"
#include "prime_sieve.h"

using namespace std;




int getPrimes(int under, int primes[]) {
	int count = 0;
	// it's assumed primes is a pre-allocated array of at least "under" size.

	arbiter b(
        [&](void * data) { 
            int * iptr = (int *) data;
            primes[count++] = *iptr;
        }
    );

    generate_primes(under, (void*)&b);

    return count;

}


int main() {
	int values[100];
	int count = getPrimes(100, values);
	cout << count << endl;
	cout << "------------" << endl;
	for ( int i = 0; i < count; i++ ) {
		cout << values[i] << endl;
	}
}
