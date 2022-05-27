// Copyright 2022 21-school.ru

#include "../s21_string.h"

START_TEST(strchr_test) {
    char str[] = "Hello world\0";
    ck_assert_pstr_eq(strchr(str, _i), s21_strchr(str, _i));
}
END_TEST

START_TEST(strchr_test1) {
    char str1[] = "Hello world\n\0";
    ck_assert_pstr_eq(strchr(str1, _i), s21_strchr(str1, _i));
}
END_TEST

START_TEST(strchr_test2) {
    char str2[] = "a\n\0";
    ck_assert_pstr_eq(strchr(str2, _i), s21_strchr(str2, _i));
}
END_TEST

START_TEST(strchr_test3) {
    char str3[] = " \n\0";
    ck_assert_pstr_eq(strchr(str3, _i), s21_strchr(str3, _i));
}
END_TEST

START_TEST(strchr_test4) {
    char str4[] = " \0";
    ck_assert_pstr_eq(strchr(str4, _i), s21_strchr(str4, _i));
}
END_TEST

START_TEST(strchr_test5) {
    char str5[] = "\n\0";
    ck_assert_pstr_eq(strchr(str5, _i), s21_strchr(str5, _i));
}
END_TEST

START_TEST(strchr_test6) {
    char str6[] = "\0";
    ck_assert_pstr_eq(strchr(str6, _i), s21_strchr(str6, _i));
}
END_TEST


Suite *strchr_suite_create(void) {
    Suite *suite = suite_create("strchr_test");
    TCase *tcase_core = tcase_create("Core of strchr_test");
    tcase_add_loop_test(tcase_core, strchr_test, -1000, 1000);
    tcase_add_loop_test(tcase_core, strchr_test1, -1000, 1000);
    tcase_add_loop_test(tcase_core, strchr_test2, -1000, 1000);
    tcase_add_loop_test(tcase_core, strchr_test3, -1000, 1000);
    tcase_add_loop_test(tcase_core, strchr_test4, -1000, 1000);
    tcase_add_loop_test(tcase_core, strchr_test5, -1000, 1000);
    tcase_add_loop_test(tcase_core, strchr_test6, -1000, 1000);
    suite_add_tcase(suite, tcase_core);

    return suite;
}
