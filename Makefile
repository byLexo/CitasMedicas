CC=gcc
CFLAGS=-I.
DEPS = 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#hellomake: hellomake.o hellofunc.o 
#	$(CC) -o hellomake hellomake.o hellofunc.o

main: main.o
	$(CC) -o main main.o

.PHONY: clean

clean:
	rm -f *.o
