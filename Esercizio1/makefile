COMPILER=gcc
FLAGS=-I Headers/ 
FLAGSTEST= $(FLAGS) -I UnityTest/

BinarySortMain: Build/BinarySort.o Build/main.o
	$(COMPILER) Build/BinarySort.o Build/main.o -o Build/BinarySortMainExec
	Build/BinarySortMainExec

Build/BinarySort.o: Headers/BinarySort.h SortLibrary/BinarySort.c
	$(COMPILER) $(FLAGS) -c SortLibrary/BinarySort.c -o Build/BinarySort.o

Build/main.o: Headers/BinarySort.h SortLibrary/main.c
	$(COMPILER) $(FLAGS) -c SortLibrary/main.c -o Build/main.o

debug: Headers/BinarySort.h SortLibrary/BinarySort.c SortLibrary/main.c
	$(COMPILER) $(FLAGS) -g -c SortLibrary/main.c -o Build/main.o
	$(COMPILER) $(FLAGS) -g -c SortLibrary/BinarySort.c -o Build/BinarySort.o
	$(COMPILER) Build/BinarySort.o Build/main.o -o Build/BinarySortMainExec
	gdb Build/BinarySortMainExec

UnityTest/unity.o: UnityTest/unity.c UnityTest/unity.h
	$(COMPILER) $(FLAGSTEST) -c UnityTest/unity.c -o UnityTest/unity.o

unitTest: Headers/BinarySort.h SortLibrary/unitTest.c Build/BinarySort.o UnityTest/unity.o
	$(COMPILER) $(FLAGSTEST) -c SortLibrary/unitTest.c -o Build/unitTest.o
	$(COMPILER) Build/BinarySort.o Build/unitTest.o UnityTest/unity.o -o Build/BinarySortUnitTest
	Build/BinarySortUnitTest

clear:
	rm Build/*.o
	rm Build/BinarySortMainExec
	