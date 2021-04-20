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

clear: 
	rm Build/*.o
	rm Build/exec