// Copyright 2022 21-school.ru

#include "../s21_string.h"

START_TEST(strncpy_test) {
    char s21_src[] = "Hello world\0";
    char s21_dest[30];
    char str_dest[30];
    s21_strncpy(s21_dest, s21_src, _i);
    strncpy(str_dest, s21_src, _i);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

START_TEST(strncpy_test1) {
    char s21_src[] = "Hello world\n\0";
    char s21_dest[30];
    char str_dest[30];
    s21_strncpy(s21_dest, s21_src, _i);
    strncpy(str_dest, s21_src, _i);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

START_TEST(strncpy_test2) {
    char s21_src[] = "a\n\0";
    char s21_dest[30];
    char str_dest[30];
    s21_strncpy(s21_dest, s21_src, _i);
    strncpy(str_dest, s21_src, _i);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

START_TEST(strncpy_test3) {
    char s21_src[] = " \n\0";
    char s21_dest[30];
    char str_dest[30];
    s21_strncpy(s21_dest, s21_src, _i);
    strncpy(str_dest, s21_src, _i);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

START_TEST(strncpy_test4) {
    char s21_src[] = " \0";
    char s21_dest[30];
    char str_dest[30];
    s21_strncpy(s21_dest, s21_src, _i);
    strncpy(str_dest, s21_src, _i);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

START_TEST(strncpy_test5) {
    char s21_src[] = "\n\0";
    char s21_dest[30];
    char str_dest[30];
    s21_strncpy(s21_dest, s21_src, _i);
    strncpy(str_dest, s21_src, _i);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

START_TEST(strncpy_test6) {
    char s21_src[] = "\0";
    char s21_dest[30];
    char str_dest[30];
    s21_strncpy(s21_dest, s21_src, _i);
    strncpy(str_dest, s21_src, _i);
    ck_assert_str_eq(s21_dest, str_dest);
}
END_TEST

Suite *strncpy_suite_create(void) {
    Suite *suite = suite_create("strncpy_test");
    TCase *tcase_core = tcase_create("Core of strncpy_test");
    tcase_add_loop_test(tcase_core, strncpy_test, 14, 31);
    tcase_add_loop_test(tcase_core, strncpy_test1, 14, 31);
    tcase_add_loop_test(tcase_core, strncpy_test2, 4, 31);
    tcase_add_loop_test(tcase_core, strncpy_test3, 4, 31);
    tcase_add_loop_test(tcase_core, strncpy_test4, 3, 31);
    tcase_add_loop_test(tcase_core, strncpy_test5, 3, 31);
    tcase_add_loop_test(tcase_core, strncpy_test6, 2, 31);
    suite_add_tcase(suite, tcase_core);
    return suite;
}
