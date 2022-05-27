// Copyright 2022 21-school.ru

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>
#include "./s21_strrchr.h"

START_TEST(strrchr_test) {
    char str[] = "Hello world\0";
    ck_assert_pstr_eq(strrchr(str, _i), s21_strrchr(str, _i));
}
END_TEST

START_TEST(strrchr_test1) {
    char str1[] = "Hello world\n\0";
    ck_assert_pstr_eq(strrchr(str1, _i), s21_strrchr(str1, _i));
}
END_TEST

START_TEST(strrchr_test2) {
    char str2[] = "a\n\0";
    ck_assert_pstr_eq(strrchr(str2, _i), s21_strrchr(str2, _i));
}
END_TEST

START_TEST(strrchr_test3) {
    char str3[] = " \n\0";
    ck_assert_pstr_eq(strrchr(str3, _i), s21_strrchr(str3, _i));
}
END_TEST

START_TEST(strrchr_test4) {
    char str4[] = " \0";
    ck_assert_pstr_eq(strrchr(str4, _i), s21_strrchr(str4, _i));
}
END_TEST

START_TEST(strrchr_test5) {
    char str5[] = "\n\0";
    ck_assert_pstr_eq(strrchr(str5, _i), s21_strrchr(str5, _i));
}
END_TEST

START_TEST(strrchr_test6) {
    char str6[] = "\0";
    ck_assert_pstr_eq(strrchr(str6, _i), s21_strrchr(str6, _i));
}
END_TEST


Suite *strrchr_suite_create(void) {
    Suite *suite = suite_create("strrchr_test");
    TCase *tcase_core = tcase_create("Core of strrchr_test");
    tcase_add_loop_test(tcase_core, strrchr_test, -1000, 1000);
    tcase_add_loop_test(tcase_core, strrchr_test1, -1000, 1000);
    tcase_add_loop_test(tcase_core, strrchr_test2, -1000, 1000);
    tcase_add_loop_test(tcase_core, strrchr_test3, -1000, 1000);
    tcase_add_loop_test(tcase_core, strrchr_test4, -1000, 1000);
    tcase_add_loop_test(tcase_core, strrchr_test5, -1000, 1000);
    tcase_add_loop_test(tcase_core, strrchr_test6, -1000, 1000);
    suite_add_tcase(suite, tcase_core);

    return suite;
}

int main(void) {
    int failed_count = 0;
    Suite *suite = strrchr_suite_create();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_NORMAL);
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return (failed_count != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
