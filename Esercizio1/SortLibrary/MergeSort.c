#include "BinarySort.h"
#include "MergeSort.h"

void MergeSort(int A[] ,int i,int j){  //i = 0, j=len(A) - 1
    int k=2;
    int m;
    if (j-i+1 < k){ // len(A) = j-i+1
      BinaryInsertionSort(A, i, j);
    }
    else{    
        m = (i+j)/2;
        MergeSort(A, i, m); 
        MergeSort(A, m+1, j);  
        Merge(A, i ,m , j);
    }

}

void Merge(int A[],int i,int m,int j){
    int n1 = m-i+1;
    int n2 =j-m; 
    int L[n1];
    int R[n2];
    int a = 0; //posizione su L
    int b = 0; //posizione su R
    int c = i; //posizione su arrSupporto

    for(int a=0; a<n1; a++){
        L[a] = A[i + a];
    }
    for(int b=0; b<n2; b++){
        R[b] = A[m + 1 + b];
    }

    while(c < j){
        if(a < n1 && L[a] < R[b]){
            A[c] = L[a];
            a++;
        }
        else{
            A[c] = R[b]; 
            b++;
        }
        c++;
    }

  /*  while(a < n1){
        A[c] = L[a];
        a++;
        c++; 
    }

    while(b < n2){
        A[c] = R[b]; 
        b++; 
        c++;
    }*/
        
    
}


