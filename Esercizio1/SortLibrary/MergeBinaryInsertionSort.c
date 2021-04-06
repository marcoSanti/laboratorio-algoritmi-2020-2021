#include "MergeBinaryInsertionSort.h"

void BinaryInsertionSort(void** array , int l, int r, sortingCompareFunction mySortingCompareFunction){
    register int i, position;

    for(i=l+1;i<=r; i++) {
        void* tmp = (void* )array[i];
        position = BinarySearchPosition(array, tmp, l, i, mySortingCompareFunction);
        memcpy(array+position+1, array+position, (i-position)*sizeof(void**) );
        array[position] = tmp;
    }
};

int BinarySearchPosition(void** array, void* x, register int l,register int r, sortingCompareFunction mySortingCompareFunction){
    register int m;
    while(l<=r) {
        m = (l+r)>>1;
        if(mySortingCompareFunction(x, array[m]) <= 0) {
            --r;
        }else{
            ++l;
        }
    }
    return l;
};

void Merge(void** array,register int l,register int m,register int r, sortingCompareFunction mySortingCompareFunction){ 

    register int n1 = m - l + 1;
    register int n2 = r - m;
    register int i=0, j=0, k = l;

    void** arrayLeft = malloc(n1 * sizeof(void*));
    void** arrayRight = malloc(n2 * sizeof(void*));

    memcpy(arrayLeft, array+l, n1*sizeof(void*));
    memcpy(arrayRight, array+m+1, n2* sizeof(void *));
    
   
    while(i < n1 && j < n2) {
        if(mySortingCompareFunction(arrayLeft[i], arrayRight[j]) <= 0) { 
            array[k] = arrayLeft[i];
            ++i;
        } else {
            array[k] = arrayRight[j];
            ++j;
        }
        ++k;
    }
    

    memcpy(array+k, arrayLeft+i, (n1-i) * sizeof(void*));
    k+=(n1-i);
   
    memcpy(array+k, arrayRight+j, (n2-j) * sizeof(void*));
   
    
    free(arrayLeft);
    free(arrayRight);
};

void MergeBinaryInsertionSort(void** array ,register int l,register int r, sortingCompareFunction mySortingCompareFunction){  
    if(l >= r) return;
    
    register int m = (r + l) >> 1;

    if(r - l < K) {
        BinaryInsertionSort(array, l, r, mySortingCompareFunction);
     } else {
        MergeBinaryInsertionSort(array, l, m, mySortingCompareFunction);
        MergeBinaryInsertionSort(array, m+1, r, mySortingCompareFunction);
        Merge(array, l, m, r, mySortingCompareFunction);
    }
}