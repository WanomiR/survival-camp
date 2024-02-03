/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/
#include <stdio.h>

#define NMAX 10

int input(int *arr, int *n);
void output(int *arr, int n);
int sumNumbers(int *arr, int n);
int findNumbers(int *arr, int n, int num, int *arrNum);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main(void) {
    int rc = 0;
    int n, isRead, sum, evenCount;
    int arr[NMAX], arrNum[NMAX];

    isRead = input(arr, &n);

    if (isRead) {
        sum = sumNumbers(arr, n);
        printf("%d\n", sum);
        evenCount = findNumbers(arr, n, sum, arrNum);
        output(arrNum, evenCount);
    } else {
        rc = -1;
        printf("n/a");
    }

    return rc;
}

int input(int *arr, int *n) {
    char term;
    int rc = 1;
    if (scanf("%d%c", n, &term) != 2 || *n > NMAX || *n <= 0 || term != '\n') rc = 0;

    term = ' ';  // reset the term for the following checks

    int *p = arr;
    do {
        if (scanf("%d%c", p, &term) != 2 || !(term == ' ' || term == '\n') || p - arr >= *n) rc = 0;
        p++;
    } while (rc && term != '\n');

    return rc;
}

void output(int *arr, int n) {
    for (int *p = arr; p - arr < n; p++) {
        printf("%d", *p);
        if (p - arr + 1 < n) printf(" ");
    }
}
/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sumNumbers(int *arr, int n) {
    int sum = 0;
    for (int *p = arr; p - arr < n; p++) {
        if (!(*p % 2)) sum += *p;
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int findNumbers(int *arr, int n, int num, int *arrNum) {
    int *k = arrNum;
    int evenCount = 0;
    for (int *p = arr; p - arr < n; p++) {
        if (*p != 0 && !(num % *p)) {
            *(k + evenCount) = *p;
            evenCount++;
        }
    }
    return evenCount;
}
