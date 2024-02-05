/*
Notes:
- Professional Cmake, Craig Scott
- Out-Of-Source Builds files structure
- `cmake --help` to see available generators (*... — default generator)
*/
#include <stdio.h>

#include "my_lib.h"

int main(int argc, char *argv[]) {
    printf("foo(5) = %d\n", foo(5));
    return 0;
}