#ifndef SEARCH_REQ
    #define SEARCH_REQ
    #include <stdio.h>
    #include <stdlib.h>
    #include <strings.h>
    #include <sys/types.h>
    #include <unistd.h>
#endif

//Length of sub array at wich point merge sort is swapped with binary insertion sort
#define K 2

typedef struct {
    int firstNumber;
} record;

void MergeBinaryInsertionSort(record array[], int l, int r);
void Merge(record array[], int l, int m, int r); 
void BinaryInsertionSort(record *array , int startingIndex, int arrayLength);
int BinarySearchPosition(record *array, record x, int i, int j); 
