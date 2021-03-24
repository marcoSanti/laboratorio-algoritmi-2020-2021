#include "BinarySort.h"

void BinaryInsertionSort(int *array , int startingIndex, int arrayLength){
    int i, position, tmp, k;
    for(i=startingIndex+1;i<arrayLength; i++){
        tmp = array[i];
        position = BinarySearchPosition(array, tmp, startingIndex, i);
        for(k = i; k>position; k--){
            array[k] = array[k-1];
        }
        array[position] = tmp;
    }
};


int BinarySearchPosition(int *array, int x, int i, int j){
    int m = (i+j)/2;
    
    if((array[m] >= x && array[m-1] <= x) || (m== 0 && x < array[0])) {
        return m;
    }else if(x>array[m]) {
        return BinarySearchPosition(array, x, m+1, j);
    }else{
        return BinarySearchPosition(array, x, i, m-1);
    }
};

