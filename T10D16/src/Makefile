CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD=../build/

strlen_tests: s21_string.o s21_string_test_strlen.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_1

strcmp_tests: s21_string.o s21_string_test_strcmp.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_2

strcpy_tests: s21_string.o s21_string_test_strcpy.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_3

strcat_tests: s21_string.o s21_string_test_strcat.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_4

strchr_tests: s21_string.o s21_string_test_strchr.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_5

strstr_tests: s21_string.o s21_string_test_strstr.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_6

strtok_tests: s21_string.o s21_string_test_strtok.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_7

text_processor: text_processor.o s21_string.o
	$(CC) $(CFLAGS) text_processor.o s21_string.o -o $(BUILD)Quest_8

s21_string_test_strlen.o: s21_string_test.c
	$(CC) $(CFLAGS) -DSTRLEN -c s21_string_test.c 

s21_string_test_strcmp.o: s21_string_test.c
	$(CC) $(CFLAGS) -DSTRCMP -c s21_string_test.c

s21_string_test_strcpy.o: s21_string_test.c
	$(CC) $(CFLAGS) -DSTRCPY -c s21_string_test.c

s21_string_test_strcat.o: s21_string_test.c
	$(CC) $(CFLAGS) -DSTRCAT -c s21_string_test.c

s21_string_test_strchr.o: s21_string_test.c
	$(CC) $(CFLAGS) -DSTRCHR -c s21_string_test.c

s21_string_test_strstr.o: s21_string_test.c
	$(CC) $(CFLAGS) -DSTRSTR -c s21_string_test.c

s21_string_test_strtok.o: s21_string_test.c
	$(CC) $(CFLAGS) -DSTRTOK -c s21_string_test.c

text_processor.o: text_processor.c
	$(CC) $(CFLAGS) -c text_processor.c

s21_string_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c 
	
clean:
	rm -rf *.o ../build/*