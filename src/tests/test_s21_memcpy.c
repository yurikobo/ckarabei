// Copyright 2022 21-school.ru

#include "../s21_string.h"

START_TEST(memcpy_test) {
    char str[] = "Hello ";
    char s21_str[] = "Hello ";
    char text[] = "el";
    ck_assert_str_eq(memcpy(str, text, _i), s21_memcpy(s21_str, text, _i));
}
END_TEST

START_TEST(memcpy_test1) {
    char str1[] = "d\n\0";
    char s21_str1[] = "d\n\0";
    char text[] = "llo";
    ck_assert_str_eq(memcpy(str1, text, _i), s21_memcpy(s21_str1, text, _i));
}
END_TEST

START_TEST(memcpy_test2) {
    char str2[11] = "";
    char s21_str2[11] = "";
    char text[] = "\0";
    ck_assert_str_eq(memcpy(str2, text, _i), s21_memcpy(s21_str2, text, _i));
}
END_TEST

START_TEST(memcpy_test3) {
    char str3[] = "Hello world";
    char s21_str3[] = "Hello world";
    char text[] = "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    ck_assert_str_eq(memcpy(str3, text, _i), s21_memcpy(s21_str3, text, _i));
}
END_TEST

START_TEST(memcpy_test4) {
    char str4[14] = "!!!!!asdfa";
    char s21_str4[14] = "!!!!!asdfa";
    char text[] = "";
    ck_assert_str_eq(memcpy(str4, text, _i), s21_memcpy(s21_str4, text, _i));
}
END_TEST

START_TEST(memcpy_test5) {
    char str5[6] = "";
    char s21_str5[6] = "";
    char text[] = "el";
    ck_assert_str_eq(memcpy(str5, text, _i), s21_memcpy(s21_str5, text, _i));
}
END_TEST

Suite *memcpy_suite_create(void) {
    Suite *suite = suite_create("memcpy_test");
    TCase *tcase_core = tcase_create("Core of memcpy_test");
    tcase_add_loop_test(tcase_core, memcpy_test, 0, 8);
    tcase_add_loop_test(tcase_core, memcpy_test1, 0, 2);
    tcase_add_loop_test(tcase_core, memcpy_test2, 0, 10);
    tcase_add_loop_test(tcase_core, memcpy_test3, 0, 12);
    tcase_add_loop_test(tcase_core, memcpy_test4, 0, 14);
    tcase_add_loop_test(tcase_core, memcpy_test5, 0, 5);
    suite_add_tcase(suite, tcase_core);

    return suite;
}
