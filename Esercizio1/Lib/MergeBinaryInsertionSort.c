#include "MergeBinaryInsertionSort.h"

/*
    This method proceed to merge two Sub arrays into a single array.
    Be aware that this is done by using two support arrays wich could cause some swapping if your system is low on memory.
    The parameters are: 
        -array: a pointer to the array in wich the sub arrays should be taken
        -l: the begin index of the first sub array to be merged
        -m : the mid point wich both function as last index for the first sub array and the begon index for the second sub array
        -r : the upper bound of the second sub array to be sorted
        -mySortingCompareFunction:  This is a pointer to the comparing function to be used into the method
    BE AWARE THAT THIS FUNCTION IS ONLY MEANT TO BE CALLED BY THE MergeBinaryInsertionSort METHOD
*/
void Merge(void **array, register int l, register int m, register int r, sortingCompareFunction mySortingCompareFunction)
{

    register int n1 = m - l + 1;
    register int n2 = r - m;
    register int i = 0, j = 0, k = l;

    void **arrayLeft = malloc(n1 * sizeof(void *));
    void **arrayRight = malloc(n2 * sizeof(void *));

    if (arrayLeft == NULL || arrayRight == NULL)
    {
        printf("Unable to allocate memory for support array.\nExiting now...\n");
        exit(EXIT_FAILURE);
    }

    memcpy(arrayLeft, array + l, n1 * sizeof(void *));
    memcpy(arrayRight, array + m + 1, n2 * sizeof(void *));

    while (i < n1 && j < n2)
    {
        if (mySortingCompareFunction(arrayLeft[i], arrayRight[j]) <= 0)
        {
            array[k] = arrayLeft[i];
            ++i;
        }
        else
        {
            array[k] = arrayRight[j];
            ++j;
        }
        ++k;
    }

    /*
        Here we are copying the support array to the main array.
        We are doing this with a memcpy in orfer to achieve this trough a single operation with O(1) instead of
        a while loop that will be O(n).

        The (n-i) part is present in order to do the copy only if i is lower than Ni otherwise if they are equal, 
        no action will happen because a memcopy will be done on 0 bytes.

        There is no need to update k value as only one memcpy will happen because the upper loop will have exited either
        because n1-i = 0 or because n2-j equals 0!
    */
    memcpy(array + k, arrayLeft + i, (n1 - i) * sizeof(void *));
    memcpy(array + k, arrayRight + j, (n2 - j) * sizeof(void *));

    free(arrayLeft);
    free(arrayRight);
};

/*
    This method returns the position in wich the new element shall be inserted by using the binary dicotomic search algoritm.
    Parameters are: 
        -array: a pointer to the array in wich the sub arrays should be taken
        -x the element that needs to be inserte
        -i : the beggining index of the array 
        -j : the end of the array to be sorted
        -mySortingCompareFunction:  This is a pointer to the comparing function to be used into the method
    BE AWARE THAT THIS FUNCTION IS ONLY MEANT TO BE CALLED BY THE MergeBinaryInsertionSort METHOD
*/
int BinarySearchPosition(void **array, void *x, register int l, register int r, sortingCompareFunction mySortingCompareFunction)
{
    register int m;
    while (l <= r)
    {
        m = (l + r) >> 1;
        if (mySortingCompareFunction(x, array[m]) <= 0)
        {
            --r;
        }
        else
        {
            ++l;
        }
    }
    return l;
};

/*
    This method implements an insertion sort algorithm with a binary search for the position in wich to insert the new element
    The parameter are:
        -array: a pointer to the array in wich the sub arrays should be taken
        -l : the beggining index of the array 
        -r : the end of the array to be sorted
        -mySortingCompareFunction:  This is a pointer to the comparing function to be used into the method
    BE AWARE THAT THIS FUNCTION IS ONLY MEANT TO BE CALLED BY THE MergeBinaryInsertionSort METHOD
*/
void BinaryInsertionSort(void **array, int l, int r, sortingCompareFunction mySortingCompareFunction)
{
    register int i, position, k;

    for (i = l + 1; i <= r; i++)
    {
        void *tmp = (void *)array[i];
        position = BinarySearchPosition(array, tmp, l, i, mySortingCompareFunction);
        for (k = i; k > position; k--)
        {
            array[k] = array[k - 1];
        }

        array[position] = tmp;
    }
};



void MergeBinaryInsertionSort(void **array, register int l, register int r, sortingCompareFunction mySortingCompareFunction)
{
    if (l >= r)
        return;
    if (array == NULL)
        return;

    register int m = (r + l) >> 1;

    if (r - l < K)
    {
        BinaryInsertionSort(array, l, r, mySortingCompareFunction);
    }
    else
    {
        MergeBinaryInsertionSort(array, l, m, mySortingCompareFunction);
        MergeBinaryInsertionSort(array, m + 1, r, mySortingCompareFunction);
        Merge(array, l, m, r, mySortingCompareFunction);
    }
}