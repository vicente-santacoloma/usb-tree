CC=gcc
CFLAGS=-I.
DEPS = Arbol.h Lista.h
OBJ = Main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Main: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
