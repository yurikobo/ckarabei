// Copyright 2022 21-school.ru

#include "../s21_string.h"

START_TEST(strncat_test) {
    char str[10] = "Hello ";
    char s21_str[10] = "Hello ";
    char text[] = "el";
    ck_assert_str_eq(strncat(str, text, _i), s21_strncat(s21_str, text, _i));
}
END_TEST

START_TEST(strncat_test1) {
    char str1[8] = "d\n\0";
    char s21_str1[8] = "d\n\0";
    char text[] = "llo";
    ck_assert_str_eq(strncat(str1, text, _i), s21_strncat(s21_str1, text, _i));
}
END_TEST

START_TEST(strncat_test2) {
    char str2[2] = "";
    char s21_str2[2] = "";
    char text[] = "\0";
    ck_assert_str_eq(strncat(str2, text, _i), s21_strncat(s21_str2, text, _i));
}
END_TEST

START_TEST(strncat_test3) {
    char str3[49] = "Hello world";
    char s21_str3[49] = "Hello world";
    char text[] = "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    ck_assert_str_eq(strncat(str3, text, _i), s21_strncat(s21_str3, text, _i));
}
END_TEST

START_TEST(strncat_test4) {
    char str4[14] = "!!!!!asdfa";
    char s21_str4[14] = "!!!!!asdfa";
    char text[] = "";
    ck_assert_str_eq(strncat(str4, text, _i), s21_strncat(s21_str4, text, _i));
}
END_TEST

START_TEST(strncat_test5) {
    char str5[10] = "";
    char s21_str5[10] = "";
    char text[] = "asdasdasdasdasdasddsadasdel";
    ck_assert_str_eq(strncat(str5, text, _i), s21_strncat(s21_str5, text, _i));
}
END_TEST

Suite *strncat_suite_create(void) {
    Suite *suite = suite_create("strncat_test");
    TCase *tcase_core = tcase_create("Core of strncat_test");
    tcase_add_loop_test(tcase_core, strncat_test, 0, 10);
    tcase_add_loop_test(tcase_core, strncat_test1, 0, 10);
    tcase_add_loop_test(tcase_core, strncat_test2, 0, 10);
    tcase_add_loop_test(tcase_core, strncat_test3, 0, 10);
    tcase_add_loop_test(tcase_core, strncat_test4, 0, 10);
    tcase_add_loop_test(tcase_core, strncat_test5, 0, 10);
    suite_add_tcase(suite, tcase_core);

    return suite;
}
