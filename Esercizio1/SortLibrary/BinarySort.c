#include "MergeBinaryInsertionSort.h"

void BinaryInsertionSort(int *array , int startingIndex, int arrayLength){
    int i, position, tmp, k;
    
    for(i=startingIndex+1;i<startingIndex + arrayLength; i++){
        tmp = array[i];
        position = BinarySearchPosition(array, tmp, startingIndex, i);

        for(k = i; k>position; k--){
            array[k] = array[k-1];
        }
        array[position] = tmp;
    }
};


int BinarySearchPosition(int *array, int x, int l, int r){
    
    int mid = (l + r) / 2;

    if (r <= l){
        if(x > array[l]){
            return l+1;
        } 
        else return l;
    } 
 
 
    if (x == array[mid]){
        return mid + 1;
    } 
 
    if (x > array[mid]){
        return BinarySearchPosition(array, x, mid + 1, r);
    }else{
        return BinarySearchPosition(array, x, l, mid - 1);
    } 

};

