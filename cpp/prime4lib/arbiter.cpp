#include "arbiter.h"

void pass(void * thearbiter, int data) {
    arbiter * b = (arbiter *) thearbiter;
    b->send(data);
}

