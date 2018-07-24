#My own makefile for ML lab 1

#Declare variables
CC=g++
LIBS=-lm

#First create ".exe" called kmeans
kmeans: Lab1-Kmeans.o
	$(CC) Lab1-Kmeans.o -o kmeans $(LIBS)

#Need to make Audio.o file though
Lab1-Kmeans.o: Lab1-Kmeans.cpp
	$(CC) -c Lab1-Kmeans.cpp


#Other rules

#Clean .o and exe
clean:
	@rm -f *.o
	@rm -f kmeans

#To run program
run:
	./kmeans
