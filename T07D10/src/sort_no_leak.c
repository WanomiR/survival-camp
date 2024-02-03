#include <stdio.h>
#include <stdlib.h>

int input(int *A, int n);
void bubbleSort(int *a, int n);
void output(int *a, int n);

int main() {
    int rc = 0;
    int n, isRead;
    char term;
    int *A = 0;

    if (scanf("%d%c", &n, &term) == 2 && n > 0 && term == '\n') {
        A = (int *)calloc(n, sizeof(int));

        if (A != 0) {
            isRead = input(A, n);
            if (isRead) {
                bubbleSort(A, n);
                output(A, n);
            } else {
                rc = -1;
                printf("n/a");
            }
            free(A);
            A = 0;
        }
    } else {
        rc = -1;
        printf("n/a");
    }

    return rc;
}

int input(int *A, int n) {
    char term;
    int rc = 1;
    int *p = A;

    do {
        if (scanf("%d%c", p, &term) != 2 || !(term == ' ' || term == '\n') || p - A >= n) rc = 0;
        p++;
    } while (rc && term != '\n');

    if (p - A < n) rc = 0;

    return rc;
}

void bubbleSort(int *a, int n) {
    int i, tmp;

    for (i = 0; i < n; i++) {
        for (int *p = a; p - a < n - i - 1; p++) {
            if (*p > *(p + 1)) {
                tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a + 1 < n) printf(" ");
    }
}
