#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

void showOptions(void);
int inputParams(int *type, int *n, int *m);
int inputMatrix(int **M, int n, int m);
void staticAllocation(int n, int m);
void arrayOfPointersToArrays(int **M, int n, int m);
void arrayOfPointersToSegments(int **M, int n, int m);
void pointersToSegmentsWithOneBuffer(int **M, int n, int m);
void output(int **M, int n, int m);
void outputRowMaxs(int **M, int n, int m);
void outputColumnMins(int **M, int n, int m);

int main() {
    int type, n, m;
    int **M = 0;

    showOptions();

    if (inputParams(&type, &n, &m)) {
        switch (type) {
            case 1:
                staticAllocation(n, m);
                break;
            case 2:
                arrayOfPointersToArrays(M, n, m);
                break;
            case 3:
                arrayOfPointersToSegments(M, n, m);
                break;
            case 4:
                pointersToSegmentsWithOneBuffer(M, n, m);
                break;
        }
    } else {
        printf("n/a");
    }

    return 0;
}

void showOptions(void) {
    printf("\nSelect one of the memory allocation types:\n");
    printf("1 -------------------------- static memory\n");
    printf("2 --- array of pointers to multiple arrays\n");
    printf("3 ---- array of pointers to array segments\n");
    printf("4 — pointers to segments all in one buffer\n\n");
}

int inputParams(int *type, int *n, int *m) {
    char term;
    int flag = 1;

    if (scanf("%d%c", type, &term) != 2 || term != '\n')
        flag = 0;
    else if (!flag || *type < 1 || *type > 4)
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

void staticAllocation(int n, int m) {
    int A[n * m];
    int *a[n];

    if (n <= 100 && m <= 100) {
        for (int i = 0; i < n; i++) {
            a[i] = &A[i * n];
        }

        if (inputMatrix(a, n, m)) {
            output(a, n, m);
            outputRowMaxs(a, n, m);
            outputColumnMins(a, n, m);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}

void arrayOfPointersToArrays(int **M, int n, int m) {
    M = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        M[i] = (int *)malloc(m * sizeof(int));
    }

    if (inputMatrix(M, n, m) && M != 0) {
        output(M, n, m);
        outputRowMaxs(M, n, m);
        outputColumnMins(M, n, m);
    } else {
        printf("n/a");
    }
    free(M);
}

void arrayOfPointersToSegments(int **M, int n, int m) {
    M = (int **)malloc(n * sizeof(int *));
    int *a = malloc(n * m * sizeof(int));

    for (int i = 0; i < n; i++) {
        M[i] = &a[i * m];
    }

    if (inputMatrix(M, n, m) && M != 0) {
        output(M, n, m);
        outputRowMaxs(M, n, m);
        outputColumnMins(M, n, m);
    } else {
        printf("n/a");
    }

    free(M);
    free(a);
}

void pointersToSegmentsWithOneBuffer(int **M, int n, int m) {
    M = (int **)malloc(n * sizeof(int *) + n * m * sizeof(int));
    for (int i = 0; i < n; i++) {
        M[i] = (int *)(M + n + i * m);
    }

    if (inputMatrix(M, n, m) && M != 0) {
        output(M, n, m);
        outputRowMaxs(M, n, m);
        outputColumnMins(M, n, m);
    } else {
        printf("n/a");
    }
    free(M);
}

void output(int **A, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", A[i][j]);
            if (j < m - 1)
                printf(" ");
            else if (i < n)
                printf("\n");
        }
    }
}

void outputRowMaxs(int **M, int n, int m) {
    int maxValue;

    for (int i = 0; i < n; i++) {
        maxValue = M[i][0];
        for (int j = 1; j < m; j++) {
            if (M[i][j] > maxValue) maxValue = M[i][j];
        }
        printf("%d", maxValue);
        if (i < n - 1)
            printf(" ");
        else if (i < n)
            printf("\n");
    }
}

void outputColumnMins(int **M, int n, int m) {
    int minValue;

    for (int j = 0; j < n; j++) {
        minValue = M[0][j];
        for (int i = 0; i < m; i++) {
            if (M[i][j] < minValue) minValue = M[i][j];
        }
        printf("%d", minValue);
        if (j < m - 1) printf(" ");
    }
}
