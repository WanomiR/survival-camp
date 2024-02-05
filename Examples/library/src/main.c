#include <stdio.h>

#include "library.h"

int main(void) {
    printf("%d + %d = %d\n", 4, 5, add(4, 5));
    printf("%d - %d = %d\n", 10, 7, sub(10, 7));
    return 0;
}

/*
compile with:
gcc -o main.c library.c

note: the order doesn't matter
*/