// Copyright 2022 21-school.ru

#include "../s21_string.h"

START_TEST(strlen_test) {
    char str[] = "Hello world\0";
    ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_test1) {
    char str1[] = "Hello world\n\0";
    ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_test2) {
    char str2[] = "a\n\0";
    ck_assert_int_eq(strlen(str2), s21_strlen(str2));
}
END_TEST

START_TEST(strlen_test3) {
    char str3[] = " \n\0";
    ck_assert_int_eq(strlen(str3), s21_strlen(str3));
}
END_TEST

START_TEST(strlen_test4) {
    char str4[] = " \0";
    ck_assert_int_eq(strlen(str4), s21_strlen(str4));
}
END_TEST

START_TEST(strlen_test5) {
    char str5[] = "\n\0";
    ck_assert_int_eq(strlen(str5), s21_strlen(str5));
}
END_TEST

START_TEST(strlen_test6) {
    char str6[] = "\0";
    ck_assert_int_eq(strlen(str6), s21_strlen(str6));
}
END_TEST


Suite *strlen_suite_create(void) {
    Suite *suite = suite_create("strlen_test");
    TCase *tcase_core = tcase_create("Core of strlen_test");
    tcase_add_test(tcase_core, strlen_test);
    tcase_add_test(tcase_core, strlen_test1);
    tcase_add_test(tcase_core, strlen_test2);
    tcase_add_test(tcase_core, strlen_test3);
    tcase_add_test(tcase_core, strlen_test4);
    tcase_add_test(tcase_core, strlen_test5);
    tcase_add_test(tcase_core, strlen_test6);
    suite_add_tcase(suite, tcase_core);

    return suite;
}
