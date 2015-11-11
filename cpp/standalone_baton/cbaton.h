
/*

    This should not be included directly from C++ code.  Instead, 
    always include baton.h

    C code cannot include baton.h, and should only include this file.

    Using _batonclass a guard because g++ on Mac wasn't properly
    setting the _cplusplus definition!

*/

#ifdef _batonclass
extern "C" {
#endif

void pass(void * thebaton, int data);

#ifdef _batonclass
}
#endif

