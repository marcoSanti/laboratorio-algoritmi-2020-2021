#include "MergeBinaryInsertionSort.h"


void MergeBinaryInsertionSort(record array[] ,int l,int r){  //i = 0, j=len(A) - 1
    
     if(l>=r){
        return;
    }
    
    int m =(r+l)/2;
    
   if(r-l < K){
        BinaryInsertionSort(array, l, r);
    }else{
        MergeBinaryInsertionSort(array,l,m);
        MergeBinaryInsertionSort(array,m+1,r);
        Merge(array,l,m,r);
   }
    
}

void Merge(record array[],int l,int m,int r){ // 0 5 11
    int n1 = m - l + 1;
    int n2 = r - m;
    int i, j, k = l;
 
    record L[n1], R[n2];
 
    for (i = 0; i < n1; i++){
      L[i] = array[l + i];   
    }
    for (j = 0; j < n2; j++){
        R[j] = array[m + 1 + j];
    }
        
    i = 0;
    j = 0;
 
    while (i < n1 && j < n2) {
        if (L[i].firstNumber <= R[j].firstNumber) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
};