OBJ = matrix.o utilities.o
SRCTEST = matrix.c matrix_test.c utilities.c
LIB = matrix.a
SRC = matrix.c utilities.c
CC = gcc
LIBCHECK = -lcheck
TESTF = matrix_test.c
PUSHCOMMENT="update"

.PHONY:
	clean rebuild test leaks all default

OS = $(shell uname -s)
ifeq ($(OS), Linux)
	LIBCHECK= -lcheck -lpthread  -lrt -lm -lsubunit
endif


default: matrix.a

all: matrix.a test gcov_report

matrix.a: matrix.o
	ar rcs matrix.a $(OBJ)

matrix.o:
	gcc -c $(SRC) 


clean:
	rm -rf *.txt test matrix valgrind leaks *.dSYM *.out *.cfg
	rm -rf *.gcno *.gcda *.gcov *.info report
	rm -rf *.o *.a


gcov_report:
	sh test.sh

leaks: matrix.a
	gcc matrix.a matrix_test.c $(LIBCHECK) -o leaks
	leaks -atExit -- ./leaks 

valgrind:
	gcc $(SRC) $(TESTF) $(LIBCHECK) -o valgrind
	valgrind -s --trace-children=yes --leak-check=yes ./valgrind

test: matrix.a
	$(CC) $(pkg-config --cflags --libs check) matrix.a matrix_test.c $(LIBCHECK) -o test
	./test

debug:
	gcc -g $(SRC) main.c -o debug.out

rebuild: clean all