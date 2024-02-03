#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int isRead;

    isRead = input(data, &n);

    if (isRead) {
        squaring(data, n);
        output(data, n);
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
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p *= *p;
    }
}
