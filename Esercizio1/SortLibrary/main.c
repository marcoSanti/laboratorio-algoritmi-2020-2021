#include "MergeBinaryInsertionSort.h"

#define MAX_LEN 128
#define TIME_LIM 600

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
  int i, intSortedElements=0;

  for(i = 0; i < size-1; i++) {
        if(mySortingCompareFunction(array[i], array[i+1]) > 0) {
            fprintf(stderr, "\n================\nNOT SORTED\n================\n");
            exit(EXIT_FAILURE);
        }
        intSortedElements++;
    }
}
 
int compareTwoString(record* firstRecord, record* secondRecord){
  return strcmp(firstRecord -> string, secondRecord -> string); 
}

int compareTwoFloats(record* firstRecord, record* secondRecord){
  if(firstRecord->numberFloat <= secondRecord->numberFloat){
    return 0;
  } else {
    return 1;
  }
}

int compareTwoIntegers(record* firstRecord, record* secondRecord){  
  return firstRecord->numberInt - secondRecord->numberInt;
}

void signalHandler(int signal) {
  switch(signal) {
    case SIGALRM:
      fprintf(stderr, "mmm...Time's up, pack your things, we are leaving\n");
      exit(EXIT_FAILURE);
    break;
  }
}

int main(int argc, char* argv[]) {
    int insertionModeUser, sizeOfArray;
    int line = 0, id, i;
    double duration; 
    clock_t start, stop;
    char stringInFile[MAX_LEN];
    int secondNumber;
    float thirdNumber;
    record** myRecord = (record**) malloc(sizeof(record*));
    sortingPreferences mySortingPreferences;
    record* singleElement; 
    FILE* myFile = fopen("records.csv", "r");
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
    while(line != 8000000 && fscanf(myFile, "%d,%[^,],%d,%f\n", &id, stringInFile, &secondNumber, &thirdNumber) != EOF) {
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
    printf("Sorting complete...\nStarting Verification...\n");    
    arrayIsSorted((void**)myRecord, sizeOfArray, mySortingPreferences.comparePreference);
    /* The CLOCKS_PER_SEC MACRO is defined inside the time.h library */
    duration = ( double ) ( stop - start ) / CLOCKS_PER_SEC;
    fprintf(stdout, "Sorting completed in: %.2lf\n", duration);
    free(myRecord);
    return 0;
}