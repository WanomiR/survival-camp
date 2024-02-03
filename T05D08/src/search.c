#include <math.h>
#include <stdio.h>

#define NMAX 30
/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int isFitsCriteria(int *a, int n);

int main() {
    int n, data[NMAX];
    int isRead, result;
    int rc = 0;

    isRead = input(data, &n);

    if (isRead) {
        result = isFitsCriteria(data, n);
        if (result) {
            printf("%d", result);

        } else {
            printf("%d", 0);
        }
    } else {
        printf("n/a");
        rc = -1;
    }

    return rc;
}

int input(int *a, int *n) {
    char term;
    int rc = 1;
    if (scanf("%d%c", n, &term) != 2 || *n > NMAX || *n <= 0 || term != '\n') rc = 0;

    term = ' ';

    int *p = a;
    do {
        if (scanf("%d%c", p, &term) != 2 || !(term == ' ' || term == '\n') || p - a >= *n) rc = 0;
        p++;
    } while (rc && term != '\n');

    return rc;
}

double mean(int *a, int n) {
    double accum = 0;
    for (int *p = a; p - a < n; p++) {
        accum += *p;
    }
    return accum / n;
}

double variance(int *a, int n) {
    double var = 0;
    for (int *p = a; p - a < n; p++) {
        var += pow((*p) - mean(a, n), 2) / n;
    }
    return var;
}

int isFitsCriteria(int *a, int n) {
    double sigma = sqrt(variance(a, n));
    double expected = mean(a, n);
    int rc = 0;

    for (int *x = a; x - a < n; x++) {
        if (!(*x % 2) && *x >= expected && *x <= expected + 3 * sigma && *x != 0) {
            rc = *x;
        }
    }
    return rc;
}