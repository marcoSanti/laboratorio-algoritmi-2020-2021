#include "editDistance.h"



int main(int argc, char *argv[])
{
    FILE *myFile;
    char myStringInput[200];
    char *myToken;
    char **tokenizedInputFile;
    char **dictionary;
    int i = 0, tokenizedNumberLines, dictionaryElements, j, minEditDistance = INT_MAX, positionOfMinEditDistance =0, tmp;

    myFile = fopen("correctme.txt", "r");
    if (myFile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    tokenizedInputFile=malloc(i*sizeof(char *));
    while (fscanf(myFile, "%s\n", myStringInput) != EOF)
    {
        myToken = strtok(myStringInput, SEPARATOR);
        while (myToken != NULL)
        {
            tokenizedInputFile = realloc(tokenizedInputFile, (i + 1) * sizeof(char *));
            tokenizedInputFile[i] = malloc(strlen(myToken)+1);
            strcpy(tokenizedInputFile[i], myToken);
            i++;
            myToken = strtok(NULL, SEPARATOR);
        }
    }

    tokenizedNumberLines = i;

    dictionary = loadDictionary("dictionary.txt", &dictionaryElements);

    for(i=0;i<tokenizedNumberLines;i++){ //scorro le parole dentro il file da correggere
        minEditDistance = INT_MAX;
        for(j=0;j<dictionaryElements;j++){
            tmp = edit_distance(tokenizedInputFile[i], dictionary[j]);
            if(tmp<minEditDistance){
                minEditDistance = tmp;
                positionOfMinEditDistance = j;
            }
        }
        if(minEditDistance != 0){
            printf("Word %s is probably wrong... Did you mean %s?\n", tokenizedInputFile[i], dictionary[positionOfMinEditDistance]);
        }else{
            printf("Word %s is correct.\n", tokenizedInputFile[i]);
        }
    }

    return 0;
}