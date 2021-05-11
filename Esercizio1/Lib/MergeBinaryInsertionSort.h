#ifndef SEARCH_REQ
    #define SEARCH_REQ
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/types.h>
    #include <errno.h>
    #include <unistd.h>
    #include <time.h>
    #include <signal.h>
#define K 15 //Length of sub array at wich point merge sort is swapped with binary insertion sort
#endif

/*
    This typedef is here to be able to pass the pointer to the function which will be doing the comparison.
    This way, the algoritm will be able to work with whatever data structure you would think of as long as you define
    a compare function for the data structure you have implemented.
    The first two elements are the ones wich the comparison will happen, while the third parameter is the one that is going t decide the sorting order
*/
typedef int (*sortingCompareFunction)(void *, void *);

/*
    This function implements the algoritm Merge - Binary insertion sort, by using the 
    Constant K (defined at line 10) to decide whether the binary insertion sort or the merge sort is used
    List of parameters:
        - array: a pointer to an array of records to be sorted
        -l : the lower index bound of the element. When the function is called for the first time, it should be 0
        -r : the upper boundaries of the indexes of my array. When the function is called for the first time it should be the last valid index of the array (array.length -1)
        -mySortingCompareFunction:  This is a pointer to the comparing function to be used into the method
*/
void MergeBinaryInsertionSort(void **array, int l, int r, sortingCompareFunction mySortingCompareFunction);
