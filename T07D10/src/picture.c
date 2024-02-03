#include "stdio.h"
#include "stdlib.h"

#define N 15
#define M 13

void transform(int (*buf)[M], int **matr);
void reset_picture(int **picture, int n, int m);
void make_picture(int **picture, int n, int m);
void make_vertical_lines(int **picture, int *frame_h);
void make_tree_foliage(int **picutre, int *frame_w);
void make_tree_trunk(int **picture, int *tree_trunk);
void make_sun(int **picture, int (*sun_data)[5]);
void make_horizonal_lines(int **picture, int *frame_w);
void draw_picture(int **picture, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];

    transform(picture_data, picture);
    make_picture(picture, N, M);
    draw_picture(picture, N, M);

    return 0;
}

void transform(int (*buf)[M], int **matr) {
    for (int i = 0; i < N; i++) {
        matr[i] = buf[i];
    }
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    make_vertical_lines(picture, frame_h);
    make_tree_foliage(picture, tree_foliage);
    make_tree_trunk(picture, tree_trunk);
    make_sun(picture, sun_data);
    make_horizonal_lines(picture, frame_w);
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void make_vertical_lines(int **picture, int *frame_h) {
    int n = N;
    for (int i = 0; i < n; i++) {
        picture[i][0] = frame_h[i];
        picture[i][6] = frame_h[i];
        picture[i][12] = frame_h[i];
    }
}

void make_tree_foliage(int **picture, int *tree_foliage) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            picture[3 + i][2 + j] = tree_foliage[i];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            picture[2 + i][3 + j] = tree_foliage[i];
        }
    }
}

void make_tree_trunk(int **picture, int *tree_trunk) {
    for (int i = 0; i < 4; i++) {
        picture[10][2 + i] = tree_trunk[i];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            picture[6 + i][3 + j] = tree_trunk[i];
        }
    }
}

void make_sun(int **picture, int (*sun_data)[5]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            picture[1 + i][7 + j] = sun_data[i][j];
        }
    }
}
void make_horizonal_lines(int **picture, int *frame_w) {
    int m = M;
    for (int j = 0; j < m; j++) {
        picture[0][j] = frame_w[j];
        picture[7][j] = frame_w[j];
        picture[14][j] = frame_w[j];
    }
}

void draw_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", picture[i][j]);
            if (j < m - 1)
                printf(" ");
            else if (i < n - 1)
                printf("\n");
        }
    }
}