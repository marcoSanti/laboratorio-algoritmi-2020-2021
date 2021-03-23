#include "BinarySort.h"

void BinaryInsertionSort(int *array , int arrayLength){
    int i, position, tmp;

    for(i=1;i<arrayLength; i++){
            
        tmp = array[i];
        position = BinarySearchPosition(array, tmp, 1, i);
    
        for(int k = i; k>position; k--){
            array[k] = array[k-1];
        }
        
        array[position] = tmp;
    }
};


int BinarySearchPosition(int *array, int x, int i, int j){
    int m = (i+j)/2;
    
    if((array[m] >= x && array[m-1] <= x) || i==j){
        return m;
    }else if(x>array[m]) {
        return BinarySearchPosition(array, x, m+1, j);
    }else{
        return BinarySearchPosition(array, x, i, m-1);
    }
};

