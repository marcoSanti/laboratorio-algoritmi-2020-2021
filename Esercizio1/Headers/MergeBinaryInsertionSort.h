#ifndef SEARCH_REQ
    #define SEARCH_REQ
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/types.h>
    #include <errno.h>
    #include <unistd.h>
    //Length of sub array at wich point merge sort is swapped with binary insertion sort
    #define K 45
#endif

typedef int (*sortingCompareFunction)(void*, void*);

/*
    This function implements the algoritm Merge - Binary insertion sort, by using the 
    Constant K (defined at line 10) to decide whether the binary insertion sort or the merge sort is used
    List of parameters:
        - array: a pointer to an array of records to be sorted
        -l : the lower index bound of the element. When the function is called for the first time, it should be 0
        -r : the upper boundaries of the indexes of my array. When the function is called for the first time it should be the last valid index of the array (array.length -1)
*/
void MergeBinaryInsertionSort(void** array, int l, int r, sortingCompareFunction mySortingCompareFunction);

/*
    This method proceed to merge two Sub arrays into a single array.
    Be aware that this is done by using two support arrays wich could cause some swapping if your system is low on memory.
    The parameters are: 
        -array: a pointer to the array in wich the sub arrays should be taken
        -l: the begin index of the first sub array to be merged
        -m : the mid point wich both function as last index for the first sub array and the begon index for the second sub array
        -r : the upper bound of the second sub array to be sorted

    BE AWARE THAT THIS FUNCTION IS ONLY MEANT TO BE CALLED BY THE MergeBinaryInsertionSort METHOD
*/
void Merge(void** array, int l, int m, int r, sortingCompareFunction mySortingCompareFunction);

/*
    This method implements an insertion sort algorithm with a binary search for the position in wich to insert the new element
    The parameter are:
        -array: a pointer to the array in wich the sub arrays should be taken
        -l : the beggining index of the array 
        -r : the end of the array to be sorted
    BE AWARE THAT THIS FUNCTION IS ONLY MEANT TO BE CALLED BY THE MergeBinaryInsertionSort METHOD
*/
void BinaryInsertionSort(void** array , int l, int r, sortingCompareFunction mySortingCompareFunction);

/*
    This method returns the position in wich the new element shall be inserted by using the binary dicotomic search algoritm.
    Parameters are: 
        -array: a pointer to the array in wich the sub arrays should be taken
        -x the element that needs to be inserte
        -i : the beggining index of the array 
        -j : the end of the array to be sorted
    BE AWARE THAT THIS FUNCTION IS ONLY MEANT TO BE CALLED BY THE MergeBinaryInsertionSort METHOD
*/
int BinarySearchPosition(void** array, void* x, int i, int j, sortingCompareFunction mySortingCompareFunction); 
