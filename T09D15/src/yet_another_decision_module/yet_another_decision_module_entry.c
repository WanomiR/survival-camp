#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    double *data;
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        printf("n/a");
        return 1;
    }

    data = (double *)malloc(sizeof(double) * n);

    input(data, n);

    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");

    free(data);

    return 0;
}
