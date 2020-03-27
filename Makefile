all: display.o  filestolist.o  function.o inout.o  ListSearch.o  ListSort.o  listtofile.o  main.o add.o update.o
	gcc display.c  filestolist.c  function.c inout.c  ListSearch.c  ListSort.c  listtofile.c  main.c add.c update.c -o main

clean:
	rm *.o 
