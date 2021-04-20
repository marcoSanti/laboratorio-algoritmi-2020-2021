#include "unity.h"
#include "MergeBinaryInsertionSort.h"
#define MAX_LEN 128

void setUp(void) {}
void tearDown(void) {}

/*
  The following method compares two integer and return the difference between the two numbers
*/
int compareTwoIntegers(int *firstRecord, int *secondRecord)
{
  return *firstRecord - *secondRecord;
}

int *addNewElement(int elem)
{
  int *result = (int *)malloc(sizeof(int));
  *result = elem;

  return result;
}

static void arrayWithZeroElementInsertion()
{
  int **array = NULL;
  BinaryInsertionSort((void **)array, 0, 0, (sortingCompareFunction)compareTwoIntegers);
  TEST_ASSERT_EQUAL(NULL, array);
}

static void arrayWithZeroElementMerge()
{
  int **array = NULL;
  MergeBinaryInsertionSort((void **)array, 0, 0, (sortingCompareFunction)compareTwoIntegers);
  TEST_ASSERT_EQUAL(NULL, array);
}

static void arrayWithOneElementInsertion()
{
  int **array = (int **)malloc(sizeof(int *) * 1);
  array[0] = addNewElement(2);
  BinaryInsertionSort((void **)array, 0, 0, (sortingCompareFunction)compareTwoIntegers);
  TEST_ASSERT_EQUAL(2, *array[0]);
}

static void arrayWithOneElementMerge()
{
  int **array = (int **)malloc(sizeof(int *) * 1);
  array[0] = addNewElement(2);
  MergeBinaryInsertionSort((void **)array, 0, 0, (sortingCompareFunction)compareTwoIntegers);
  TEST_ASSERT_EQUAL(2, *array[0]);
}

static void arrayWithOrderedElementsInsertion()
{
  int **array = (int **)malloc(sizeof(int *) * 4);
  array[0] = addNewElement(3);
  array[1] = addNewElement(4);
  array[2] = addNewElement(5);
  array[3] = addNewElement(6);
  BinaryInsertionSort((void **)array, 0, 3, (sortingCompareFunction)compareTwoIntegers);
  TEST_ASSERT_EQUAL(3, *array[0]);
  TEST_ASSERT_EQUAL(4, *array[1]);
  TEST_ASSERT_EQUAL(5, *array[2]);
  TEST_ASSERT_EQUAL(6, *array[3]);
}

static void arrayWithUnorderedElementsInsertion()
{
  int **array = (int **)malloc(sizeof(int *) * 4);
  array[0] = addNewElement(6);
  array[1] = addNewElement(2);
  array[2] = addNewElement(5);
  array[3] = addNewElement(3);
  BinaryInsertionSort((void **)array, 0, 3, (sortingCompareFunction)compareTwoIntegers);
  TEST_ASSERT_EQUAL(2, *array[0]);
  TEST_ASSERT_EQUAL(3, *array[1]);
  TEST_ASSERT_EQUAL(5, *array[2]);
  TEST_ASSERT_EQUAL(6, *array[3]);
}

static void arrayWithUnorderedElementsMerge()
{
  int **array = (int **)malloc(sizeof(int *) * 4);
  array[0] = addNewElement(10);
  array[1] = addNewElement(2);
  array[2] = addNewElement(5);
  array[3] = addNewElement(3);
  MergeBinaryInsertionSort((void **)array, 0, 3, (sortingCompareFunction)compareTwoIntegers);
  TEST_ASSERT_EQUAL(2, *array[0]);
  TEST_ASSERT_EQUAL(3, *array[1]);
  TEST_ASSERT_EQUAL(5, *array[2]);
  TEST_ASSERT_EQUAL(10, *array[3]);
}

static void arrayWithOrderedElementsMerge()
{
  int **array = (int **)malloc(sizeof(int *) * 4);
  array[0] = addNewElement(3);
  array[1] = addNewElement(4);
  array[2] = addNewElement(5);
  array[3] = addNewElement(6);
  MergeBinaryInsertionSort((void **)array, 0, 3, (sortingCompareFunction)compareTwoIntegers);
  TEST_ASSERT_EQUAL(3, *array[0]);
  TEST_ASSERT_EQUAL(4, *array[1]);
  TEST_ASSERT_EQUAL(5, *array[2]);
  TEST_ASSERT_EQUAL(6, *array[3]);
}

int main(int argc, char *argv[])
{

  UNITY_BEGIN();
  RUN_TEST(arrayWithZeroElementInsertion);
  RUN_TEST(arrayWithZeroElementMerge);
  RUN_TEST(arrayWithOneElementInsertion);
  RUN_TEST(arrayWithOneElementMerge);
  RUN_TEST(arrayWithOrderedElementsInsertion);
  RUN_TEST(arrayWithOrderedElementsMerge);
  RUN_TEST(arrayWithUnorderedElementsInsertion);
  RUN_TEST(arrayWithUnorderedElementsMerge);

  return 0;
}