CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD=../build/

door_struct: dmanager_module.o
	$(CC) $(CFLAGS) dmanager_module.o -o $(BUILD)Quest_1

dmanager_module.o: dmanager_module.c
	$(CC) $(CFLAGS) -c dmanager_module.c

clean:
	rm -rf *.o ../build/*