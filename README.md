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
This function creates a new matrix with the specified number of rows and columns. It returns a matrix_t structure representing the created matrix. If the number of rows or columns is non-positive, the matrix_type field of the returned structure is set to INCORRECT_MATRIX

```c
void remove_matrix(matrix_t *A);
```
This function frees the memory allocated for a matrix. It takes a pointer to a matrix_t structure as input and sets the fields of the structure to appropriate values after freeing the memory.

```c
int eq_matrix(matrix_t *A, matrix_t *B);
```
This function compares two matrices for equality. It returns SUCCESS if the matrices are equal and FAILURE otherwise. Matrices are considered equal if they have the same dimensions and their corresponding elements are within a defined accuracy.

```c
matrix_t sum_matrix(matrix_t *A, matrix_t *B);
```
This function computes the sum of two matrices. It returns a new matrix representing the sum of the input matrices. If the input matrices have different dimensions or are of an incorrect matrix type, the matrix_type field of the returned matrix is set to INCORRECT_MATRIX.

```c
matrix_t sub_matrix(matrix_t *A, matrix_t *B);
```
This function computes the difference between two matrices. It returns a new matrix representing the difference of the input matrices. If the input matrices have different dimensions or are of an incorrect matrix type, the matrix_type field of the returned matrix is set to INCORRECT_MATRIX.

```c
matrix_t mult_number(matrix_t *A, double number);
```
This function multiplies a matrix by a scalar value. It returns a new matrix representing the result of the multiplication. If the input matrix is of an incorrect matrix type, the matrix_type field of the returned matrix is set to INCORRECT_MATRIX.

```c
matrix_t mult_matrix(matrix_t *A, matrix_t *B);
```
This function multiplies two matrices. It returns a new matrix representing the result of the multiplication. If the input matrices have incompatible dimensions or are of an incorrect matrix type, the matrix_type field of the returned matrix is set to INCORRECT_MATRIX.

```c
matrix_t transpose(matrix_t *A);
```
This function computes the transpose of a matrix. It returns a new matrix representing the transpose of the input matrix. If the input matrix is of an incorrect matrix type, the matrix_type field of the returned matrix is set to INCORRECT_MATRIX.

```c
matrix_t calc_complements(matrix_t *A);
```
This function calculates the matrix of complements for a square matrix. It returns a new matrix representing the matrix of complements. If the input matrix is not a square matrix or is of an incorrect matrix type, the matrix_type field of the returned matrix is set to INCORRECT_MATRIX.

```c
matrix_t inverse_matrix(matrix_t *A);
```
This function calculates the inverse of a square matrix. It returns a new matrix representing the inverse matrix. If the input matrix is not a square matrix, is of an incorrect matrix type, or has a determinant of 0, the matrix_type field of the returned matrix is set to INCORRECT_MATRIX.

```c
matrix_t inverse_matrix(matrix_t *A);
```
This function calculates the determinant of a square matrix. It returns the determinant value. If the input matrix is not a square matrix or is of an incorrect matrix type, the function returns NaN.
