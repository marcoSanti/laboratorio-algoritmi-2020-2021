#include "MergeBinaryInsertionSort.h"

void BinaryInsertionSort(record *array , int l, int r){
    
    int i, position, k;
    record tmp;
    
    for(i=l+1;i<=r; i++){

        tmp = array[i];
        position = BinarySearchPosition(array, tmp, l, i);

        for(k = i; k>position; k--){
            array[k] = array[k-1];
        }
        array[position] = tmp;
    }
};


int BinarySearchPosition(record *array, record x, int l, int r){
    
    int mid = (l + r) / 2;

    if (r <= l){
        return l;
    } 
 
 
    if (array[mid-1].firstNumber <= x.firstNumber && array[mid].firstNumber> x.firstNumber){
        return mid;
    } 
 
    if (x.firstNumber > array[mid].firstNumber){
        return BinarySearchPosition(array, x, mid + 1, r);
    }else{
        return BinarySearchPosition(array, x, l, mid);
    } 

};

