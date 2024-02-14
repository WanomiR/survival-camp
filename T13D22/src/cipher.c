#include "cipher.h"

#include <ctype.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 512

int main(void) {
    FILE *file = NULL;
    char *filepath = (char *)malloc(sizeof(char) * MAX_SIZE);
    int mode = 0;
    int rv = 1;
    while (mode != -1) {
        if (scanf("%d", &mode) == 1 && (mode == -1 || mode == 1 || mode == 2 || mode == 3)) {
            if (mode == 1) {
                rv = read_file(file, filepath);
            } else if (mode == 2) {
                rv = write_file(file, filepath);
            } else if (mode == 3) {
                rv = mess_with_dir(file, filepath);
            }
        } else {
            rv = !rv;
        }
        if (!rv) {
            printf("n/a\n");
            rv = !rv;
        }
    }
    free(filepath);
    return 0;
}

int read_file(FILE *file, char *path) {
    int flag = 1;
    scanf("%255s", path);
    file = fopen(path, "rt");
    if (file != NULL) {
        char string[MAX_SIZE];
        while (fgets(string, sizeof(string), file)) {
            printf("%s", string);
        }
        fclose(file);
        printf("\n");
    } else {
        flag = 0;
    }
    return flag;
}

int write_file(FILE *file, char *path) {
    int flag = 1;
    if (strlen(path) > 0) {
        char string[MAX_SIZE];
        getchar();
        fgets(string, sizeof(string), stdin);
        if (string[strlen(string) - 1] == '\n') string[strlen(string) - 1] = '\0';
        file = fopen(path, "r+");
        if (file != NULL) {
            fseek(file, 0, SEEK_END);
            long pos = ftell(file);                   // determine the end of the line
            if (pos != 0) fprintf(file, "%c", '\n');  // add new line character
            fprintf(file, "%s", string);              // insert your line
            rewind(file);                             // rewind and print the resulting file
            while (fgets(string, sizeof(string), file)) {
                printf("%s", string);
            }
            fclose(file);
            printf("\n");
        } else {
            flag = 0;
        }
    } else {
        flag = 0;
    }
    return flag;
}

char make_rot(char ch, int nrot) {
    if (ch >= 32 && ch <= 126) {
        int range = 94;
        int c = (int)ch - 32;

        int shift = nrot % range;

        if (c + shift > range) {
            c += shift - range;
        } else {
            c += shift;
        }

        if (c < 0) c = range + c + 1;
        ch = (char)(c + 32);
    }

    return ch;
}

int cipher_file(FILE *file, char *filepath, int nrot) {
    int flag = 1;
    char *buffer;
    file = fopen(filepath, "rt");

    if (file != NULL) {
        buffer = (char *)malloc(sizeof(char));
        int cnt = 0;
        int c;
        while ((c = fgetc(file)) != EOF) {
            char *tmp = realloc(buffer, sizeof(char) * (cnt + 1));
            tmp[cnt] = make_rot((char)c, nrot);
            buffer = tmp;
            cnt++;
        }
        fclose(file);
        fopen(filepath, "w");
        fputs(buffer, file);
        fclose(file);
        free(buffer);
    } else {
        flag = 0;
    }
    return flag;
}

int mess_with_dir(FILE *file, char *filepath) {
    int flag = 1;
    DIR *directory;
    char *dirpath = (char *)malloc(sizeof(char) * MAX_SIZE);
    int nrot;
    scanf("%s", dirpath);
    scanf("%d", &nrot);
    if (nrot < 0) flag = 0;
    printf("%s\n", dirpath);

    directory = opendir(dirpath);
    for (; flag && directory;) {
        struct dirent *dir;
        char filename[MAX_SIZE];
        unsigned len;
        char file_extension;

        dir = readdir(directory);
        if (!dir) break;

        strcpy(filename, dir->d_name);
        len = strlen(filename);
        file_extension = filename[len - 1];

        strcpy(filepath, dirpath);
        strcat(filepath, "/");
        strcat(filepath, filename);

        if (file_extension == 'c') {
            flag = cipher_file(file, filepath, nrot);
        } else if (file_extension == 'h') {
            fclose(fopen(filepath, "w"));
        }
    }
    closedir(directory);
    free(dirpath);
    return flag;
}