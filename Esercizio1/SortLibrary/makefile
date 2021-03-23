BinarySortMain: BinarySort.o main.o
	gcc BinarySort.o main.o -o BinarySortMainExec
	./BinarySortMainExec

BinarySort.o: BinarySort.h BinarySort.c
	gcc -c BinarySort.c

clear:
	rm *.o
	rm BinarySortMainExec