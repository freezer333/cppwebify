#include <iostream>
#include <stdio.h>
#include "../prime_sieve.h"

using namespace std;


// Simulating a legacy C++ app that always reads
// it's input from a fixed file (input.txt) and
// outputs to a fixed file (output.txt).
int main(int argc, char ** argvs) {

    FILE * in = fopen("input.txt", "r");

    int i;
    fscanf (in, "%d", &i);   
    fclose(in);

    FILE * out = fopen("output.txt", "w");

    generate_primes(i, out);

    fprintf(stdout, "Output saved in output.txt\n");
    fclose(out);
}