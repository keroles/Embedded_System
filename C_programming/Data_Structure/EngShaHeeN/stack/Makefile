CC=gcc
CFLAGS=-I.
DEPS = lifo.h stdio.h
OBJ = main.o lifo.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

lifo: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

