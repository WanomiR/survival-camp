#include <stdio.h>
#include <math.h>

void print_x(double x);
void print_agnesi(double x);
void print_hyperbolic(double x);
void print_bernoulli(double x);


int main() {

  double pi = 3.141592653589793238462643383279502884197;

  for (double k = -pi; k <= pi; k += pi * 2 / 41) {

    print_x(k);
    print_agnesi(k);
    print_bernoulli(k);
    print_hyperbolic(k);

  }
  
  return 0;
}


void print_x(double x) {
  printf("%.7f | ", x);
}


void print_agnesi(double x) {
  double y = 1 / (1 + pow(x, 2));
  printf("%.7f | ", y);
}


void print_bernoulli(double x) {
  double y = sqrt( sqrt(1 + 4 * pow(x, 2)) - pow(x, 2) - 1);
  if (isnan(y)){
    printf(" - |");
  } else {
    printf("%.7f | ", y);
  }
}


void print_hyperbolic(double x) {
  double y = 1 / pow(x, 2);
  if ((x < 1e-6) && (x > -1e-6)) {
    printf(" - \n");
  } else {
    printf("%.7f\n", y);
  }
}

