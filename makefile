life: life.o start.o future.o draw.o
	gcc life.o start.o future.o draw.o -o life -lncurses -Wall

life.o: life.c life.h
	gcc -c -Wall life.c

start.o: start.c life.h
	gcc -c -Wall start.c

future.o: future.c life.h
	gcc -c -Wall future.c

draw.o: draw.c life.h
	gcc -c -Wall draw.c
	
clean:
	rm *o life