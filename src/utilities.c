
#include "matrix.h"


void init_matrix(matrix_t* A, char* name) {
    FILE* file;
    file = fopen(name, "r+");
    if (file) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                fscanf(file, "%lf", &A->matrix[i][j]);
            }
        }
        fclose(file);
    } else {
        printf("Error write file");
    }
}


void print_matrix(matrix_t A) {
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.columns; j++) {
            printf("%lf ", A.matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\t%d\n", A.matrix_type);
}


bool validate(matrix_t *A) {
    bool result = false;
    if ((A->matrix != NULL) && (A != NULL) && (A->columns > 0) && \
     (A->rows > 0) && (A->matrix_type != INCORRECT_MATRIX)) {
         result = true;
     }
    return result;
}

bool zeroMatrix(matrix_t *A) {
    bool result = true;
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            if (fabs(A->matrix[i][j] > 0)) {
                result = false;
                break;
            }
        }
    }
    return result;
}

bool identityMatrix(matrix_t *A) {
    bool result = true;
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            if (i == j) {
                if ((A->matrix[i][j] - 1) > accuracy) result = false;
            }
            if (i != j) {
                if (((A->matrix[i][j]) - 0) > accuracy) result = false;
            }
        }
    }
    return result;
}


void matrixType(matrix_t *A) {
    if (validate(A) == true) A->matrix_type = CORRECT_MATRIX;
    if (identityMatrix(A) == true) A->matrix_type = IDENTITY_MATRIX;
    if (zeroMatrix(A) == true) A->matrix_type = ZERO_MATRIX;
}


matrix_t cutMatrix(matrix_t *A, int rows, int columns) {
    matrix_t result = create_matrix(A->rows - 1, A->columns - 1);
    int rowsTmp = 0, columnsTmp = 0;
    if (validate(A) == true) {
        for (int i = 0; i < A->rows; i++) {
            if (rows != i) {
                for (int j = 0; j < A->columns; j++) {
                    if (columns != j) {
                        result.matrix[rowsTmp][columnsTmp] = A->matrix[i][j];
                        columnsTmp++;
                    }
                }
                columnsTmp = 0;
                rowsTmp++;
            }
        }
      matrixType(A);
    } else {
        result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}

