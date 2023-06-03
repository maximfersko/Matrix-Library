# lib_matrix

## Implementation of the data type library matrix and operations on the type.

### Struct data type matrix

```c
typedef enum {
    CORRECT_MATRIX = 0,
    INCORRECT_MATRIX = 1,
    IDENTITY_MATRIX = 2,
    ZERO_MATRIX = 3
} matrix_type_t;

typedef struct matrix_struct {
    double **matrix; // A 2D array storing the matrix elements.
    int rows; // The number of rows in the matrix.
    int columns; // The number of columns in the matrix.
    matrix_type_t matrix_type; //  An enumeration indicating the type of the matrix (ZERO_MATRIX, INCORRECT_MATRIX, or CORRECT_MATRIX).
} matrix_t;
```

### How to build library:

```bash
$ cd src
$ make
```
### How to run tests:

```bash
$ cd src
$ make gcov_report
```

## Functions:

```c
matrix_t create_matrix(int rows, int columns);
```
Description:
This function creates a new matrix with the specified number of rows and columns. It returns a matrix_t structure representing the created matrix. If the number of rows or columns is non-positive, the matrix_type field of the returned structure is set to INCORRECT_MATRIX
