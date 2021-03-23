#include "BinarySort.h"

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
    
    
    return 0;
}