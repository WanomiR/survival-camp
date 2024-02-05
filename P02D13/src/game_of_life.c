#include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define N 25
#define M 80
#define C 35

void selectMode(int *mode);
void readFromFile(char *filepath, char (*a)[M]);
void clearScreen(void);
void drawScreen(char (*a)[M], int time);
void process(char (*a)[M], char (*b)[M]);
void swap(char (*here)[M], char (*from)[M]);
void newScreen(char (*a)[M]);
int neighbours(char (*a)[M], int i, int j);

int main(void) {
    char screen[N][M];
    char *fname;
    int mode = 10;
    int time = 64, click = 0;
    selectMode(&mode);

    switch (mode) {
        case '1':
            fname = "datasets/pulsar.txt";
            break;
        case '2':
            fname = "datasets/glider.txt";
            break;
        case '3':
            fname = "datasets/gosper-glider-gun.txt";
            break;
        case '4':
            fname = "datasets/simkin-glider-gun.txt";
            break;
        case '5':
            fname = "datasets/r-pentomino.txt";
            break;
    }

    readFromFile(fname, screen);

    fcntl(0, F_GETFL);
    struct termios raw;
    tcgetattr(0, &raw);
    raw.c_lflag &= ~(ICANON);
    tcsetattr(0, TCSAFLUSH, &raw);
    while (1 && mode != 'q') {
        usleep(10000);
        fcntl(0, F_SETFL, O_NONBLOCK);
        mode = getchar();
        fcntl(0, F_SETFL, O_APPEND);
        if ((mode == '+') && (time > 4)) {
            time /= 2;
        } else if ((mode == '-') && (time < 1024)) {
            time *= 2;
        }
        click++;
        if (click >= time) {
            newScreen(screen);
            drawScreen(screen, time);
            click = 0;
        }
    }
    return 0;
}

void selectMode(int *mode) {
    char input = '1';
    printf(
        "Select initial status:\n1 - pulsar\n2 - glider\n3 - gosper-glider-gun\n4 - simkin-glider-gun\n5 - "
        "r-pentomino\nInput only "
        "numbers, please.\n");
    while (input == '1') {
        *mode = getchar();
        if ((*mode > 53) || (*mode < 49) || (getchar() != 10)) {
            printf("Incorrect input, try again.\n");
            while (*mode != 10) {
                *mode = getchar();
            }
        } else {
            input = '0';
        }
    }
}

void readFromFile(char *filepath, char (*a)[M]) {
    FILE *file;
    int i = 0;
    file = fopen(filepath, "r");
    while (fgets(a[i], M, file)) i++;
    fclose(file);
};

void clearScreen(void) { printf("\033[H\033[J"); }

void drawScreen(char (*a)[M], int time) {
    clearScreen();
    printf("Control keys:\n");
    printf("+ --> increase speed\n");
    printf("- --> decrease speed\n");
    printf("q --> stop the program\n\n");

    printf("Simulation speed: %.f%%\n", 6400. / time);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}

void process(char (*a)[M], char (*b)[M]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (a[i][j] == C) {
                if (!(neighbours(a, i, j) == 2 || neighbours(a, i, j) == 3)) {
                    b[i][j] = ' ';
                    continue;
                } else {
                    b[i][j] = C;
                }
            } else if (a[i][j] == ' ' && neighbours(a, i, j) == 3) {
                b[i][j] = C;
            } else {
                b[i][j] = ' ';
            }
        }
    }
}

void swap(char (*here)[M], char (*from)[M]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            here[i][j] = from[i][j];
        }
    }
}
void newScreen(char (*a)[M]) {
    char temp[N][M];
    process(a, temp);
    swap(a, temp);
}

int neighbours(char (*a)[M], int i, int j) {
    int cnt = 0;
    int l, c;
    for (int k = -1; k <= 1; k++) {
        for (int m = -1; m <= 1; m++) {
            // skip when over current cell
            if ((k == 0) && (m == 0)) m++;

            if (i + k == -1) {
                l = 24;
            } else if (i + k == 25) {
                l = 0;
            } else {
                l = i + k;
            }

            if (j + m == -1) {
                c = 79;
            } else if (j + m == 80) {
                c = 0;
            } else {
                c = j + m;
            }
            if (a[l][c] == C) cnt++;
        }
    }
    return cnt;
};
