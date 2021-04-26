COMPILER=gcc
FLAGS=-I Lib/
FLAGSTEST= $(FLAGS) -I UnityTest/

#TARGET
editDistance: Build/editDistance.o Build/main.o
	$(COMPILER) Build/editDistance.o Build/main.o -o Build/exec
	Build/exec

Build/editDistance.o: Lib/editDistance.c Lib/editDistance.h
	$(COMPILER) $(FLAGS) -c Lib/editDistance.c -o Build/editDistance.o

Build/main.o: Src/main.c Lib/editDistance.h
	$(COMPILER) $(FLAGS) -c Src/main.c -o Build/main.o

debug: Lib/editDistance.h Lib/editDistance.c Src/main.c
	$(COMPILER) $(FLAGS) -g -c Src/main.c -o Build/main.o
	$(COMPILER) $(FLAGS) -g -c Lib/editDistance.c -o Build/editDistance.o
	$(COMPILER) Build/editDistance.o Build/main.o -o Build/editDistance
	gdb Build/editDistance

Build/unity.o: UnityTest/unity.c UnityTest/unity.h
	$(COMPILER) $(FLAGSTEST) -c UnityTest/unity.c -o Build/unity.o

unitTest: Lib/editDistance.h Src/unitTest.c Build/editDistance.o Build/unity.o
	$(COMPILER) $(FLAGSTEST) -c Src/unitTest.c -o Build/unitTest.o
	$(COMPILER) Build/editDistance.o Build/unity.o Build/unitTest.o -o Build/EditDistanceUnitTest
	Build/EditDistanceUnitTest
 
clear: 
	rm Build/*.o
	rm Build/exec
