CC=gcc
CFLAGS= -I. -lsqlite3
DEPS = sistema.h menus.h
OBJ = main.o sistema.o menus.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#hellomake: hellomake.o hellofunc.o 
#	$(CC) -o hellomake hellomake.o hellofunc.o

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o
