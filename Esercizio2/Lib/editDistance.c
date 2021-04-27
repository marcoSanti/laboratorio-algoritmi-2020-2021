#include "editDistance.h"

int edit_distance_dyn(char* str1, char*str2){
  memset(memoizationHelpMatrix, -1, sizeof memoizationHelpMatrix);
  return _edit_distance_dyn(str1, str2, strlen(str1), strlen(str2));
}

int _edit_distance_dyn(char * str1, char * str2, int strlen1, int strlen2) {
  int insert, canc, noOp;

  //control to not overflow the space of memoizationHelpMatrix
  if (strlen1 > 50 || strlen2 > 50) {
    printf("Warning: not enough space to use memoization! Skipping word...\n");
    return INT_MAX;
  }

  if (strlen1 == 0 || strlen2 == 0)
    return strlen1 + strlen2;

  //looking for already calculated distance
  if (memoizationHelpMatrix[strlen1 - 1][strlen2 - 1] != -1)
    return memoizationHelpMatrix[strlen1 - 1][strlen2 - 1];

  if (str1[0] == str2[0]) {
    noOp = _edit_distance_dyn(str1 + 1, str2 + 1, strlen1 - 1, strlen2 - 1);
  } else {
    noOp = INT_MAX;
  }

  insert = _edit_distance_dyn(str1 + 1, str2, strlen1 - 1, strlen2) + 1;
  canc = _edit_distance_dyn(str1, str2 + 1, strlen1, strlen2 - 1) + 1;

  return memoizationHelpMatrix[strlen1 - 1][strlen2 - 1] = MIN(insert, MIN(noOp, canc));
}

int edit_distance(char * s1, char * s2) {
  int noOp, canc, insert;

  if (strlen(s1) == 0 || strlen(s2) == 0) {
    return strlen(s1) + strlen(s2);
  }

  if (s1[0] == s2[0]) {
    noOp = edit_distance(s1 + 1, s2 + 1);
  } else {
    noOp = INT_MAX;
  }

  canc = edit_distance(s1, s2 + 1) + 1;
  insert = edit_distance(s1 + 1, s2) + 1;

  return MIN(noOp, MIN(canc, insert));
}

char ** loadDictionary(char * fileName, int * dictionaryElements) {

  FILE * dictFP;
  char wordTmp[200];
  char ** dictionary;
  int i = 0;

  if (fileName == NULL) {
    printf("No dictionary available... exiting...\n");
    exit(EXIT_FAILURE);
  }

  dictFP = fopen(fileName, "r");

  if (dictFP == NULL) {
    printf("Unable to open file!\n");
    exit(EXIT_FAILURE);
  }

  dictionary = malloc(i * sizeof(char * ));
  while (fscanf(dictFP, "%s", wordTmp) != EOF) {
    dictionary = realloc(dictionary, (i + 1) * sizeof(void * ));
    dictionary[i] = malloc(strlen(wordTmp) + 1);
    strcpy(dictionary[i], wordTmp);
    i++;
  }

  fclose(dictFP);
  * dictionaryElements = i;
  return dictionary;
}