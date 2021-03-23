#include "unity.h"
#include "BinarySort.h"


int ArrayAreEquals(int *array1, int* array2, int len1, int len2){
    int i=0, equals = 1;
    if(len1 != len2) return 0;

    while(i<len1 && equals){
        equals = equals && array1[i] == array2[i];
        i++;
    }
    return equals;
}


void setUp (void) {} 
void tearDown (void) {}

int main(){
   
    //test per algo solo per BinaryIsertionSort solo con array di interi

    int arr1[] = {4,3,2,1};
    int arr1sorted[] = {1,2,3,4};

    int arr2[] = {10,9,8,7,6,5,4,3,2,1};
    int arr2sorted[] = {1,2,3,4,5,6,7,8,9,10};

    int arr3[] = {};
    int arr3sorted[] = {};

    BinaryInsertionSort(arr1, 4);
    TEST_ASSERT_TRUE(ArrayAreEquals(arr1, arr1sorted, 4, 4));

    BinaryInsertionSort(arr2, 10);
    TEST_ASSERT_TRUE(ArrayAreEquals(arr2, arr2sorted, 10, 10));

    BinaryInsertionSort(arr3, 0);
    TEST_ASSERT_TRUE(ArrayAreEquals(arr3, arr3sorted, 0, 0));
}