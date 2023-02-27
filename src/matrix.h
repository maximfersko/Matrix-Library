#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

#define SUCCESS 1
#define FAILURE 0
#define accuracy 1e-7

/**
 * @brief Выделяет память по создание матрицы
 * @param rows число строк
 * @param columns число колонок
 * @return возращает  матрицу указанного размера заполненую нулями
 */
matrix_t create_matrix(int rows, int columns);

/**
 * @brief Считывает матрицу с текстового файла
 * @param A матрица в которую записывается результат
 * @param name путь к файлу
 */
void init_matrix(matrix_t* A, char* name);

/**
 * @brief Очищает память матрицы, также зануляет все значения
 * @param A Матрица
 */
void remove_matrix(matrix_t *A);

/**
 * @brief Распечатывает матрицу в консоль
 * @param A Матрица 
 */
void print_matrix(matrix_t A);

/**
 * @brief Сравнивает две одинаковых по размеру матрицы
 * @param A Первая Матрица
 * @param B Вторая Матрица
 * @return SUCCESS - 1,  FAILURE - 0
 */
int eq_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief Складывает две матрицы
 * @param A Первая Матрица
 * @param B Вторая Матрица
 * @return возращает сумму двух матриц
 */
matrix_t sum_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief Вычитает вторую матрицу из первой матрицы 
 * @param A Первая Матрица
 * @param B Вторая Матрица
 * @return возращает разность двух матриц
 */
matrix_t sub_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief Умножает матрицу на число
 * @param A Первая Матрица
 * @param number число
 * @return возращает произведение матрицы на число
 */
matrix_t mult_number(matrix_t *A, double number);

/**
 * @brief Умножает матрицу на матрицу 
 * @param A Первая Матрица
 * @param B Вторая Матрица
 * @return Возращает произведение матрицы на число
 */
matrix_t mult_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief транспонирует матрицу
 * @param A  Матрица
 * @return Возвращает транспонированную матрицу 
 */
matrix_t transpose(matrix_t *A);

/**
 * @brief Вычисляет минор матрицы и матрица алгебраических дополнений
 * @param A  Матрица
 * @return Возвращает матрицу алгеброических дополнений 
 */
matrix_t calc_complements(matrix_t *A);


/**
 * @brief Проверяет корректность матрицы
 * @param A  Матрица
 * @return true - матрица корректна, false - матрица неккоректна 
 */
bool validate(matrix_t *A);

/**
 * @brief Проверяет нулевая ли матрица
 * @param A  Матрица
 * @return true - матрица нулевая, false - матрица не нулевая 
 */
bool zeroMatrix(matrix_t *A);

/**
 * @brief Проверяет единичная ли матрица
 * @param A  Матрица
 * @return true - матрица единичная, false - матрица не единичная 
 */
bool identityMatrix(matrix_t *A);

/**
 * @brief Проверяет нулевая ли матрица
 * @param A  Матрица
 * @param rows  Строка
 * @param columns Столбец
 * @return Возращает обрезанную матрицу
 */
matrix_t cutMatrix(matrix_t *A, int rows, int columns);

/**
 * @brief Устанавливает в поле структуры matrix_type тип матрицы 
 * @param A  Матрица
 */
void matrixType(matrix_t *A);

/**
 * @brief Вычисляет детерминант матрицы
 * @param A  Матрица
 * @return Возращает дерминант матрицы
 */
double determinant(matrix_t* A);

/**
 * @brief Инвертирует матрицу 
 * @param A  Матрица
 * @return Возращает инвертированную матрицу
 */
matrix_t inverse_matrix(matrix_t *A);

#endif  //  SRC_MATRIX_H_
