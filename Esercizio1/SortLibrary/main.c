#include "BinarySort.h"
#include "MergeSort.h"

int main(int argc, char* argv[]) {
    int i;
    int arr1[] = {11,10,9,8,7,6,5,4,3,2,1};
    
    for(i=0; i<11; i++) {
        printf("[%d]", arr1[i]);
    }
    printf("\n");
    MergeSort(arr1, 0, 11);
    //BinaryInsertionSort(arr1, 0, 11);
    for(i=0; i<11; i++) {
        printf("[%d]", arr1[i]);
    }
    printf("\n");
    return 0;
}