#include "MergeBinaryInsertionSort.h"


#define MAX_LEN 128

int sizeOfArray;

void freeElements(void** myArrayOfRecords, int size) {
    while(size > 0){
        free(myArrayOfRecords[size]);
        size--;
    } 
};

int main(int argc, char* argv[]) {
    record** myRecord = (record**) malloc(sizeof(record*));
    FILE* myFile = fopen("records.csv", "r");
    if(myFile == NULL) {
        fprintf(stderr, "Error: %s", strerror(errno));
        return 0;
    }
    int line = 0;
    char stringInFile[MAX_LEN];
    int id;
    int secondNumber;
    float thirdNumber;    
    while(line != 200 && fscanf(myFile, "%d,%[^,],%d,%f\n", &id, stringInFile, &secondNumber, &thirdNumber) != EOF) {
        record* singleElement = (record*) malloc(sizeof(record));
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
    int i;
    BinaryInsertionSort((void** )myRecord, 1, sizeOfArray-1);
    for(i = 1; i < sizeOfArray-1; i++) {
        if(myRecord[i]->numberInt > myRecord[i+1]->numberInt ) {
            fprintf(stderr, "NON E' ORDINATO");
            exit(EXIT_FAILURE);
        }
    }
    fprintf(stderr, "Ordinato");
    freeElements((void**) myRecord, sizeOfArray-1);
    free(myRecord);

    return 0;
}