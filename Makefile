CC=gcc
CFLAGS=-I.
DEPS = sistema.h
OBJ = main.o sistema.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#hellomake: hellomake.o hellofunc.o 
#	$(CC) -o hellomake hellomake.o hellofunc.o

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o
