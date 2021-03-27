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


void Merge(record array[],int l,int m,int r){ 

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