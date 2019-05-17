CC     = gcc
AR     = ar rcs
RANLIB = ranlib
OBJ    = src/matarith.o 

all: lib test

lib: $(OBJ)
	$(AR)     libmatarith.a $^
	$(RANLIB) libmatarith.a

*.o: *.c
	$(CC) -c $< -o $@

test: libmatarith.a
	gcc -o t3st -L./ test/test_add.c -lmatarith

clean:
	rm -f *.o *.a
