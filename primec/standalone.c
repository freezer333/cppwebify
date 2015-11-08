
#include "prime_sieve.h"




// 1) Automate this unmodified (compiled as-is)
// 1) Automated this modified such that it uses a fixed input/output file
// 1) Automate this modified such that it uses file input/output that can be specified at command line
// 2) Create a node-addon
// 3) Create a node-addon that fires events (this might be really tough)
// 4) Use in Silicon

int main() {
    char * name = "prime_seive";
    char * param = "1000";
    char * argvs[] = {name, param };
    do_primesieve(2, argvs);
}