all: raycast.o ppmrw.o vector.o
	gcc raycast.o ppmrw.o vector.o -o raycast

raycast.o: raycast.c raycast.h
	gcc -c raycast.c

vector.o: vector.c vector.h
	gcc -c vector.c

ppmrw.o: ppmrw.c ppmrw.h
	gcc -c ppmrw.c

clean:
	rm -rf *.o *.stackdump *.exe 2>/dev/null || true
