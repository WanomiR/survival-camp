#include <stdio.h>

int input(int *a, int n);
void bubbleSort(int *a, int n);
void output(int *a, int n);

int main() {
    int rc = 0;
    int n = 10;
    int data[n];
    int isRead;

    isRead = input(data, n);

    if (isRead) {
        bubbleSort(data, n);
        output(data, n);
    } else {
        rc = -1;
        printf("n/a");
    }

    return rc;
}

int input(int *a, int n) {
    char term = ' ';
    int rc = 1;

    int *p = a;
    do {
        if (scanf("%d%c", p, &term) != 2 || !(term == ' ' || term == '\n') || p - a >= n) rc = 0;
        p++;
    } while (rc && term != '\n');

    if (p - a != n) rc = 0;

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
