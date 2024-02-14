#include <stdio.h>

int read_file(FILE *file, char *path);
int write_file(FILE *file, char *path);
char make_rot(char ch, int nrot);
int cipher_file(FILE *file, char *filepath, int nrot);
int mess_with_dir(FILE *file, char *filepath);