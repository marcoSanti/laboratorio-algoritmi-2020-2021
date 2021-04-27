#include "editDistance.h"

int main(int argc, char *argv[])
{
    /*  
        Variables declaration   
    */
    FILE *myFile;
    char myStringInput[200];
    char *myToken;
    char **tokenizedInputFile;
    char **dictionary;
    int tokenizedNumberLines, dictionaryElements, minEditDistance, positionOfMinEditDistance;
    int i, j, tmp;

    i = 0;
    minEditDistance = INT_MAX;
    positionOfMinEditDistance = 0;

    myFile = fopen("correctme.txt", "r");
    if (myFile == NULL)
    {
        printf("Unable to open source file to correct.\n");
        exit(EXIT_FAILURE);
    }
    /*
        File opened: success.
        Read from the file and create tokens using the text inside the file.
        "Hello world" will create two tokens: 1) Hello 2) world.
        tokenIzedInputFile is initialized at 0 so that we can use the realloc funtion.
        tokenizedInputFile is a double pointer array. Every element of the array is a pointer to a string, 
        this sring is out token.
    */
    tokenizedInputFile = malloc(i * sizeof(char *));
    while (fscanf(myFile, "%s\n", myStringInput) != EOF)
    {
        myToken = strtok(myStringInput, SEPARATOR);
        while (myToken != NULL)
        {
            tokenizedInputFile = realloc(tokenizedInputFile, (i + 1) * sizeof(char *));
            tokenizedInputFile[i] = malloc(strlen(myToken) + 1);

            /*
                Get rid of the uppercased letters.
            */
            if (myToken[0] >= 65 && myToken[0] <= 90)
            {
                myToken[0] = myToken[0] + 32;
            }

            strcpy(tokenizedInputFile[i], myToken);
            i++;
            myToken = strtok(NULL, SEPARATOR);
        }
    }

    tokenizedNumberLines = i;

    dictionary = loadDictionary("dictionary.txt", &dictionaryElements);

#ifdef noMemoization
    /*
        Solve the problem without memoisation. 
        In this case we don't use a matrix.
    */
    for (i = 0; i < tokenizedNumberLines; i++)
    {
        minEditDistance = INT_MAX;
        for (j = 0; j < dictionaryElements; j++)
        {
            tmp = edit_distance(tokenizedInputFile[i], dictionary[j]);
            if (tmp < minEditDistance)
            {
                minEditDistance = tmp;
                positionOfMinEditDistance = j;
            }
        }
        if (minEditDistance != 0)
        {
            printf("Word %s is probably wrong... Did you mean %s?\n", tokenizedInputFile[i], dictionary[positionOfMinEditDistance]);
        }
        else
        {
            printf("Word %s is correct.\n", tokenizedInputFile[i]);
        }
    }
#else
    /*
        In order to support the memoisation method to solve the problem we need a matrix that will be used
        to store the progressive results while comparing two strings.
    */
    for (i = 0; i < tokenizedNumberLines; i++)
    {
        minEditDistance = INT_MAX;
        for (j = 0; j < dictionaryElements; j++)
        {

            tmp = edit_distance_dyn(tokenizedInputFile[i], dictionary[j]);

            if (tmp < minEditDistance)
            {
                minEditDistance = tmp;
                positionOfMinEditDistance = j;
            }
            /*
                if minEditDistance is zero it means that my two words are equal, otherwise the loop
                goes on and the algorithm keeps searching for the edit distance.
            */
            if (minEditDistance == 0)
                break;
        }
        if (minEditDistance != 0)
        {
            printf("Word %10s is probably wrong... Did you mean %s (editDistance=%d)?\n", tokenizedInputFile[i], dictionary[positionOfMinEditDistance], minEditDistance);
        }
        else
        {
            printf("Word %10s is correct.\n", tokenizedInputFile[i]);
        }
    }
#endif
    return 0;
}