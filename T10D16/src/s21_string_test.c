#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test(const char *str, int expected_len);
void s21_strcmp_test(char *str1, char *str2, int expected_result);
void s21_strcpy_test(char *str);
void s21_strcat_test(char *dest, char const *src);
void s21_strchr_test(char *str, int ch, char *expected_result);
void s21_strstr_test(char *haystack, char *needle, char *expected_result);
void s21_strtok_test(char *str, char *del, int expected_number);

int main() {
#ifdef STRLEN
    s21_strlen_test("Just a string", 13);
    s21_strlen_test("", 0);
    s21_strlen_test("000000", 6);
    s21_strlen_test("String\nwith a new line", 22);
    s21_strlen_test("String with\ttabulation", 22);
    s21_strlen_test("String that ends with a blank space ", 36);
#endif

#ifdef STRCMP
    s21_strcmp_test("abcd", "abCd", 1);
    s21_strcmp_test("abCd", "abcd", -1);
    s21_strcmp_test("abcd", "abcd", 0);
    s21_strcmp_test("", "abcd", -1);
    s21_strcmp_test("", "", 0);
#endif

#ifdef STRCPY
    s21_strcpy_test("string2copy");
    s21_strcpy_test("another\tstring\tto\tcopy");
    s21_strcpy_test("tricky\nstring\nto\ncopy");
    s21_strcpy_test("");
    s21_strcpy_test("00001111010102220");
#endif

#ifdef STRCAT
    char dest1[50] = "Here is a string";
    char src1[] = ", and this is its continuation";
    s21_strcat_test(dest1, src1);
    char dest2[50] = "It is another string";
    char src2[] = "\nthat continues with a new line";
    s21_strcat_test(dest2, src2);
    char dest3[50] = "Tabulation is\t";
    char src3[] = "in the middle of this string";
    s21_strcat_test(dest3, src3);
#endif

#ifdef STRCHR
    s21_strchr_test("String to test", ' ', " to test");
    s21_strchr_test("This line has 0 as its start", '0', "0 as its start");
    s21_strchr_test("Slice this line\tby the tab character", '\t', "\tby the tab character");
    s21_strchr_test("12345054321", '0', "054321");
#endif

#ifdef STRSTR
    s21_strstr_test("Here is the text to find a string", "to", "to find a string");
    s21_strstr_test("Find this word and slice from it", "word", "word and slice from it");
    s21_strstr_test("Use a bunch of 000 to slice from", "000", "000 to slice from");
    s21_strstr_test("Use combination of \t\t to make a slice", "\t\t", "\t\t to make a slice");
#endif

#ifdef STRTOK
    char s1[] = "This is the way";
    s21_strtok_test(s1, " ", 4);
    char s2[] = "Comma,separated,values";
    s21_strtok_test(s2, ",", 3);
    char s3[] = "Zero0seprated0values";
    s21_strtok_test(s3, "0", 3);
    char s4[] = "This\tis\ta\tsentence\twhere\twords\tare\tseparated\tby\ttabs";
    s21_strtok_test(s4, "\t", 10);

#endif

    return 0;
}

void s21_strlen_test(const char *str, int expected_len) {
    int len = s21_strlen(str);

    printf("%s\n", str);
    printf("%d\n", len);
    if (len == expected_len) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcmp_test(char *str1, char *str2, int expected_result) {
    int result = s21_strcmp(str1, str2);

    printf("%s", str1);
    printf(" %s\n", str2);
    printf(" %d\n", result);

    if (result == expected_result) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcpy_test(char *str) {
    char newStr[s21_strlen(str)];
    s21_strcpy(newStr, str);

    printf("%s\n", str);
    printf("%s\n", newStr);

    if (!s21_strcmp(newStr, str)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcat_test(char *dest, char const *src) {
    int result;
    int lenDest = s21_strlen(dest);
    int lenSrc = s21_strlen(src);

    printf("%s", dest);
    printf(" %s\n", src);

    s21_strcat(dest, src);

    result = s21_strlen(dest);
    printf("%s\n", dest);

    if (result == (lenDest + lenSrc)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strchr_test(char *str, int ch, char *expected_result) {
    char *result;
    printf("%s", str);
    printf(" %c\n", ch);

    result = s21_strchr(str, ch);
    printf("%s\n", result);

    if (!s21_strcmp(result, expected_result)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strstr_test(char *haystack, char *needle, char *expected_result) {
    char *result;
    printf("%s", haystack);
    printf(" %s\n", needle);

    result = s21_strstr(haystack, needle);
    printf("%s\n", result);
    if (!s21_strcmp(result, expected_result)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strtok_test(char *str, char *del, int expected_number) {
    int cnt = 0;

    printf("%s\n", str);
    printf("%s\n", del);

    char *token = s21_strtok(str, del);
    while (token != NULL) {
        printf("%s", token);
        token = s21_strtok(NULL, del);
        if (token != NULL) {
            cnt++;
            printf(" ");
        }
    }

    if (cnt > 0) cnt++;
    printf("\n");

    if (cnt == expected_number) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}