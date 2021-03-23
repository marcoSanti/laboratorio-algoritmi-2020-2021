#include "BinarySort.h"

void BinaryInsertionSort(int *array , int arrayLength){
    int i, position, tmp;
    for(i=1;i<arrayLength; i++){
        position = BinarySearchPosition(array, array[i], 0, i);
        tmp = array[i];
        memcpy( &array[position+1], &array[position], i-position);
        array[position] = tmp;
    }
}