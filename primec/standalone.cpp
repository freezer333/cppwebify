#include <iostream>
#include "prime_sieve.h"

using namespace std;


// Post 1) Automate this unmodified (compiled as-is)
// Post 1) Automated this modified such that it uses a fixed input/output file
// Post 1) Automate this modified such that it uses file input/output that can be specified at command line
// Post 2) Create a dynamic link library and use https://github.com/node-ffi/
// Post 3) Create a node-addon
// Post 4) Create a node-addon that fires events (this might be really tough)
// Post 5) Use in Silicon

int main() {
    cout << "Here we go!" << endl;
    char * name = "prime_seive";
    char * param = "1000";
    char * argvs[] = {name, param };
    do_primesieve(2, argvs);
}