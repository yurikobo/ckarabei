// Copyright 2022 21-school.ru

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>
#include "./s21_memmove.h"

START_TEST(memmove_test) {
    char text[] = "el";
    char *str = text - 10;
    char *s21_str = text - 10;
    ck_assert_str_eq(memmove(str, text, _i), s21_memmove(s21_str, text, _i));
}
END_TEST

START_TEST(memmove_test1) {
    char str1[] = "d\n\0";
    char s21_str1[] = "d\n\0";
    char text[] = "llo";
    ck_assert_str_eq(memmove(str1, text, _i), s21_memmove(s21_str1, text, _i));
}
END_TEST

START_TEST(memmove_test2) {
    char str2[11] = "";
    char s21_str2[11] = "";
    char text[] = "\0";
    ck_assert_str_eq(memmove(str2, text, _i), s21_memmove(s21_str2, text, _i));
}
END_TEST

START_TEST(memmove_test3) {
    char text[] = "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    char *str3 = text + 3;
    char *s21_str3 = text + 3;
    ck_assert_str_eq(memmove(str3, text, _i), s21_memmove(s21_str3, text, _i));
}
END_TEST

START_TEST(memmove_test4) {
    char str4[14] = "!!!!!asdfa";
    char s21_str4[14] = "!!!!!asdfa";
    char text[] = "";
    ck_assert_str_eq(memmove(str4, text, _i), s21_memmove(s21_str4, text, _i));
}
END_TEST

START_TEST(memmove_test5) {
    char str5[6] = "";
    char s21_str5[6] = "";
    char text[] = "el";
    ck_assert_str_eq(memmove(str5, text, _i), s21_memmove(s21_str5, text, _i));
}
END_TEST

Suite *memmove_suite_create(void) {
    Suite *suite = suite_create("memmove_test");
    TCase *tcase_core = tcase_create("Core of memmove_test");
    tcase_add_loop_test(tcase_core, memmove_test, 0, 8);
    tcase_add_loop_test(tcase_core, memmove_test1, 0, 2);
    tcase_add_loop_test(tcase_core, memmove_test2, 0, 10);
    tcase_add_loop_test(tcase_core, memmove_test3, 0, 12);
    tcase_add_loop_test(tcase_core, memmove_test4, 0, 14);
    tcase_add_loop_test(tcase_core, memmove_test5, 0, 5);
    suite_add_tcase(suite, tcase_core);

    return suite;
}
int main(void) {
    int failed_count = 0;
    Suite *suite = memmove_suite_create();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_NORMAL);
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return (failed_count != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
