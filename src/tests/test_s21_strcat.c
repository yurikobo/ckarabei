// Copyright 2022 21-school.ru

#include "../s21_string.h"

START_TEST(strcat_test) {
    char str[10] = "Hello ";
    char s21_str[10] = "Hello ";
    char text[] = "el";
    ck_assert_str_eq(strcat(str, text), s21_strcat(s21_str, text));
}
END_TEST

START_TEST(strcat_test1) {
    char str1[8] = "d\n\0";
    char s21_str1[8] = "d\n\0";
    char text[] = "llo";
    ck_assert_str_eq(strcat(str1, text), s21_strcat(s21_str1, text));
}
END_TEST

START_TEST(strcat_test2) {
    char str2[2] = "";
    char s21_str2[2] = "";
    char text[] = "\0";
    ck_assert_str_eq(strcat(str2, text), s21_strcat(s21_str2, text));
}
END_TEST

START_TEST(strcat_test3) {
    char str3[49] = "Hello world";
    char s21_str3[49] = "Hello world";
    char text[] = "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    ck_assert_str_eq(strcat(str3, text), s21_strcat(s21_str3, text));
}
END_TEST

START_TEST(strcat_test4) {
    char str4[14] = "!!!!!asdfa";
    char s21_str4[14] = "!!!!!asdfa";
    char text[] = "";
    ck_assert_str_eq(strcat(str4, text), s21_strcat(s21_str4, text));
}
END_TEST

START_TEST(strcat_test5) {
    char str5[6] = "";
    char s21_str5[6] = "";
    char text[] = "el";
    ck_assert_str_eq(strcat(str5, text), s21_strcat(s21_str5, text));
}
END_TEST

Suite *strcat_suite_create(void) {
    Suite *suite = suite_create("strcat_test");
    TCase *tcase_core = tcase_create("Core of strcat_test");
    tcase_add_test(tcase_core, strcat_test);
    tcase_add_test(tcase_core, strcat_test1);
    tcase_add_test(tcase_core, strcat_test2);
    tcase_add_test(tcase_core, strcat_test3);
    tcase_add_test(tcase_core, strcat_test4);
    tcase_add_test(tcase_core, strcat_test5);
    suite_add_tcase(suite, tcase_core);

    return suite;
}
