#include "MergeBinaryInsertionSort.h"


void MergeBinaryInsertionSort(int A[] ,int l,int r){  //i = 0, j=len(A) - 1
    
     if(l>=r){
        return;
    }
    
    int m =(r+l)/2;
    
   if(r-l < K){
        BinaryInsertionSort(A, l, r);
    }else{
        MergeBinaryInsertionSort(A,l,m);
        MergeBinaryInsertionSort(A,m+1,r);
        Merge(A,l,m,r);
   }
    
}

void Merge(int A[],int l,int m,int r){ // 0 5 11
    int n1 = m - l + 1;
    int n2 = r - m;
    int i, j, k = l;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++){
      L[i] = A[l + i];   
    }
    for (j = 0; j < n2; j++){
        R[j] = A[m + 1 + j];
    }
        
    i = 0;
    j = 0;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
};