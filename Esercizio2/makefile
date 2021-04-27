COMPILER=gcc
FLAGS=-I Lib/
FLAGSTEST= $(FLAGS) -I UnityTest/

#TARGET
editDistance: Build/EditDistance.o Build/Main.o
	$(COMPILER) Build/EditDistance.o Build/Main.o -o Build/EditDistance
	Build/EditDistance

Build/EditDistance.o: Lib/EditDistance.c Lib/editDistance.h
	$(COMPILER) $(FLAGS) -c Lib/editDistance.c -o Build/EditDistance.o

Build/Main.o: Src/main.c Lib/editDistance.h
	$(COMPILER) $(FLAGS) -c Src/main.c -o Build/Main.o

debug: Lib/editDistance.h Lib/editDistance.c Src/main.c
	$(COMPILER) $(FLAGS) -g -c Src/main.c -o Build/Main.o
	$(COMPILER) $(FLAGS) -g -c Lib/editDistance.c -o Build/EditDistance.o
	$(COMPILER) Build/EditDistance.o Build/Main.o -o Build/EditDistance
	gdb Build/EditDistance

Build/unity.o: UnityTest/unity.c UnityTest/unity.h
	$(COMPILER) $(FLAGSTEST) -c UnityTest/unity.c -o Build/unity.o

unitTest: Lib/editDistance.h Src/unitTest.c Build/EditDistance.o Build/unity.o
	$(COMPILER) $(FLAGSTEST) -c Src/unitTest.c -o Build/UnitTest.o
	$(COMPILER) Build/EditDistance.o Build/unity.o Build/UnitTest.o -o Build/EditDistanceUnitTest
	Build/EditDistanceUnitTest
 
clear: 
	rm Build/*.o
	rm Build/E*
