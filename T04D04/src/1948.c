#include <stdio.h>
#include <math.h>

int is_divisor(int a, int b);
int is_prime(int p);
int get_biggest_prime_divisor(int x);

int main(void) {

  float input;
  int x, numRead, result;

  numRead = scanf("%f", &input);

  if ((numRead != 1) || ((int)input != input)) {
    printf("n/a\n");
    return -1;
  }

  x = (int)input;

  if (x < 0) {
    x = x * -1;
  }

  result = get_biggest_prime_divisor(x);

  if (result == 0) {
    printf("n/a\n");
  } else {
    printf("%d\n", result);
  }
  return 0;
}


int is_divisor(int a, int b) {
  while (a >= b) {
    a -= b;
    if (a == 0) return 1;
  }
  return 0;
}


int is_prime(int a) {
  for (int i = 2; i < sqrt(a) + 1; i++) {
    if (is_divisor(a, i) || (a < 2)) return 0;
  }
  return 1;
}



int get_biggest_prime_divisor(int x) {
  for (int i = x - 1; i > 1; i--) {
    if (is_divisor(x, i) && is_prime(i)) return i;
  }
  return 0;
}
