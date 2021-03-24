#include "BinarySort.h"
#include "MergeSort.h"

int main(int argc, char* argv[]) {
    int i;
    int arr1[] = {11,10,9,8,7,6,5,4,3,2,1};
    int array[] = {9,8,7,6};

    
    for(i=0; i<4;i++){
        printf(" [%d] ", array[i]);
    }
    printf("\n"); 
    BinaryInsertionSort(array, 4);
    for(i=0; i<4;i++){
        printf(" [%d] ", array[i]);
    } 
    printf("\n\n");  


    
    
    for(i=0; i<11;i++){
        printf(" [%d] ", arr1[i]);
    }
    printf("\n"); 
    BinaryInsertionSort(arr1, 11);
    
    for(i=0; i<11;i++){
        printf(" [%d] ", arr1[i]);
    } 
    printf("\n");


    int A[] = {5, 9, 4, 1, 3, 7, 2}; 
   
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++)
        printf("%d ", A[i]);

    MergeSort(A, 0, sizeof(A)/sizeof(A[0])-1 );

    printf("\n"); 
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++)
        printf("%d ", A[i]);
    
    
    return 0;
}