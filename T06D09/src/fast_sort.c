#include <stdio.h>

int input(int *arr1, int *arr2, int n);
void swap(int *a, int *b);
void quickSort(int *a, int low, int high);
void heapify(int *arr, int n, int i);
void heapSort(int *arr, int n);
void output(int *a, int n);

int main() {
    int rc = 0;
    int n = 10;
    int dataQuick[n], dataHeap[n];
    int isRead;

    isRead = input(dataQuick, dataHeap, n);

    if (isRead) {
        quickSort(dataQuick, 0, n - 1);
        output(dataQuick, n);
        printf("\n");
        heapSort(dataHeap, n);
        output(dataHeap, n);
    } else {
        rc = -1;
        printf("n/a");
    }

    return rc;
}

int input(int *arr1, int *arr2, int n) {
    char term = ' ';
    int rc = 1;

    int *p = arr1;
    int *k = arr2;
    do {
        if (scanf("%d%c", p, &term) != 2 || !(term == ' ' || term == '\n') || p - arr1 >= n) rc = 0;
        *k = *p;
        k++;
        p++;
    } while (rc && term != '\n');

    if (p - arr1 != n) rc = 0;

    return rc;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = arr[(low + high) / 2];
        int i = low;
        int j = high;

        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;

            if (i <= j) {
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        }

        if (low < j) quickSort(arr, low, j);
        if (i < high) quickSort(arr, i, high);
    }
}

void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;

    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a + 1 < n) printf(" ");
    }
}
