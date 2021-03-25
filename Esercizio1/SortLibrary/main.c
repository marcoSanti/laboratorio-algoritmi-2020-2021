#include "BinarySort.h"
#include "MergeSort.h"

int main(int argc, char* argv[]) {
    int i;
    int arr1[] = {11,10,9,8,7,6,5,4,3,2,1,20,19,18,17,16,15,14,13,12};
    
    for(i=0; i<20; i++) {
        printf("[%d]", arr1[i]);
    }
    printf("\n");
    MergeSort(arr1, 0, 20);
    for(i=0; i<20; i++) {
        printf("[%d]", arr1[i]);
    }
    printf("\n");
    return 0;
}