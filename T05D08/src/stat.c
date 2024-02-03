#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int isRead;

    isRead = input(data, &n);

    if (isRead) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    } else {
        printf("n/a");
    }

    return 0;
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

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a + 1 < n) printf(" ");
    }
    printf("\n");
}

int max(int *a, int n) {
    int max = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > max) max = *p;
    }
    return max;
}

int min(int *a, int n) {
    int min = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < min) min = *p;
    }
    return min;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %0.6f %0.6f", max_v, min_v, mean_v, variance_v);
}
