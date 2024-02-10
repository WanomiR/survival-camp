#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

#define NMAX 100

int main(int argc, char *argv[]) {
    int w;
    char ch;
    char txt[NMAX];

    if (argc != 2 || (s21_strcmp(argv[1], "-w")) || scanf("%d%c", &w, &ch) != 2 || w > NMAX || w < 1) {
        printf("n/a");
        return 0;
    }

    ch = ' ';  // reset the char
    int cnt = 0;
    while (ch != '\n') {
        scanf("%c", &ch);
        if (cnt > NMAX - 1) {
            printf("n/a");
            return 0;
        }
        if (ch != '\n') {
            txt[cnt] = ch;
            cnt++;
        }
    }

    for (int i = 0; i < cnt; i++) {
        printf("%c", txt[i]);

        if (i > 0 && !(i % w)) {
            printf("\n");
            if (txt[i + 1] == ' ') {
                i++;
                continue;
            }
        }
    }

    return 0;
}