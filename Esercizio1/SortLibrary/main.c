#include "MergeBinaryInsertionSort.h"

int main(int argc, char* argv[]) {
    int i;
    int size = 200;
    record arr1[size];
    
    srand(getpid());
    
    for(i=0; i<size; i++) {
        arr1[i].firstNumber = rand()%200;
        printf("[%d]", arr1[i].firstNumber);
    }
    printf("\n\n");
    MergeBinaryInsertionSort(arr1, 0, size -1);

    for(i=1; i<size; i++) {
        printf("[%d]", arr1[i].firstNumber);

        if(arr1[i-1].firstNumber> arr1[i].firstNumber){
            printf("\nArray non ordinato");
            return 0;
        }
    }
    printf("\nArray ordinato!");
    printf("\n");
    return 0;
}