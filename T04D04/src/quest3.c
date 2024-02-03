#include <stdio.h>

long fibonacci(int n);

int main(void) {

    float n;
    int numRead;
    long long result;

    numRead = scanf("%f", &n);

    if ((numRead != 1) || ((int)n != n)) {
      printf("n/a\n");
      return -1;
    }

    result = fibonacci(n);
    printf("%lld\n", result);

    return result;
}

long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}