#include "baton.h"






void pass(void * thebaton, int data) {
    baton * b = (baton *) thebaton;
    b->send(data);
}

