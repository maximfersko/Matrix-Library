# lib_matrix

## Implementation of the data type library matrix and operations on the type.

### Struct data type matrix

```
typedef enum {
    CORRECT_MATRIX = 0,
    INCORRECT_MATRIX = 1,
    IDENTITY_MATRIX = 2,
    ZERO_MATRIX = 3
} matrix_type_t;

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
    matrix_type_t matrix_type;
} matrix_t;

```

### How to build library:

```
$ cd src
$ make

```
### How to run tests:

```
$ cd src
$ make gcov_report

```

