all: raycast.o ppmrw.o
	gcc raycast.o ppmrw.o -o raycast

raycast.o: raycast.c raycast.h
	gcc -c raycast.c

ppmrw.o: ppmrw.c ppmrw.h
	gcc -c ppmrw.c

clean:
	rm -rf *.o *.stackdump *.exe 2>/dev/null || true
