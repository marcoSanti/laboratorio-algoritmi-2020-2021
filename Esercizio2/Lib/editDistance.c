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