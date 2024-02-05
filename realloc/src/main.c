/*
read unlimited input size
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *array = NULL;
    int *newArray = NULL;
    int size = 0;      // current array size
    int capacity = 0;  // number of elements the array can store
    int num;

    while (scanf("%d", &num) == 1 && num != -1) {
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            newArray = realloc(array, capacity * sizeof(int));

            if (newArray == NULL) {
                fprintf(stderr, "Memory allocation failure\n");
                free(array);
                exit(EXIT_FAILURE);
            }
            array = newArray;
        }

        array[size] = num;
        size++;
    }

    // print elements of the resulting array
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    free(array);

    return 0;
}