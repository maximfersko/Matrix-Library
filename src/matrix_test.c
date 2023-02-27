
#include "matrix.h"
#include <check.h>

matrix_t first;
matrix_t second;
matrix_t result;

START_TEST(create_matrix_test) {
  first = create_matrix(1, 1);
  ck_assert_int_eq(first.matrix_type, ZERO_MATRIX);
  remove_matrix(&first);
}
END_TEST

START_TEST(create_matrix_test2) {
  first = create_matrix(-2, 3);
  ck_assert_int_eq(first.matrix_type, INCORRECT_MATRIX);
  second = create_matrix(2, -4);
  ck_assert_int_eq(second.matrix_type, INCORRECT_MATRIX);
  remove_matrix(&first);
  remove_matrix(&second);
}
END_TEST

START_TEST(eq_matrix_test) {
  first = create_matrix(2, 3);
  second = create_matrix(3, 2);
  init_matrix(&first, "data/2x3.txt");
  init_matrix(&second, "data/3x2.txt");
  int res = eq_matrix(&first, &second);
  ck_assert_int_eq(FAILURE, res);
  remove_matrix(&first);
  remove_matrix(&second);
}
END_TEST

START_TEST(eq_matrix_test2) {
  matrix_t first = create_matrix(2, 3);
  matrix_t second = create_matrix(3, 2);
  init_matrix(&first, "data/2x2.txt");
  init_matrix(&second, "data/2x2-1.txt");
  int res = eq_matrix(&first, &second);
  ck_assert_int_eq(FAILURE, res);
  remove_matrix(&first);
  remove_matrix(&second);
}
END_TEST

START_TEST(eq_matrix_test3) {
  first = create_matrix(1, 1);
  second = create_matrix(1, 1);
  init_matrix(&first, "data/1x1.txt");
  init_matrix(&second, "data/1-1.txt");
  int res = eq_matrix(&first, &second);
  ck_assert_int_eq(FAILURE, res);
  remove_matrix(&first);
  remove_matrix(&second);
}
END_TEST

START_TEST(eq_matrix_test4) {
  first = create_matrix(5, 5);
  second = create_matrix(5, 5);
  init_matrix(&first, "data/5x5.txt");
  init_matrix(&second, "data/5x5-1.txt");
  int res = eq_matrix(&first, &second);
  ck_assert_int_eq(FAILURE, res);
  remove_matrix(&first);
  remove_matrix(&second);
}
END_TEST

START_TEST(eq_matrix_test5) {
  first = create_matrix(3, 3);
  second = create_matrix(3, 3);
  result = create_matrix(3, 3);
  init_matrix(&first, "data/3x3.txt");
  init_matrix(&second, "data/3x3-1.txt");
  int res = eq_matrix(&first, &second);
  ck_assert_int_eq(SUCCESS, res);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
}
END_TEST


