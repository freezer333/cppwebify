#include <iostream>
#include <stdio.h>


#include "baton.h"
#include "prime_sieve.h"

using namespace std;


// This is just an example of using the baton class to allow
// the c code to call an object's member function.  This same technique
// will be used in the node addon example, in order to allow
// the prime numbers to be generated asynchronously.

// Take a look at baton.h - it defines a send function, and also
// a C wrapper function call "pass".  The c code (prime_sieve.c)
// will call pass - which in turn calls baton->send.d

// In the node addon example, baton->send will fire a callback
// that maps to JavaScript.
int main(int argc, char ** argvs) {
    baton b;
    generate_primes(1000, &b);
}