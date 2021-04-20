#ifndef EDITDISTANCEINC
    #define EDITDISTANCEINC
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>
    #define MIN(x, y) (((x) < (y)) ? (x) : (y))
#endif

int edit_distance(char* s1, char* s2);