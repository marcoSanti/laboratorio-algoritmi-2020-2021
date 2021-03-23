#include "BinarySort.h"

void BinaryInsertionSort(int *array , int arrayLength){
    int i, position, tmp;

    for(i=1;i<arrayLength; i++){
        tmp = array[i];
        position = BinarySearchPosition(array, tmp, 1, i);
        memcpy( &array[position+1], &array[position], i-position);
        array[position] = tmp;
    }
};

int BinarySearchPosition(int *array, int x, int i, int j){
    int m = (i+j)/2;
    if(array[m+1] >= x && array[m] < x) {
        return x;
    } else if(array[m] > x) {
        return BinarySearchPosition(array, x, i, m-1);
    } else {
        return BinarySearchPosition(array, x, m+1, j);
    }
};

int main(int argc, char* argv[]) {
    int array[] = {9,8,7,6};
    for(int i=0; i<4;i++){
        printf(" [%d] ", array[i]);
    }
    printf("\n"); 
    BinaryInsertionSort(array, 4);
    for(int i=0; i<4;i++){
        printf(" [%d] ", array[i]);
    } 
    printf("\n");   
}