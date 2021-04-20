#include "editDistance.h"

#define SEPARATOR " ,.:;-_\n"

int main(int argc, char *argv[])
{
    FILE *myFile;
    char myStringInput[200];
    char *myToken;
    char **tokenizedInputFile;
    char **dictionary;
    int i = 0, tokenizedNumberLines, dictionaryElements;

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

    for(i=0;i<tokenizedNumberLines;i++){
        printf("%s\n", tokenizedInputFile[i]);
    }

    dictionary = loadDictionary("dictionary.txt", &dictionaryElements);

    printf("We have %d elements in dict\n", dictionaryElements);

    return 0;
}