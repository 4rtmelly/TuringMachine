CC = gcc

projet :	main.o fonction.o pro.h
	$(CC)	-o	projet main.o fonction.o

main.o :	main.c pro.h
	$(CC)	-c main.c pro.h

fonction.o :	fonction.c pro.h
	$(CC)	-c fonction.c pro.h

