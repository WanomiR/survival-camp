#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int ***result);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int ***result);
void allocate_memory(int ***matrix, int n, int m);
int input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);
void sort_array(int *array, int n, int asc);
void transpose_matrix(int **matr1, int **matr2, int n, int m);

int main() {
    int **matrix = NULL;
    int **result = NULL;
    int n, m;

    if (input(&matrix, &n, &m)) {
        allocate_memory(&result, n, m);
        sort_vertical(matrix, n, m, &result);
        output(result, n, m);
        printf("\n\n");
        sort_horizontal(matrix, n, m, &result);
        output(result, n, m);
    } else {
        printf("n/a");
    }

    for (int i = n; i < n; i++) {
        free(matrix[i]);
        free(result[i]);
    }
    free(matrix);
    free(result);


    return 0;
}
void sort_vertical(int **matrix, int n, int m, int ***result) {
    int T[n * m], r[n];
    int asc = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            T[m * i + j] = matrix[i][j];
        }
    }

    sort_array(T, n * m, 1);

    for (int j = 0; j < m; j++) {
        asc = j % 2 == 0;
        for (int i = 0; i < n; i++) {
            r[i] = T[n * j + i];
        }
        sort_array(r, n, asc); 
        for (int i = 0; i < n; i++) {
            (*result)[i][j] = r[i];
        }
    }
}

void sort_horizontal(int **matrix, int n, int m, int ***result) {
    int T[n * m], r[n];
    int asc = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            T[m * i + j] = matrix[i][j];
        }
    }

    sort_array(T, n * m, 1);

    for (int i = 0; i < n; i++) {
        asc = i % 2 == 0;
        for (int j = 0; j < m; j++) {
            r[j] = T[m * i + j];
        }
        sort_array(r, m, asc); 
        for (int j = 0; j < m; j++) {
            (*result)[i][j] = r[j];
        }
    }
}

void allocate_memory(int ***matrix, int n, int m) {
    *matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*matrix)[i] = (int *)malloc(m * sizeof(int));
    }
};

int input(int ***matrix, int *n, int *m) {
    char term;
    int flag = 1;

    if (scanf("%d%c", n, &term) != 2 || term != ' ')
        flag = 0;
    else if (!flag || scanf("%d%c", m, &term) != 2 || term != '\n')
        flag = 0;

    if (flag) allocate_memory(matrix, *n, *m);

    if (flag && *matrix != NULL) {
        for (int i = 0; i < *n; i++) {
            for (int j = 0; flag && j < *m; j++) {
                if (scanf("%d%c", &(*matrix)[i][j], &term) != 2 || !(term == ' ' || term == '\n')) flag = 0;
            }
        }
    }
    return flag;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j < m - 1)
                printf(" ");
            else if (i < n - 1)
                printf("\n");
        }
    }
}

void sort_array(int *array, int n, int asc) {
    int tmp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (asc) {
                if (array[j] > array[j + 1]) {
                    tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            } else {
                if (array[j] < array[j + 1]) {
                    tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
        }
    }
};

void transpose_matrix(int **matr1, int **matr2, int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matr2[i][j] = matr1[j][i];
        }
    }
}