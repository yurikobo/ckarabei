// Copyright 2022 21-school.ru

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>
#include "./s21_strcpy.h"

START_TEST(strcpy_test) {
    char s21_src[] = "Hello world\0";
    char s21_dest[30];
    char str_dest[30];
    s21_strcpy(s21_dest, s21_src);
    strcpy(str_dest, s21_src);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

START_TEST(strcpy_test1) {
    char s21_src[] = "Hello world\n\0";
    char s21_dest[30];
    char str_dest[30];
    s21_strcpy(s21_dest, s21_src);
    strcpy(str_dest, s21_src);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

START_TEST(strcpy_test2) {
    char s21_src[] = "a\n\0";
    char s21_dest[30];
    char str_dest[30];
    s21_strcpy(s21_dest, s21_src);
    strcpy(str_dest, s21_src);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

START_TEST(strcpy_test3) {
    char s21_src[] = " \n\0";
    char s21_dest[30];
    char str_dest[30];
    s21_strcpy(s21_dest, s21_src);
    strcpy(str_dest, s21_src);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

START_TEST(strcpy_test4) {
    char s21_src[] = " \0";
    char s21_dest[30];
    char str_dest[30];
    s21_strcpy(s21_dest, s21_src);
    strcpy(str_dest, s21_src);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

START_TEST(strcpy_test5) {
    char s21_src[] = "\n\0";
    char s21_dest[30];
    char str_dest[30];
    s21_strcpy(s21_dest, s21_src);
    strcpy(str_dest, s21_src);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

START_TEST(strcpy_test6) {
    char s21_src[] = "\0";
    char s21_dest[30];
    char str_dest[30];
    s21_strcpy(s21_dest, s21_src);
    strcpy(str_dest, s21_src);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

Suite *strcpy_suite_create(void) {
    Suite *suite = suite_create("strcpy_test");
    TCase *tcase_core = tcase_create("Core of strcpy_test");
    tcase_add_test(tcase_core, strcpy_test);
    tcase_add_test(tcase_core, strcpy_test1);
    tcase_add_test(tcase_core, strcpy_test2);
    tcase_add_test(tcase_core, strcpy_test3);
    tcase_add_test(tcase_core, strcpy_test4);
    tcase_add_test(tcase_core, strcpy_test5);
    tcase_add_test(tcase_core, strcpy_test6);
    suite_add_tcase(suite, tcase_core);
    return suite;
}
int main(void) {
    int failed_count = 0;
    Suite *suite = strcpy_suite_create();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_NORMAL);
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return (failed_count != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
