#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

void showOptions(void);
int inputParams(int *type, int *n, int *m);
int inputMatrix(int **M, int n, int m);
int arrayOfPointersToArrays(int **M, int n, int m);
int arrayOfPointersToSegments(int **M, int n, int m);
int pointersToSegmentsWithOneBuffer(int **M, int n, int m);
int rowSum(int *A, int m);
void sortMatrix(int **M, int n, int m);
void output(int **M, int n, int m);

int main() {
    int type, n, m;
    int **M = 0;
    int rv = 0;

    showOptions();

    if (inputParams(&type, &n, &m)) {
        switch (type) {
            case 1:
                rv = arrayOfPointersToArrays(M, n, m);
                break;
            case 2:
                rv = arrayOfPointersToSegments(M, n, m);
                break;
            case 3:
                rv = pointersToSegmentsWithOneBuffer(M, n, m);
                break;
        }
    } else {
        rv = -1;
        printf("n/a");
    }

    return rv;
}

void showOptions(void) {
    printf("\nSelect one of the memory allocation types:\n");
    printf("1 --- array of pointers to multiple arrays\n");
    printf("2 ---- array of pointers to array segments\n");
    printf("3 — pointers to segments all in one buffer\n\n");
}

int inputParams(int *type, int *n, int *m) {
    char term;
    int flag = 1;

    if (scanf("%d%c", type, &term) != 2 || term != '\n')
        flag = 0;
    else if (!flag || *type < 1 || *type > 3)
        flag = 0;
    else if (!flag || scanf("%d%c", n, &term) != 2 || term != ' ')
        flag = 0;
    else if (!flag || scanf("%d%c", m, &term) != 2 || term != '\n')
        flag = 0;

    return flag;
}

int inputMatrix(int **A, int n, int m) {
    char ch;
    int flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; flag && j < m; j++) {
            if (scanf("%d%c", &A[i][j], &ch) != 2 || !(ch == ' ' || ch == '\n')) flag = 0;
        }
    }
    return flag;
}

int arrayOfPointersToArrays(int **M, int n, int m) {
    int rv = 0;

    M = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        M[i] = (int *)malloc(m * sizeof(int));
    }

    if (inputMatrix(M, n, m) && M != 0) {
        sortMatrix(M, n, m);
        output(M, n, m);
    } else {
        printf("n/a");
        rv = -1;
    }

    for (int i = 0; i < n; i++) {
        free(M[i]);
        M[i] = 0;
    }
    free(M);
    M = 0;

    return rv;
}

int arrayOfPointersToSegments(int **M, int n, int m) {
    int rv = 0;
    int *a = 0;

    M = (int **)malloc(n * sizeof(int *));
    a = malloc(n * m * sizeof(int));

    for (int i = 0; i < n; i++) {
        M[i] = &a[i * m];
    }

    if (inputMatrix(M, n, m) && M != 0) {
        sortMatrix(M, n, m);
        output(M, n, m);
    } else {
        printf("n/a");
        rv = -1;
    }

    free(M);
    free(a);
    M = 0;
    a = 0;

    return rv;
}

int pointersToSegmentsWithOneBuffer(int **M, int n, int m) {
    int rv = 0;

    M = (int **)malloc(n * sizeof(int *) + n * m * sizeof(int));
    for (int i = 0; i < n; i++) {
        M[i] = (int *)(M + n + i * m);
    }

    if (inputMatrix(M, n, m) && M != 0) {
        sortMatrix(M, n, m);
        output(M, n, m);
    } else {
        printf("n/a");
        rv = -1;
    }
    free(M);
    M = 0;

    return rv;
}

int rowSum(int *A, int m) {
    int sum = 0;
    for (int *p = A; p - A < m; p++) {
        sum += *p;
    }
    return sum;
}

void sortMatrix(int **M, int n, int m) {
    int *tmp[m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (rowSum(M[j], m) > rowSum(M[j + 1], m)) {
                *tmp = M[j];
                M[j] = M[j + 1];
                M[j + 1] = *tmp;
            }
        }
    }
};

void output(int **A, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", A[i][j]);
            if (j < m - 1)
                printf(" ");
            else if (i < n - 1)
                printf("\n");
        }
    }
}