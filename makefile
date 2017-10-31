all: main.o
	gcc -o runo main.o

main.o: main.c
	gcc -c main.c

run: all
	./runo

clean:
	rm -rf *.o *~ runo debugo

debug: main.c
	gcc -o debugo -g main.c

valgrind: debug
	valgrind --leak-check=yes ./debugo

gdb: debug
	gdb ./debugo
