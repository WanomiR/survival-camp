#include <stdio.h>

#define NMAX 10

int input(int *A, int *n, int *c);
void output(int *A, int n);
void cycleShift(int *A, int *B, int n, int c);

int main(void) {
    int n, c, isRead, A[NMAX], B[NMAX];
    int rc = 0;

    isRead = input(A, &n, &c);

    if (isRead) {
        cycleShift(A, B, n, c);
        output(B, n);
    } else {
        printf("n/a");
        rc = -1;
    }

    return rc;
}

int input(int *A, int *n, int *c) {
    char term;
    int rc = 1;

    if (scanf("%d%c", n, &term) != 2 || *n > NMAX || *n <= 0 || term != '\n') rc = 0;

    term = ' ';

    int *p = A;
    do {
        if (scanf("%d%c", p, &term) != 2 || !(term == ' ' || term == '\n') || p - A > *n - 1) rc = 0;
        p++;
    } while (rc && term != '\n');

    if (p - A < *n) rc = 0;

    if (scanf("%d%c", c, &term) != 2 || term != '\n') rc = 0;

    return rc;
}

void output(int *A, int n) {
    for (int *p = A; p - A < n; p++) {
        printf("%d", *p);
        if (p - A + 1 < n) printf(" ");
    }
}

void cycleShift(int *A, int *B, int n, int c) {
    if (c > 0) {
        for (int i = 0; i < n; i++) {
            B[i] = A[(i + c) % n];
        }
    } else {
        for (int i = 0; i < n; i++) {
            B[(i - c) % n] = A[i];
        }
    }
}