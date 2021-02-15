#PhotoLab Makefile 

all: PhotoLab_v2 PhotoLabTest

clean: 
	rm -f *.o 
	rm -f PhotoLab_v2 
	rm -f PhotoLabTest

#PhotoLabTest target 
PhotoLabTest: PhotoLabTest.o libFilter.a FileIO.o 		 
	gcc PhotoLabTest.o FileIO.o DIPs.o Advanced.o -g -L. -lFilter -o PhotoLabTest -lm -DDEBUG 

#PhotoLab_v2 target 
PhotoLab_v2: PhotoLab_v2.o FileIO.o libFilter.a			
	gcc PhotoLab_v2.o DIPs.o FileIO.o Advanced.o -Wall -lm -ansi -std=c99 -o PhotoLab_v2

PhotoLabTest.o: PhotoLab_v2.c FileIO.h Advanced.h DIPs.h Constants.h  
	gcc PhotoLab_v2.c -Wall -ansi -std=c99 -c -o PhotoLabTest.o -DDEBUG

PhotoLab_v2.o: PhotoLab_v2.c FileIO.h DIPs.h Constants.h 
	gcc PhotoLab_v2.c -Wall -ansi -std=c99 -c -o PhotoLab_v2.o

Advanced.o: Advanced.c Advanced.h Constants.h
	gcc Advanced.c -Wall -ansi -std=c99 -c -o Advanced.o

DIPs.o: DIPs.c DIPs.h Constants.h 
	gcc DIPs.c -Wall -ansi -std=c99 -c -o DIPs.o

FileIO.o: FileIO.c FileIO.h Constants.h  
	gcc FileIO.c -Wall -ansi -std=c99 -c -o FileIO.o 

libFilter.a: DIPs.o Advanced.o 
	ar rc libFilter.a DIPs.o Advanced.o 
	ranlib libFilter.a 


