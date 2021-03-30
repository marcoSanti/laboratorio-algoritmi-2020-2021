#include "MergeBinaryInsertionSort.h"


#define MAX_LEN 128
//data structure to store a single element of the input file
/* 
    Declaring global scope variables
 */
typedef struct {
    int id;
    char* string;
    int numberInt;
    float numberFloat;
} record;

int sizeOfArray;

int compareInt(record* firstRecord, record* secondRecord) {
    return firstRecord->numberInt - secondRecord->numberInt;
};

void printElement(record* record, int conta) {
    fprintf(stdout, "%d-%d\n", record->numberInt, conta);
};

void freeElements(void** myArrayOfRecords, int size) {
    while(size > 0){
        free(myArrayOfRecords[size]);
        size--;
    } 
};

int main(int argc, char* argv[]) {
    record** myRecord = (record**) malloc(sizeof(record*));
    fprintf(stderr, "DONE with allocating memory\n");
    FILE* myFile = fopen("records.csv", "r");
    if(myFile == NULL) {
        fprintf(stderr, "Error: %s", strerror(errno));
        return 0;
    }
    fprintf(stderr, "DONE with opening file\n");
    int line = 0;
    char stringInFile[MAX_LEN];
    int id;
    int secondNumber;
    float thirdNumber;    
    while(fscanf(myFile, "%d,%[^,],%d,%f\n", &id, stringInFile, &secondNumber, &thirdNumber) != EOF) {
        record* singleElement = (record*) malloc(sizeof(record));
        singleElement->id = id;
        singleElement->string = strndup(stringInFile, MAX_LEN);
        singleElement->numberInt = secondNumber;
        singleElement->numberFloat = thirdNumber;
        line++;        
        myRecord = (record**) realloc(myRecord, sizeof(record*)*line);
        myRecord[line-1] = singleElement;
    } 
    sizeOfArray = line;
    fclose(myFile);
    // for(int p = 0; p < sizeOfArray; p++) {
    //     printElement(myRecord[p], p);
    // }
    MergeBinaryInsertionSort((void **) myRecord, 0, sizeOfArray-1);
    freeElements((void**) myRecord, sizeOfArray);
    return 0;
}