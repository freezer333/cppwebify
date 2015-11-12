
/*

    This should not be included directly from C++ code.  Instead, 
    always include arbiter.h

    C code cannot include arbiter.h, and should only include this file.

    Using _arbiterclass a guard because g++ on Mac wasn't properly
    setting the _cplusplus definition!

*/

#ifdef _arbiterclass
extern "C" {
#endif

void pass(void * thearbiter, int data);

#ifdef _arbiterclass
}
#endif

