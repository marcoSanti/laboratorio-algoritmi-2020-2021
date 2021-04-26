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
/*
    This function calculates the edit distance between the two parameters, that are two strings,
    without the dynamic programming. 
*/
int edit_distance(char* s1, char* s2);

/*
    This function imports our dictionary and inside it there are the correct words that will be used to 
    correct the wrong words. 
*/
char** loadDictionary(char *fileName, int *dictionaryElements);

/*
    This function calculates the edit distance between two strings, by dynamic programming with the memoization technique.
    The parameters are: 
    str1, str2: strings of which we calculate the edit distance.
    strlen1, strlen2: lengths respectively of str1, str2. 
*/
int edit_distance_dyn(char* str1, char* str2, int strlen1, int strlen2);