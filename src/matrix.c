
#include "matrix.h"


matrix_t create_matrix(int rows, int columns) {
    matrix_t A;
    A.columns = columns;
    A.rows = rows;
    if (A.columns <= 0 || A.rows <= 0) {
        A.matrix_type = INCORRECT_MATRIX;
    } else {
        A.matrix = (double **) calloc(rows, sizeof(double *));
        for (int i = 0; i < A.rows; i++) {
            A.matrix[i] = (double *) calloc(columns, sizeof(double));
        }
        A.matrix_type = ZERO_MATRIX;
    }
    return A;
}


void remove_matrix(matrix_t *A) {
    if (A != NULL) {
        if (A->matrix_type != INCORRECT_MATRIX) {
            for (int i = 0; i < A->rows; i++) {
                free(A->matrix[i]);
                A->matrix[i] = NULL;
            }
            free(A->matrix);
        }
    }
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
    A->matrix_type = INCORRECT_MATRIX;
}



int eq_matrix(matrix_t *A, matrix_t *B) {
    int status = SUCCESS;
    double equal;
    if (((validate(A) == true) && (validate(B) == true)) && \
        ((A->rows == B->rows) && (A->columns == B->columns))) {
        for (int i = 0; i < A->rows || !status; i++) {
            for (int j = 0; j < A->columns || !status; j++) {
                equal = fabs(A->matrix[i][j] - B->matrix[i][j]);
                if (equal > accuracy) status = FAILURE;
            }
        }
    } else {
        status = FAILURE;
    }
    return status;
}


matrix_t sum_matrix(matrix_t *A, matrix_t *B) {
    matrix_t result = create_matrix(A->rows, A->columns);
    if (((validate(A) == true) \
          && (validate(B) == true)) \
         && (A->rows == B->rows && A->columns == B->columns)) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
        }
        matrixType(&result);
    } else {
        result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}


matrix_t sub_matrix(matrix_t *A, matrix_t *B) {
    matrix_t result = create_matrix(A->rows, A->columns);
    if (((validate(A) == true) \
          && (validate(B) == true)) \
          && (A->rows == B->rows && A->columns == B->columns)) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }
        matrixType(&result);
    } else {
        result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}


matrix_t mult_number(matrix_t *A, double number) {
    matrix_t result = create_matrix(A->rows, A->columns);
    if (validate(A) == true) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result.matrix[i][j] = number * A->matrix[i][j];
            }
        }
        matrixType(&result);
    } else {
        result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}


matrix_t mult_matrix(matrix_t *A, matrix_t *B) {
    matrix_t result = {NULL, 0, 0, 1};
    if (((validate(A) == true) && (validate(B) == true)) && \
        (A->columns == B->rows)) {
        result = create_matrix(A->rows, B->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
                for (int k = 0; k < A->columns; k++) {
                    result.matrix[i][j] += (A->matrix[i][k] * B->matrix[k][j]);
                }
            }
        }
        matrixType(&result);
    } else {
        result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}


matrix_t transpose(matrix_t *A) {
    matrix_t result;
    if ((validate(A) == true)) {
        result = create_matrix(A->columns, A->rows);
        for (int i = 0; i < result.rows; i++) {
            for (int j = 0; j < result.columns; j++) {
                result.matrix[i][j] = A->matrix[j][i];
            }
        }
        matrixType(&result);
    } else {
        result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}


matrix_t calc_complements(matrix_t *A) {
    matrix_t result, tmp;
    if ((validate(A) == true) && (A->rows == A->columns)) {
        result = create_matrix(A->rows, A->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->rows; j++) {
                tmp = cutMatrix(A, i, j);
                result.matrix[i][j] = pow(-1, i + j) * determinant(&tmp);
                remove_matrix(&tmp);
            }
        }
        result.matrix_type = CORRECT_MATRIX;
        matrixType(&result);
    } else {
        result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}


matrix_t inverse_matrix(matrix_t *A) {
    matrix_t result;
    if ((validate(A)) && (A->columns == A->rows) && \
    (determinant(A) != 0.0)) {
        matrix_t minor = calc_complements(A), \
        tran = transpose(&minor);
        result = mult_number(&tran, 1 / determinant(A));
        result.matrix_type = CORRECT_MATRIX;
        matrixType(A);
        remove_matrix(&minor);
        remove_matrix(&transpose);
    } else {
        result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}


double determinant(matrix_t* A) {
    double result = 0.0;
    if ((validate(A) == true) && (A->columns == A->rows)) {
        if (A->rows == 1) {
            result = A->matrix[0][0];
        } else if (A->rows == 2) {
            result = (A->matrix[1][1] * A->matrix[0][0]) - \
            (A->matrix[1][0] * A->matrix[0][1]);
        } else if (A->rows > 2) {
            for (int i = 0; i < A->rows; i++) {
                matrix_t detA = cutMatrix(A, 0, i);
                result += pow(-1, i) * A->matrix[0][i] * determinant(&detA);
                remove_matrix(&detA);
            }
        }
    } else {
        result = NAN;
    }
    return result;
}
