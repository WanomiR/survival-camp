CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD=../build/

cipher: cipher.o
	$(CC) $(CFLAGS) cipher.o -o $(BUILD)cipher

cipher.o: cipher.c cipher.h
	$(CC) $(CFLAGS) -c cipher.c

clean:
	rm -rf *.o ../build/*