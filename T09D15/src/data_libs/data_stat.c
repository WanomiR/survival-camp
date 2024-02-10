#ifndef DATA_STAT_C
#define DATA_STAT_C

#include <math.h>

double max(double const *data, int n) {
    double max = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > max) max = data[i];
    }
    return max;
}

double min(double const *data, int n) {
    double min = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < min) min = data[i];
    }
    return min;
}

double mean(double const *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

double variance(double *data, int n) {
    double sum = 0;
    double m = mean(data, n);
    for (int i = 0; i < n; i++) {
        sum += pow(data[i] - m, 2);
    }
    return sum / n;
}

#endif