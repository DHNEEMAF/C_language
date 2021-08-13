#include "my_ls.h"

/* swapping between outputs when needed */
void swap_int(int* xp, int* yp)
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void swap_str(char** xp, char** yp) 
{ 
    char* temp = *xp;
    *xp = *yp;
    *yp = temp;
}