START_TEST(sum_matrix_test) {
  first = create_matrix(3, 3);
  second = create_matrix(3, 3);
  result = create_matrix(3, 3);
  init_matrix(&first, "data/3x3.txt");
  init_matrix(&second, "data/3x3-1.txt");
  init_matrix(&result, "data/result/add/3x3+3x3-1.txt");
  matrix_t res = sum_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(sum_matrix_test2) {
  first = create_matrix(5, 5);
  second = create_matrix(5, 5);
  result = create_matrix(5, 5);
  init_matrix(&first, "data/5x5.txt");
  init_matrix(&second, "data/5x5-1.txt");
  init_matrix(&result, "data/result/add/5x5+5x5-1.txt");
  matrix_t res = sum_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(sum_matrix_test3) {
  first = create_matrix(10, 10);
  second = create_matrix(10, 10);
  result = create_matrix(10, 10);
  init_matrix(&first, "data/10x10.txt");
  init_matrix(&second, "data/10x10-1.txt");
  init_matrix(&result, "data/result/add/10x10+10x10-1.txt");
  matrix_t res = sum_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(sum_matrix_test4) {
  first = create_matrix(10, 10);
  second = create_matrix(10, 10);
  result = create_matrix(10, 10);
  init_matrix(&first, "data/10x10f.txt");
  init_matrix(&second, "data/10x10-1f.txt");
  init_matrix(&result, "data/result/add/10x10f+10x10-1f.txt");
  matrix_t res = sum_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(sum_matrix_test5) {
  first = create_matrix(7, 7);
  second = create_matrix(7, 7);
  result = create_matrix(7, 7);
  init_matrix(&first, "data/7x7f.txt");
  init_matrix(&second, "data/7x7-1f.txt");
  init_matrix(&result, "data/result/add/7x7+7x7-1f.txt");
  matrix_t res = sum_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(sum_matrix_test6) {
  first = create_matrix(0, 7);
  second = create_matrix(7, 0);
  result = create_matrix(7, 7);
  init_matrix(&first, "data/7x7f.txt");
  init_matrix(&second, "data/7x7-1f.txt");
  init_matrix(&result, "data/result/add/7x7+7x7-1f.txt");
  matrix_t res = sum_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(false, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST


START_TEST(sub_matrix_test1) {
  first = create_matrix(7, 7);
  second = create_matrix(7, 7);
  result = create_matrix(7, 7);
  init_matrix(&first, "data/7x7f.txt");
  init_matrix(&second, "data/7x7-1f.txt");
  init_matrix(&result, "data/result/sub/7x7-7x7-1f.txt");
  matrix_t res = sub_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(sub_matrix_test2) {
  first = create_matrix(3, 3);
  second = create_matrix(3, 3);
  result = create_matrix(3, 3);
  init_matrix(&first, "data/3x3.txt");
  init_matrix(&second, "data/3x3-1.txt");
  init_matrix(&result, "data/result/sub/3x3-3x3-1.txt");
  matrix_t res = sub_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(sub_matrix_test3) {
  first = create_matrix(10, 10);
  second = create_matrix(10, 10);
  result = create_matrix(10, 10);
  init_matrix(&first, "data/10x10f.txt");
  init_matrix(&second, "data/10x10-1f.txt");
  init_matrix(&result, "data/result/sub/10x10-10x10-1f.txt");
  matrix_t res = sub_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST


START_TEST(sub_matrix_test4) {
  first = create_matrix(10, 10);
  second = create_matrix(10, 10);
  result = create_matrix(10, 10);
  init_matrix(&first, "data/10x10.txt");
  init_matrix(&second, "data/10x10-1.txt");
  init_matrix(&result, "data/result/sub/10x10-10x10-1.txt");
  matrix_t res = sub_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(sub_matrix_test5) {
  first = create_matrix(5, 5);
  second = create_matrix(5, 5);
  result = create_matrix(5, 5);
  init_matrix(&first, "data/5x5.txt");
  init_matrix(&second, "data/5x5-1.txt");
  init_matrix(&result, "data/result/sub/5x5-5x5-1.txt");
  matrix_t res = sub_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(sub_matrix_test6) {
  first = create_matrix(0, 5);
  second = create_matrix(5, 5);
  result = create_matrix(5, 5);
  init_matrix(&first, "data/5x5.txt");
  init_matrix(&second, "data/5x5-1.txt");
  init_matrix(&result, "data/result/sub/5x5-5x5-1.txt");
  matrix_t res = sub_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(false, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(sub_matrix_test7) {
  first = create_matrix(5, 5);
  second = create_matrix(5, 5);
  result = create_matrix(5, 5);
  init_matrix(&first, "data/5x5.txt");
  init_matrix(&second, "data/5x5-0.txt");
  init_matrix(&result, "data/result/sub/5x5-zero.txt");
  matrix_t res = sub_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(true, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(mult_num_test) {
  first = create_matrix(30, 30);
  result = create_matrix(30, 30);
  init_matrix(&first, "data/30x30f.txt");
  init_matrix(&result, "data/result/multNumber/30x30f*33f.txt");
  matrix_t res = mult_number(&first, 33);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_test) {
  first = create_matrix(7, 7);
  second = create_matrix(7, 7);
  result = create_matrix(7, 7);
  init_matrix(&first, "data/7x7f.txt");
  init_matrix(&second, "data/7x7-1f.txt");
  init_matrix(&result, "data/result/multMatrix/7x7f*7x7-1f.txt");
  matrix_t res = mult_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_test2) {
  first = create_matrix(5, 5);
  second = create_matrix(5, 5);
  result = create_matrix(5, 5);
  init_matrix(&first, "data/5x5.txt");
  init_matrix(&second, "data/5x5-1.txt");
  init_matrix(&result, "data/result/multMatrix/5x5*5x5-1.txt");
  matrix_t res = mult_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_test3) {
  first = create_matrix(0, 5);
  second = create_matrix(5, 0);
  result = create_matrix(5, 5);
  init_matrix(&first, "data/5x5.txt");
  init_matrix(&second, "data/5x5-1.txt");
  init_matrix(&result, "data/result/multMatrix/7x7f*7x7-1f.txt");
  matrix_t res = mult_matrix(&first, &second);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(false, f);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(transpose_test) {
  first = create_matrix(30, 30);
  result = create_matrix(30, 30);
  init_matrix(&first, "data/30x30f.txt");
  init_matrix(&result, "data/result/transponse/30x30f.txt");
  matrix_t res = transpose(&first);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(transpose_test2) {
  first = create_matrix(7, 7);
  result = create_matrix(7, 7);
  init_matrix(&first, "data/7x7f.txt");
  init_matrix(&result, "data/result/transponse/7x7f.txt");
  matrix_t res = transpose(&first);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(transpose_test3) {
  first = create_matrix(2, 22);
  result = create_matrix(22, 2);
  init_matrix(&first, "data/2x22f.txt");
  init_matrix(&result, "data/result/transponse/2x22f.txt");
  matrix_t res = transpose(&first);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(SUCCESS, f);
  remove_matrix(&first);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(transpose_test4) {
  first = create_matrix(0, 22);
  result = create_matrix(2, 22);
  init_matrix(&first, "data/2x22f.txt");
  init_matrix(&result, "data/result/transponse/2x22f.txt");
  matrix_t res = transpose(&first);
  int f = eq_matrix(&res, &result);
  ck_assert_int_eq(false, f);
  remove_matrix(&first);
  remove_matrix(&result);
  remove_matrix(&res);
}
END_TEST

START_TEST(identityMatrix_test) {
  first = create_matrix(5, 5);
  init_matrix(&first, "data/identity.txt");
  bool res = identityMatrix(&first);
  ck_assert_int_eq(res, true);
  remove_matrix(&first);
}
END_TEST

START_TEST(identityMatrix_test2) {
  first = create_matrix(3, 3);
  init_matrix(&first, "data/noidentity.txt");
  bool res = identityMatrix(&first);
  ck_assert_int_eq(res, false);
  remove_matrix(&first);
}
END_TEST


START_TEST(type_validate) {
    first = create_matrix(3, 3);
    init_matrix(&first, "data/3-0-3.txt");
    second = create_matrix(3, 3);
    init_matrix(&second, "data/0-3-3.txt");
    result = sub_matrix(&first, &second);
    ck_assert_int_eq(result.matrix_type, ZERO_MATRIX);
    matrix_t o = create_matrix(0, 0);
    bool i = validate(&o);
    ck_assert_int_eq(false, i);
    remove_matrix(&first);
    remove_matrix(&second);
    remove_matrix(&result);
    remove_matrix(&o);
}
END_TEST


START_TEST(determinant_test) {
  first = create_matrix(5, 5);
  init_matrix(&first, "data/5x5.txt");
  double res = 0, cmpRes = -96;
  res = determinant(&first);
  ck_assert_double_eq(res, cmpRes);
  remove_matrix(&first);
}
END_TEST

START_TEST(determinant_test1) {
  first = create_matrix(2, 2);
  init_matrix(&first, "data/2x2.txt");
  double res = 0, cmpRes = -681;
  res = determinant(&first);
  ck_assert_double_eq(res, cmpRes);
  remove_matrix(&first);
}
END_TEST

START_TEST(determinant_test2) {
  first = create_matrix(1, 1);
  init_matrix(&first, "data/1.txt");
  double res = 0, cmpRes = 89;
  res = determinant(&first);
  ck_assert_double_eq(res, cmpRes);
  remove_matrix(&first);
}
END_TEST

START_TEST(determinant_test3) {
  first = create_matrix(2, 1);
  init_matrix(&first, "data/1.txt");
  double res = 0, cmpRes = NAN;
  res = determinant(&first);
  ck_assert_double_eq(res, cmpRes);
  remove_matrix(&first);
}
END_TEST

START_TEST(inverse_matrix) {
  first = create_matrix(3, 3);
  init_matrix(&first, "data/inverse.txt");
  second = create_matrix(3, 3);
  init_matrix(&second, "data/result/inverse/1.txt");
  result = inverse_matrix(&first);
  int res = eq_matrix(&result, &second);
  ck_assert_int_eq(res, SUCCESS);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
}
END_TEST

START_TEST(calc_t) {
  first = create_matrix(3, 3);
  init_matrix(&first, "data/calc.txt");
  second = create_matrix(3, 3);
  init_matrix(&second, "data/result/calc/1.txt");
  result = calc_complements(&first);
  int res = eq_matrix(&second, &result);
  ck_assert_int_eq(SUCCESS, res);
  remove_matrix(&first);
  remove_matrix(&second);
  remove_matrix(&result);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("matrix");
  TCase *matrixCase = tcase_create("matrix_comparativeTest");
  SRunner *sr = srunner_create(s1);
  int nf;

  tcase_set_timeout(matrixCase, 2);
  suite_add_tcase(s1, matrixCase);
  tcase_add_test(matrixCase, create_matrix_test);
  tcase_add_test(matrixCase, create_matrix_test2);
  tcase_add_test(matrixCase, eq_matrix_test);
  tcase_add_test(matrixCase, eq_matrix_test2);
  tcase_add_test(matrixCase, eq_matrix_test3);
  tcase_add_test(matrixCase, eq_matrix_test4);
  tcase_add_test(matrixCase, eq_matrix_test5);
  tcase_add_test(matrixCase, sum_matrix_test);
  tcase_add_test(matrixCase, sum_matrix_test2);
  tcase_add_test(matrixCase, sum_matrix_test3);
  tcase_add_test(matrixCase, sum_matrix_test4);
  tcase_add_test(matrixCase, sum_matrix_test5);
  tcase_add_test(matrixCase, sum_matrix_test6);
  tcase_add_test(matrixCase, sub_matrix_test1);
  tcase_add_test(matrixCase, sub_matrix_test2);
  tcase_add_test(matrixCase, sub_matrix_test3);
  tcase_add_test(matrixCase, sub_matrix_test4);
  tcase_add_test(matrixCase, sub_matrix_test5);
  tcase_add_test(matrixCase, sub_matrix_test6);
  tcase_add_test(matrixCase, sub_matrix_test7);
  tcase_add_test(matrixCase, mult_num_test);
  tcase_add_test(matrixCase, mult_matrix_test);
  tcase_add_test(matrixCase, mult_matrix_test2);
  tcase_add_test(matrixCase, mult_matrix_test3);
  tcase_add_test(matrixCase, transpose_test);
  tcase_add_test(matrixCase, transpose_test2);
  tcase_add_test(matrixCase, transpose_test3);
  tcase_add_test(matrixCase, transpose_test4);
  tcase_add_test(matrixCase, identityMatrix_test);
  tcase_add_test(matrixCase, identityMatrix_test2);
  tcase_add_test(matrixCase, type_validate);
  tcase_add_test(matrixCase, determinant_test);
  tcase_add_test(matrixCase, determinant_test1);
  tcase_add_test(matrixCase, determinant_test2);
  tcase_add_test(matrixCase, inverse_matrix);
  tcase_add_test(matrixCase, calc_t);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
