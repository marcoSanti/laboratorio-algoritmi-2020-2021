#include "editDistance.h"

int edit_distance(char* s1, char* s2) {
    int noOp, canc, insert;

    if(strlen(s1) == 0 || strlen(s2) == 0) {
        return strlen(s1) + strlen(s2);
    }

    if(s1[0] == s2[0]) {
        noOp = edit_distance(s1+1, s2+1);
    } else {
        noOp = INT_MAX;
    }

    canc = edit_distance(s1, s2+1) + 1;
    insert = edit_distance(s1 + 1, s2) + 1;

    return MIN(noOp, MIN(canc, insert));
}

int edit_distance_dyn(char* s1, char* s2){
    return 0;
}




char** loadDictionary(char *fileName, int *dictionaryElements){

    FILE *dictFP;
    char wordTmp[200];
    char **dictionary;
    int i=0;
    
    if(fileName == NULL){
        printf("No dictionary available... exiting...\n");
        exit(EXIT_FAILURE);
    }

    dictFP = fopen(fileName, "r");

    if(dictFP == NULL){
        printf("Unable to open file!\n");
        exit(EXIT_FAILURE);
    }

    dictionary = malloc(i*sizeof(char *));
    while(fscanf(dictFP, "%s", wordTmp ) != EOF){
        dictionary = realloc(dictionary, (i+1)*sizeof(void *));
        dictionary[i] = malloc(strlen(wordTmp));
        strcpy(dictionary[i], wordTmp);
        i++;
    }
    
    fclose(dictFP);
    *dictionaryElements = i;
    return dictionary;
}


