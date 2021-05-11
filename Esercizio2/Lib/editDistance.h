#ifndef EDITDISTANCEINC
    #define EDITDISTANCEINC
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>

    #define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define SEPARATOR " ,.:;-_\n"


#endif
/*
    This function calculates the edit distance between the two parameters, that are two strings,
    without the dynamic programming. 
*/
int edit_distance(char *s1, char *s2);


/*
    this function is a wrapper to the _edit_distance_dyn() and thus this function shall be called insead of the other one.
    into this function, the memoization support matrix is initialized, and the two strings length are called.
    It returns the value calculated by _edit_distance_dyn()
    str1, str2: strings of which we calculate the edit distance.
    int *memoizationHelpMatrix is an array of dimenion rowSize*rowSize*sizeof(int) where rowSize is the max legth
    of a word between the dictionary and the correctMe file 
*/
int edit_distance_dyn(char *str1, char *str2, int *memoizationHelpMatrix, int rowSize);