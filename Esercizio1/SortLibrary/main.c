#include "MergeBinaryInsertionSort.h"

#define MAX_LEN 128
int sizeOfArray;


/*
    Struct with the pointer to the function that will be used inside the ordering functions
*/
typedef struct {
    sortingCompareFunction comparePreference;
} sortingPreferences;

typedef struct {
    int id;
    char* string;
    int numberInt;
    float numberFloat;
} record;

void arrayIsSorted(void** array, int size, sortingCompareFunction mySortingCompareFunction) {
  int intSortedElements=0;

  for(int i = 0; i < size-1; i++) {
        if(mySortingCompareFunction(array[i], array[i+1]) > 0) {
            fprintf(stderr, "\n================\nNOT SORTED\n================\n");
            exit(EXIT_FAILURE);
        }
        intSortedElements++;
    }
    
    fprintf(stderr, "Sorted %d items!\n", intSortedElements);
}
 
int compareTwoString(record* firstRecord, record* secondRecord){
  return strcmp(firstRecord -> string, secondRecord -> string); 
}

int compareTwoFloats(record* firstRecord, record* secondRecord){
  if(firstRecord->numberFloat <= secondRecord->numberFloat){
    return 0;
  }
  return 1;
}

int compareTwoIntegers(record* firstRecord, record* secondRecord){  
  return firstRecord->numberInt - secondRecord->numberInt;
}

int main(int argc, char* argv[]) {
    record** myRecord = (record**) malloc(sizeof(record*));
    FILE* myFile = fopen("records.csv", "r");
    if(myFile == NULL) {
        fprintf(stderr, "Error: %s", strerror(errno));
        return 0;
    }
    /* Setting up the pointer to the function that will be used to compare */
    sortingPreferences mySortingPreferences;
    mySortingPreferences.comparePreference = (sortingCompareFunction) compareTwoString;
    /*Finished set up */
    int line = 0;
    char stringInFile[MAX_LEN];
    int id;
    int i;
    int secondNumber;
    float thirdNumber;
    record* singleElement; 

    printf("Starting read from file...\n");
    //a 8mln400mila il programma crasha
    while(line != 80 && fscanf(myFile, "%d,%[^,],%d,%f\n", &id, stringInFile, &secondNumber, &thirdNumber) != EOF) {
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

    printf("Read complete...\nStarting sorting...\n");
    
    MergeBinaryInsertionSort((void** )myRecord, 0, sizeOfArray-1, mySortingPreferences.comparePreference);
    
    printf("Sorting complete...\nStarting Verification...\n");    

    arrayIsSorted((void**)myRecord, sizeOfArray, mySortingPreferences.comparePreference);
    free(myRecord);
    return 0;
}