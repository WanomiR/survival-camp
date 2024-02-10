#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    double *data;
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        printf("n/a");
        return 1;
    }

    data = (double *)malloc(sizeof(double) * n);

    input(data, n);

    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR");

    free(data);

    return 0;
}
