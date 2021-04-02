#include "MergeBinaryInsertionSort.h"

#define MAX_LEN 128
#define TIME_LIM 600

/*
    This struct keeps saved the preferences of the sorting algorithm. It saves the pointer to the function 
    that will be used to sort the array.
    It also save the order in which the sorting will occur (ex: non decreasing or non increasing)
*/
typedef struct {
    sortingCompareFunction comparePreference;
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
  This function is used to chech wheter an array is sorted by a certain parameter wich is decided by the
  mySortingCompareFunction pointer to compare function. 
*/
void arrayIsSorted(void** array, int size, sortingCompareFunction mySortingCompareFunction) {
  int i;
  for(i = 0; i < size-1; i++) {
        if(mySortingCompareFunction(array[i], array[i+1]) > 0) {
            fprintf(stderr, "\n================\nNOT SORTED\n================\n");
            exit(EXIT_FAILURE);
        }
    }
}
 
/*
  This method compares two strings and returns the distances between the two
*/
int compareTwoString(record* firstRecord, record* secondRecord){
  return strcmp(firstRecord -> string, secondRecord -> string); 
}

/*
  this function compares two functions and tell whether the first number is smaller than the second
*/
int compareTwoFloats(record* firstRecord, record* secondRecord){
  if(firstRecord->numberFloat <= secondRecord->numberFloat){
    return 0;
  } else {
    return 1;
  }
}


/*
  this function compares two integer and return the difference between the two numbers
*/
int compareTwoIntegers(record* firstRecord, record* secondRecord){  
  return firstRecord->numberInt - secondRecord->numberInt;
}

/*
  This function handles the signal.
  in particular, when 10 minutes have elapsed, it will kill the process
*/
void signalHandler(int signal) {
  switch(signal) {
    case SIGALRM:
      fprintf(stderr, "mmm...Time's up, pack your things, we are leaving\n");
      exit(EXIT_FAILURE);
    break;
  }
}

int main(int argc, char* argv[]) {
    int insertionModeUser, sizeOfArray,line = 0, id, i, secondNumber;
    float thirdNumber;
    double duration; 
    char stringInFile[MAX_LEN];
    clock_t start, stop;
    record** myRecord;
    sortingPreferences mySortingPreferences;
    record* singleElement; 
    FILE* myFile;

    myRecord  = (record**) malloc(sizeof(record*));

    myFile = fopen("records.csv", "r");
    if(myFile == NULL) {
        fprintf(stderr, "Error: %s", strerror(errno));
        return 0;
    }

    signal(SIGALRM, signalHandler);

    /*=====================================Handle user inputs=======================================*/
    do {
      printf("Please select sorting method:\n\t1) Integers;\n\t2) Float;\n\t3) String\nYour choice (1/2/3):");
      scanf("%d", &insertionModeUser);
    } while(insertionModeUser!=1 && insertionModeUser!=2 && insertionModeUser!=3);

    switch(insertionModeUser) {
      case 1:
        mySortingPreferences.comparePreference = (sortingCompareFunction) compareTwoIntegers;
      break;
      case 2:
        mySortingPreferences.comparePreference = (sortingCompareFunction) compareTwoFloats;
      break;
      case 3:
        mySortingPreferences.comparePreference = (sortingCompareFunction) compareTwoString;
      break;
    }
    alarm(TIME_LIM);

    /*=====================================Reading from file=======================================*/
    printf("Start reading from file...\n");
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
    printf("Read completed...\nStart sorting...\n");

    /*=====================================Sorting array=======================================*/
    start = clock();
    MergeBinaryInsertionSort((void** )myRecord, 0, sizeOfArray-1, mySortingPreferences.comparePreference);
    stop = clock();
    
    /* The CLOCKS_PER_SEC MACRO is defined inside the time.h library */
    duration = ( double ) ( stop - start ) / CLOCKS_PER_SEC;

    printf("Sorting complete in: %.2lf seconds...\nStarting Verification...\n", duration);    

    arrayIsSorted((void**)myRecord, sizeOfArray, mySortingPreferences.comparePreference);

    printf("Verification completed. Array is sorted correctly\n");

    free(myRecord);
    return 0;
}