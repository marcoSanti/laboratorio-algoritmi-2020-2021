#include "MergeBinaryInsertionSort.h"

void BinaryInsertionSort(void** array , int l, int r, sortingCompareFunction mySortingCompareFunction, int sortingOrder){
    int i, position;

    for(i=l+1;i<=r; i++) {
        void* tmp = (void* )array[i];
        position = BinarySearchPosition(array, tmp, l, i, mySortingCompareFunction, sortingOrder);
        memcpy(array+position+1, array+position, (i-position)*sizeof(void**) );
        array[position] = tmp;
    }
};

int BinarySearchPosition(void** array, void* x, int l, int r, sortingCompareFunction mySortingCompareFunction, int sortingOrder){
    int m;
    while(l<=r) {
        m = (l+r)/2;
        if(mySortingCompareFunction(x, array[m], sortingOrder) <= 0) {
            r--;
        }else{
            l++;
        }
    }
    return l;
};

void Merge(void** array,int l,int m,int r, sortingCompareFunction mySortingCompareFunction, int sortingOrder){ 

    int n1 = m - l + 1;
    int n2 = r - m;
    int i, j, k = l;

    //this needs to be allocated into the hep otherwise it will exaust the available space into the stak
    void** arrayLeft = malloc(n1 * sizeof(void*));
    void** arrayRight = malloc(n2 * sizeof(void*));

    for(i = 0; i < n1; i++) arrayLeft[i] = array[l + i];
    
    for(j = 0; j < n2; j++) arrayRight[j] = array[m + j + 1];
    
    i=0;j=0;
    while(i < n1 && j < n2) {
        if(mySortingCompareFunction(arrayLeft[i], arrayRight[j], sortingOrder) <= 0) { 
            array[k] = arrayLeft[i];
            i++;
        } else {
            array[k] = arrayRight[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        array[k] = arrayLeft[i];
        i++; k++;
    }
    while(j < n2) {
        array[k] = arrayRight[j];
        j++; k++;
    }
    free(arrayLeft);
    free(arrayRight);
};

void MergeBinaryInsertionSort(void** array ,int l,int r, sortingCompareFunction mySortingCompareFunction, int sortingOrder){  
    if(l >= r) return;
    
    int m = (r + l) / 2;
    if(r - l < K) {
        BinaryInsertionSort(array, l, r, mySortingCompareFunction, sortingOrder);
     } else {
        MergeBinaryInsertionSort(array, l, m, mySortingCompareFunction, sortingOrder);
        MergeBinaryInsertionSort(array, m+1, r, mySortingCompareFunction, sortingOrder);
        Merge(array, l, m, r, mySortingCompareFunction, sortingOrder);
    }
}