#include <iostream>
#include <stdio.h>
#include <functional>

#include "arbiter.h"
#include "prime_sieve.h"

using namespace std;


// This is just an example of using the arbiter class to allow
// the c code to call an object's member function.  This same technique
// will be used in the node addon example, in order to allow
// the prime numbers to be generated asynchronously.

// Take a look at arbiter.h - it defines a send function, and also
// a C wrapper function call "pass".  The c code (prime_sieve.c)
// will call pass - which in turn calls arbiter->send.d

// In the node addon example, arbiter->send will fire a callback
// that maps to JavaScript.
int main(int argc, char ** argvs) {
    arbiter b(
        [&](void * data) { 
            int * iptr = (int *) data;
            cout << "I got " << *iptr << endl;
            return;
        }

    );
    generate_primes(1000, (void*)&b);
}