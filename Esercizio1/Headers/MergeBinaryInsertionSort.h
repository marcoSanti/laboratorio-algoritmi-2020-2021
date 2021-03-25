#ifndef SEARCH_REQ
    #define SEARCH_REQ
    #include <stdio.h>
    #include <stdlib.h>
    #include <strings.h>
    #include "BinarySort.h"
#endif

//Length of sub array at wich point merge sort is swapped with binary insertion sort
#define K 3

void MergeBinaryInsertionSort(int A[], int l, int r);
void Merge(int A[], int l, int m, int r); 