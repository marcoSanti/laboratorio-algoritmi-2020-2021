
#include "BinarySort.h"

void BinaryInsertionSort(int *array , int arrayLength){
    int i, position, tmp;
    for(i=1;i<arrayLength; i++){
        position = BinarySearchPosition(array, array[i], 0, i);
        tmp = array[i];
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
    int array[] = {2, 3, 4, 5 ,6 ,7 ,9};
    int numberToBeFound = 9;
    int numberFound = BinarySearchPosition(array, numberToBeFound, 0, 7); 
    printf("Position of the number in the array: %d\n", numberFound);   
}