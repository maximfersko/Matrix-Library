gcc $(pkg-config --cflags --libs check) matrix.c matrix_test.c utilities.c --coverage -lcheck -o test
./test
lcov -o test.info -c -d .
genhtml -o report test.info
open report/index.html