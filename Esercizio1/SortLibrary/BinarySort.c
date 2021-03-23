#include "BinarySort.h"

void BinaryInsertionSort(int *array , int arrayLength){
    int i, position, tmp;

    for(i=1;i<arrayLength; i++){
        tmp = array[i];
        position = BinarySearchPosition(array, tmp, 1, i);
        
        //memcpy( &array[position+1], &array[position], i-position);
        for(int k = i; k>position; k--){
            array[k] = array[k-1];
        }
        
        array[position] = tmp;
    }
};

int BinarySearchPosition(int *array, int x, int i, int j){
    int m = (i+j)/2;
    
    if(array[m] >= x && array[m-1] <= x){
        return m;
    }else if(x>array[m]) {
        return BinarySearchPosition(array, x, m+1, j);
    }else{
        return BinarySearchPosition(array, x, i, m-1);
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