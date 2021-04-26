#ifndef EDITDISTANCEINC
    #define EDITDISTANCEINC
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>

    #define MIN(x, y) (((x) < (y)) ? (x) : (y))
    #define SEPARATOR " ,.:;-_\n"

    int memoizationHelpMatrix[50][50]; //used for dynamic programming! 
    

#endif

int edit_distance(char* s1, char* s2);

char** loadDictionary(char *fileName, int *dictionaryElements);

int edit_distance_dyn(char* str1, char* str2, int strlen1, int strlen2);