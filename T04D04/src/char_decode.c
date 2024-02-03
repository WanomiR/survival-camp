#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int numRead, flag, end;

    numRead = sscanf(argv[1], "%d\n%n", &flag, &end);

    if (numRead != 1 || argv[1][end] != '\0' || !(flag == 1 || flag == 0)) {
        printf("Invalid flag input");
    }

    return 0;
}