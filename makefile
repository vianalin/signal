all: sig.o
	gcc -o sig sig.o
sig.o: sig.c
	gcc -c sig.c
run: sig
	./sig
clean:
	rm *.o
	rm sig
