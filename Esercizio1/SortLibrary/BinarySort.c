
#include "BinarySort.h"

void BinaryInsertionSort(int *array , int arrayLength){
    int i, position, tmp;

    for(i=1;i<arrayLength; i++){

        position = BinarySearchPosition(array, array[i], 0, i);
        tmp = array[i];
        printf("got here at %i\n", i);
        memcpy( &array[position+1], &array[position], i-position);
        array[position] = tmp;
    }
};

int BinarySearchPosition(int *array, int x, int i, int j){
    int m = (i+j)/2;
    
    if(array[m] == x) {
        return m;
    } 
    if(array[m] > x) {
        return BinarySearchPosition(array, x, i, m-1);
    }
    return BinarySearchPosition(array, x, m+1, j);
};

int main(int argc, char* argv[]) {
    int array[] = {9,8,7,6,5,4,3,2,1,0};
    
    BinaryInsertionSort(array, 10);
    for(int i=0; i<10;i++){
        printf(" %d ", array[i]);
    } 
    printf("\n");   
}