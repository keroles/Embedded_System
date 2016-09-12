CC=gcc
CFLAGS=-I.
DEPS = fifo.h
OBJ = main.o fifo.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

fifo: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

