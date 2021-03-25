#include "MergeBinaryInsertionSort.h"

int main(int argc, char* argv[]) {
    int i;
    int arr1[] = {20,17,12,15,11,10,8,6,4,1,2,3,5,7,9,13,14,16,18,19};
    
    for(i=0; i<20; i++) {
        printf("[%d]", arr1[i]);
    }
    printf("\n");
    MergeBinaryInsertionSort(arr1, 0, 19);
    for(i=0; i<20; i++) {
        printf("[%d]", arr1[i]);
    }
    printf("\n");
    return 0;
}