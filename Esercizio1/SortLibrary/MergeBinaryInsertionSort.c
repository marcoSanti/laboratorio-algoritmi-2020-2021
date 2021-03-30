#include "MergeBinaryInsertionSort.h"

int compareInt(record* firstRecord, record* secondRecord) {
    return firstRecord->numberInt - secondRecord->numberInt;
};

void printElement2(record* record, int conta) {
    fprintf(stdout, "%d-%d\n", record->numberInt, conta);
};

void BinaryInsertionSort(void** array , int l, int r){
    
    // int i, position, k;
    // record tmp;
    
    // for(i=l+1;i<=r; i++){

    //     tmp = array[i];
    //     position = BinarySearchPosition(array, tmp, l, i);

    //     for(k = i; k>position; k--){
    //         array[k] = array[k-1];
    //     }
    //     array[position] = tmp;
    // }
};


int BinarySearchPosition(void** array, int x, int l, int r){
    
    // int mid = (l + r) / 2;

    // if (r <= l){
    //     return l;
    // } 
 
 
    // if (array[mid-1].firstNumber <= x.numberInt && array[mid].firstNumber> x.numberInt){
    //     return mid;
    // } 
 
    // if (x.numberInt > array[mid].numberInt){
    //     return BinarySearchPosition(array, x, mid + 1, r);
    // }else{
    //     return BinarySearchPosition(array, x, l, mid);
    // } 
    return 0;
};


void Merge(void** array,int l,int m,int r){ 

    int n1 = m - l + 1;
    int n2 = r - m;
    int i, j, k = l;

    void* arrayLeft[n1];
    void* arrayRight[n2];

    for(i = 0; i < n1; i++) {
        arrayLeft[i] = array[l + 1];
    }
    for(j = 0; j < n2; j++) {
        arrayRight[j] = array[m + j + 1];
    }
    i=0;
    j=0;
    while(i < n1 && j < n2) {
        // Qui ci dovra' essere un puntatore alla funzione compareInt che viene passato come parametro alla funzione
        if(compareInt(arrayLeft[i], arrayRight[j]) <= 0) {
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
        i++;
        k++;
    }
    while(j < n2) {
        array[k] = arrayRight[j];
        j++;
        k++;
    }
};

void MergeBinaryInsertionSort(void** array ,int l,int r){  //i = 0, j=len(A) - 1
    if(l >= r) {
        return;
    }
    int m = (r + l) / 2;
    // if(r - l < K) {
    //     //BinaryInsertionSort
    // } else {
        MergeBinaryInsertionSort(array, l, m);
        MergeBinaryInsertionSort(array, m+1, r);
        Merge(array, l, m, r);
    // }
}