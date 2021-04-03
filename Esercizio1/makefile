COMPILER=gcc
FLAGS=-I Headers/ 
FLAGSTEST= $(FLAGS) -I UnityTest/

BinarySortMain: Build/main.o Build/MergeBinaryInsertionSort.o
	$(COMPILER) Build/main.o Build/MergeBinaryInsertionSort.o -o Build/BinarySortMainExec
	Build/BinarySortMainExec

Build/MergeBinaryInsertionSort.o: Headers/MergeBinaryInsertionSort.h SortLibrary/MergeBinaryInsertionSort.c
	$(COMPILER) $(FLAGS) -c SortLibrary/MergeBinaryInsertionSort.c -o Build/MergeBinaryInsertionSort.o

Build/main.o: Headers/MergeBinaryInsertionSort.h SortLibrary/main.c
	$(COMPILER) $(FLAGS) -c SortLibrary/main.c -o Build/main.o

debug: Headers/MergeBinaryInsertionSort.h SortLibrary/MergeBinaryInsertionSort.c SortLibrary/main.c
	$(COMPILER) $(FLAGS) -g -c SortLibrary/main.c -o Build/main.o
	$(COMPILER) $(FLAGS) -g -c SortLibrary/MergeBinaryInsertionSort.c -o Build/MergeBinaryInsertionSort.o
	$(COMPILER) Build/MergeBinaryInsertionSort.o Build/main.o -o Build/BinarySortMainExec
	gdb Build/BinarySortMainExec

UnityTest/unity.o: UnityTest/unity.c UnityTest/unity.h
	$(COMPILER) $(FLAGSTEST) -c UnityTest/unity.c -o Build/unity.o

unitTest: Headers/MergeBinaryInsertionSort.h SortLibrary/unitTest.c Build/MergeBinaryInsertionSort.o UnityTest/unity.o
	$(COMPILER) $(FLAGSTEST) -c SortLibrary/unitTest.c -o Build/unitTest.o
	$(COMPILER) Build/MergeBinaryInsertionSort.o Build/unity.o Build/unitTest.o -o Build/BinarySortUnitTest
	Build/BinarySortUnitTest

clear:
	rm Build/*.o
	rm Build/BinarySortMainExec
	