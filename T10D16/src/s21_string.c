#include <stdlib.h>

unsigned int s21_strlen(const char *str) {
    int len = 0;
    for (; *(str + len); len++)
        ;
    return len;
};

int s21_strcmp(char *str1, char *str2) {
    int result;

    for (; *str1 && *str1 == *str2; str1++, str2++)
        ;
    result = *str1 - *str2;

    if (result > 0) {
        result = 1;
    } else if (result < 0) {
        result = -1;
    }

    return result;
}

char *s21_strcpy(char *dest, const char *src) {
    char *tmp = dest;
    while ((*dest++ = *src++))
        ;
    return tmp;
}

char *s21_strcat(char *dest, char const *src) {
    char *tmp = dest;
    while (*dest) dest++;
    while ((*dest++ = *src++))
        ;
    return tmp;
}

char *s21_strchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == c) return (char *)str;
        str++;
    }
    return NULL;
}

char *s21_strstr(char *str, char *substr) {
    char *a, *b;

    b = substr;
    if (*b == 0) {
        return str;
    }
    for (; *str != 0; str++) {
        if (*str != *b) {
            continue;
        }
        a = str;
        while (1) {
            if (*b == 0) {
                return str;
            }
            if (*a++ != *b++) {
                break;
            }
        }
        b = substr;
    }
    return NULL;
}

char *s21_strtok(char *s, const char *delim) {
    char *spanp;
    int c, sc;
    char *tok;
    static char *last;

    if (s == NULL && (s = last) == NULL) return (NULL);

    c = *s++;
    for (spanp = (char *)delim; (sc = *spanp++) != 0;) {
        if (c == sc) break;
    }

    if (c == 0) { /* no non-delimiter characters */
        last = NULL;
        return (NULL);
    }
    tok = s - 1;

    for (;;) {
        c = *s++;
        spanp = (char *)delim;
        do {
            if ((sc = *spanp++) == c) {
                if (c == 0)
                    s = NULL;
                else
                    s[-1] = 0;
                last = s;
                return (tok);
            }
        } while (sc != 0);
    }
}