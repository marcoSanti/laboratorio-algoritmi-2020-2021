#include "editDistance.h"

int main(int argc, char* argv[]) {
    FILE *myFile;
    char myStringInput[200];
    const char mySeparationChar[4] = "\0";
    char *myToken;

    myFile = fopen("correctme.txt", "r");
    if(myFile == NULL) {
        exit(EXIT_FAILURE);
    }

    while( fscanf(myFile, "%[^,]\n", myStringInput) != EOF) {
        myToken = strtok(myStringInput, mySeparationChar);
        
            fprintf(stderr, " %s\n", myToken);

            myToken = strtok(NULL, mySeparationChar);        
    }
    return 0;
}