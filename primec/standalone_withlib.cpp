#include <iostream>
#include "prime_sieve.h"

using namespace std;


// 1) Automate this unmodified (compiled as-is)
// 1) Automated this modified such that it uses a fixed input/output file
// 1) Automate this modified such that it uses file input/output that can be specified at command line
// 2) Create a dynamic link library and use https://github.com/node-ffi/
// 3) Create a node-addon
// 4) Create a node-addon that fires events (this might be really tough)
// 5) Use in Silicon

int main() {
    cout << "Here we go again!" << endl;
    char * name = "prime_seive";
    char * param = "1000";
    char * argvs[] = {name, param };
    do_primesieve(2, argvs);
}