#include "editDistance.h"

//this function returns the ptr to the dictionary. 
//the wto parameters are the path of the dict and a integer var wich will be set to the size of the dictionary
char **loadDictionary(char *fileName, int *dictionaryElements, int *dictMaxSize)
{

  FILE *dictFP;
  char wordTmp[200];
  char **dictionary;
  int i = 0;

  if (fileName == NULL)
  {
    printf("No dictionary available... exiting...\n");
    exit(EXIT_FAILURE);
  }

  dictFP = fopen(fileName, "r");

  if (dictFP == NULL)
  {
    printf("Unable to open file!\n");
    exit(EXIT_FAILURE);
  }

  dictionary = malloc(i * sizeof(char *));
  while (fscanf(dictFP, "%s", wordTmp) != EOF)
  {
    dictionary = realloc(dictionary, (i + 1) * sizeof(void *));
    dictionary[i] = malloc(strlen(wordTmp) + 1);
    strcpy(dictionary[i], wordTmp);
    i++;

    if(strlen(wordTmp) > *dictMaxSize) *dictMaxSize = strlen(wordTmp);
  }

  fclose(dictFP);
  *dictionaryElements = i;
  return dictionary;
}

int main(int argc, char *argv[])
{
    FILE *myFile;
    char myStringInput[200];
    char *myToken;
    char **tokenizedInputFile;
    char **dictionary;
    int tokenizedNumberLines, dictionaryElements, minEditDistance, positionOfMinEditDistance;
    int i, j, tmp;
    int DictMaxSize = 0, correctMeMaxSize = 0;


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

            if(strlen(myToken) > correctMeMaxSize) correctMeMaxSize = strlen(myToken);

            i++;
            myToken = strtok(NULL, SEPARATOR);
            
           
        }
    }

    tokenizedNumberLines = i;

    dictionary = loadDictionary("dictionary.txt", &dictionaryElements, &DictMaxSize);

    

#ifdef noMemoization //solving the problem without memoization.

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