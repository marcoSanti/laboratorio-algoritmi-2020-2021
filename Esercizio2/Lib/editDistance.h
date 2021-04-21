#ifndef EDITDISTANCEINC
    #define EDITDISTANCEINC
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>
    #define MIN(x, y) (((x) < (y)) ? (x) : (y))
    #define SEPARATOR " ,.:;-_\n"
#endif

int edit_distance(char* s1, char* s2);

int edit_distance_dyn(char* s1, char* s2);

char** loadDictionary(char *fileName, int *dictionaryElements);