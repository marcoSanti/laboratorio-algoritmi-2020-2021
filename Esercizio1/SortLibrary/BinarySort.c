#include "MergeBinaryInsertionSort.h"

void BinaryInsertionSort(int *array , int l, int r){
    
    int i, position, tmp, k;
    
    for(i=l+1;i<=r; i++){

        tmp = array[i];
        position = BinarySearchPosition(array, tmp, l, i);

        for(k = i; k>position; k--){
            array[k] = array[k-1];
        }
        array[position] = tmp;
    }
};


int BinarySearchPosition(int *array, int x, int l, int r){
    
    int mid = (l + r) / 2;

    if (r <= l){
        return l;
    } 
 
 
    if (array[mid-1] <= x && array[mid]> x){
        return mid;
    } 
 
    if (x > array[mid]){
        return BinarySearchPosition(array, x, mid + 1, r);
    }else{
        return BinarySearchPosition(array, x, l, mid);
    } 

};

