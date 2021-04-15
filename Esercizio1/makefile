COMPILER=gcc
FLAGS=-I Lib/ 
FLAGSTEST= $(FLAGS) -I UnityTest/

BinarySortMain: Build/main.o Build/MergeBinaryInsertionSort.o
	$(COMPILER) Build/main.o Build/MergeBinaryInsertionSort.o -o Build/BinarySortMainExec
	Build/BinarySortMainExec

Build/MergeBinaryInsertionSort.o: Lib/MergeBinaryInsertionSort.h Lib/MergeBinaryInsertionSort.c
	$(COMPILER) $(FLAGS) -c Lib/MergeBinaryInsertionSort.c -o Build/MergeBinaryInsertionSort.o

Build/main.o: Lib/MergeBinaryInsertionSort.h Src/main.c
	$(COMPILER) $(FLAGS) -c Src/main.c -o Build/main.o

debug: Lib/MergeBinaryInsertionSort.h Lib/MergeBinaryInsertionSort.c Src/main.c
	$(COMPILER) $(FLAGS) -g -c Src/main.c -o Build/main.o
	$(COMPILER) $(FLAGS) -g -c Lib/MergeBinaryInsertionSort.c -o Build/MergeBinaryInsertionSort.o
	$(COMPILER) Build/MergeBinaryInsertionSort.o Build/main.o -o Build/BinarySortMainExec
	gdb Build/BinarySortMainExec

Build/unity.o: UnityTest/unity.c UnityTest/unity.h
	$(COMPILER) $(FLAGSTEST) -c UnityTest/unity.c -o Build/unity.o

unitTest: Lib/MergeBinaryInsertionSort.h Src/unitTest.c Build/MergeBinaryInsertionSort.o Build/unity.o
	$(COMPILER) $(FLAGSTEST) -c Src/unitTest.c -o Build/unitTest.o
	$(COMPILER) Build/MergeBinaryInsertionSort.o Build/unity.o Build/unitTest.o -o Build/BinarySortUnitTest
	Build/BinarySortUnitTest

verbose: Build/MergeBinaryInsertionSort.o
	$(COMPILER) $(FLAGS) -c Src/main.c -o Build/mainVerbose.o -DVERBOSE
	$(COMPILER) Build/mainVerbose.o Build/MergeBinaryInsertionSort.o -o Build/BinarySortMainExecVerbose
	Build/BinarySortMainExecVerbose

clear:
	rm Build/*.o
	rm Build/BinarySortMainExec
	rm FloatSorted.csv IntegerSorted.csv StringSorted.csv 
	