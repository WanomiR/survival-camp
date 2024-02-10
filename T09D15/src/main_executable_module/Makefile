# sources: https://dev.to/iamkhalil42/all-you-need-to-know-about-c-static-libraries-1o0b
# 		   https://younglinux.info/c/library

CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD=../../build/
DLIBS=../data_libs/
DMODULE=../data_module/
YADM=../yet_another_decision_module/

all: build

build: main_executable_module.o data_io.o data_stat.o data_process.o decision.o 
	$(CC) $(CFLAG) main_executable_module.o data_io.o data_stat.o data_process.o decision.o -o $(BUILD)Quest_3

build_with_macro: main_executable_module_m.o data_stat.o data_process.o decision.o 
	$(CC) $(CFLAG) main_executable_module.o data_stat.o data_process.o decision.o -o $(BUILD)Quest_4

build_with_static: main_executable_module.o data_io.o libdata_stat.a data_process.o decision.o
	$(CC) $(CFLAG) main_executable_module.o data_io.o data_process.o decision.o -L$(DLIBS) -ldata_stat -o $(BUILD)Quest_5

build_with_dynamic: main_executable_module.o data_io.o libdata_process.so decision.o
	$(CC) $(CFLAG) main_executable_module.o data_io.o decision.o -L$(DMODULE) -ldata_process -Wl,-rpath,$(DMODULE) -o $(BUILD)Quest_6 

main_executable_module_m.o: main_executable_module.c
	$(CC) $(CFLAGS) -DWITH_MACRO -c main_executable_module.c

main_executable_module.o: main_executable_module.c
	$(CC) $(CFLAGS) -c main_executable_module.c

decision.o: $(YADM)decision.c $(YADM)decision.h $(DLIBS)data_stat.h
	$(CC) $(CFLAGS) -c $(YADM)decision.c

libdata_process.so: $(DMODULE)data_process.c $(DLIBS)data_stat.c
	$(CC) $(CFLAGS) -c -fPIC $(DMODULE)data_process.c $(DLIBS)data_stat.c 
	$(CC) -shared -o $(DMODULE)libdata_process.so data_stat.o data_process.o 

data_process.o: $(DMODULE)data_process.c $(DMODULE)data_process.h $(DLIBS)data_stat.h
	$(CC) $(CFLAGS) -c $(DMODULE)data_process.c

data_io.o: $(DLIBS)data_io.c $(DLIBS)data_io.h
	$(CC) $(CFLAGS) -c $(DLIBS)data_io.c

libdata_stat.a: $(DLIBS)data_stat.o
	ar r $(DLIBS)libdata_stat.a $(DLIBS)data_stat.o

data_stat.o: $(DLIBS)data_stat.c $(DLIBS)data_stat.h
	$(CC) $(CFLAGS) -c $(DLIBS)data_stat.c

clean:
	rm -rf ../**/*.o ../**/*.a ../**/*.so $(BUILD)*

rebuild: clean all