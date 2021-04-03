#include "unity.h"
#include "MergeBinaryInsertionSort.h"
#define MAX_LEN 128

/*
    This struct keeps saved the preferences of the sorting algorithm. It saves the pointer to the function 
    that will be used to sort the array.
    It also save the order in which the sorting will occur (ex: non decreasing or non increasing)
*/
typedef struct {
    sortingCompareFunction comparePreference;
    int insertionOrder; 
} sortingPreferences;

/*
  This struct will be used to store the data coming from the file wich will be required to be sorted
*/
typedef struct {
    int id;
    char* string;
    int numberInt;
    float numberFloat;
} record;

/*
  This method compares two strings and returns the distances between the two
*/
int compareTwoString(record* firstRecord, record* secondRecord, int insertionOrder){
  int result = strcmp(firstRecord -> string, secondRecord -> string); 
  if(insertionOrder==1){
    return result; 
  }else{
    return -result; 
  }
}

/*
  this function compares two functions and tell whether the first number is smaller than the second
*/
int compareTwoFloats(record* firstRecord, record* secondRecord, int insertionOrder){
    if(firstRecord->numberFloat <= secondRecord->numberFloat){
      if(insertionOrder==1) return 0;
      else return 1;
  }
  if(insertionOrder==1) return 1;
  else return 0;  

}

/*
  this function compares two integer and return the difference between the two numbers
*/
int compareTwoIntegers(record* firstRecord, record* secondRecord, int insertionOrder){  
  int result = firstRecord->numberInt - secondRecord->numberInt;
  if(insertionOrder==1){
       return result; 
  }else{
    return -result; 
  }
}

int arrayIsSorted(void** array, int size, sortingCompareFunction mySortingCompareFunction, int insertionOrder) {
  int i;
  for(i = 0; i < size-1; i++) {
        if(mySortingCompareFunction(array[i], array[i+1],insertionOrder) > 0) {
            return 0;
        }
    }
    return 1;
}


void setUp (void) {} 
void tearDown (void) {}

int main(int argc,char* argv[]){
    int insertionModeUser, sizeOfArray=0,line = 0, id, i, secondNumber, asd;
    float thirdNumber;
    double duration; 
    char stringInFile[MAX_LEN];
    record** myRecord;
    sortingPreferences mySortingPreferences;
    record* singleElement; 
    FILE* myFile;

    myRecord  = (record**) malloc(sizeof(record*));

    if(argc != 2) myFile = fopen("records.csv", "r");
    else myFile = fopen(argv[1], "r");

    if(myFile == NULL) {
        fprintf(stderr, "Error: Unable to open csv file. Error is: %s", strerror(errno));
        return 0;
    }

    mySortingPreferences.comparePreference =(sortingCompareFunction) compareTwoString;
    mySortingPreferences.insertionOrder = 1;

    MergeBinaryInsertionSort((void** )myRecord, 0, sizeOfArray-1, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder);
    TEST_ASSERT_TRUE(arrayIsSorted((void**)myRecord, sizeOfArray, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder));

    mySortingPreferences.insertionOrder = 2;

    MergeBinaryInsertionSort((void** )myRecord, 0, sizeOfArray-1, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder);
    TEST_ASSERT_TRUE(arrayIsSorted((void**)myRecord, sizeOfArray, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder));

    mySortingPreferences.comparePreference =(sortingCompareFunction) compareTwoIntegers;
    mySortingPreferences.insertionOrder = 1;

    MergeBinaryInsertionSort((void** )myRecord, 0, sizeOfArray-1, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder);
    TEST_ASSERT_TRUE(arrayIsSorted((void**)myRecord, sizeOfArray, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder));

    mySortingPreferences.insertionOrder = 2;

    MergeBinaryInsertionSort((void** )myRecord, 0, sizeOfArray-1, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder);
    TEST_ASSERT_TRUE(arrayIsSorted((void**)myRecord, sizeOfArray, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder));

    mySortingPreferences.comparePreference =(sortingCompareFunction) compareTwoFloats;
    mySortingPreferences.insertionOrder = 1;

    MergeBinaryInsertionSort((void** )myRecord, 0, sizeOfArray-1, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder);
    TEST_ASSERT_TRUE(arrayIsSorted((void**)myRecord, sizeOfArray, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder));

    mySortingPreferences.insertionOrder = 2;

    MergeBinaryInsertionSort((void** )myRecord, 0, sizeOfArray-1, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder);
    TEST_ASSERT_TRUE(arrayIsSorted((void**)myRecord, sizeOfArray, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder));


    while(fscanf(myFile, "%d,%[^,],%d,%f\n", &id, stringInFile, &secondNumber, &thirdNumber) != EOF) {
        singleElement = (record*) malloc(sizeof(record));
        singleElement->id = id;
        singleElement->string = (char*) malloc(sizeof(char) * strlen(stringInFile) + 1);
        strcpy(singleElement->string, stringInFile);
        singleElement->numberInt = secondNumber;
        singleElement->numberFloat = thirdNumber;
        line++;        
        myRecord = (record**) realloc(myRecord, sizeof(record*)*line);
        myRecord[line-1] = singleElement;
    } 
    sizeOfArray = line;
    fclose(myFile);

    mySortingPreferences.insertionOrder = 1;

    MergeBinaryInsertionSort((void** )myRecord, 0, sizeOfArray-1, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder);
    TEST_ASSERT_TRUE(arrayIsSorted((void**)myRecord, sizeOfArray, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder));

    mySortingPreferences.insertionOrder = 2;

    MergeBinaryInsertionSort((void** )myRecord, 0, sizeOfArray-1, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder);
    TEST_ASSERT_TRUE(arrayIsSorted((void**)myRecord, sizeOfArray, mySortingPreferences.comparePreference, mySortingPreferences.insertionOrder));


  


}