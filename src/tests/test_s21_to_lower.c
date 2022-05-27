// Copyright 2022 21-school.ru
#include "../s21_string.h"

START_TEST(to_lower_test1) {
    char str1[] = "THIS IS UPPER REGISTER";
    char *str_l1 = s21_to_lower(str1);
    ck_assert_str_eq(str_l1, "this is upper register");
    free(str_l1);
}
END_TEST

START_TEST(to_lower_test2) {
    char str1[] = "ThIs Is MiXeD rEgIsTeR";
    char *str_l1 = s21_to_lower(str1);
    ck_assert_str_eq(str_l1, "this is mixed register");
    free(str_l1);
}
END_TEST

START_TEST(to_lower_test3) {
    char str1[] = "this is lower register";
    char *str_l1 = s21_to_lower(str1);
    ck_assert_str_eq(str_l1, "this is lower register");
    free(str_l1);
}
END_TEST

START_TEST(to_lower_test4) {
    char str1[] = "123";
    char *str_l1 = s21_to_lower(str1);
    ck_assert_str_eq(str_l1, "123");
    free(str_l1);
}
END_TEST

START_TEST(to_lower_test5) {
    char str1[] = "!@#";
    char *str_l1 = s21_to_lower(str1);
    ck_assert_str_eq(str_l1, "!@#");
    free(str_l1);
}
END_TEST

START_TEST(to_lower_test6) {
    char str1[] = "\0";
    char *str_l1 = s21_to_lower(str1);
    ck_assert_str_eq(str_l1, "\0");
    free(str_l1);
}
END_TEST

START_TEST(to_lower_test7) {
    char str1[] = "";
    char *str_l1 = s21_to_lower(str1);
    ck_assert_str_eq(str_l1, "");
    free(str_l1);
}
END_TEST

Suite *to_lower_suite_create(void) {
    Suite *suite = suite_create("to_lower_test");
    TCase *tcase_core = tcase_create("Core of to_lower_test");
    tcase_add_test(tcase_core, to_lower_test1);
    tcase_add_test(tcase_core, to_lower_test2);
    tcase_add_test(tcase_core, to_lower_test3);
    tcase_add_test(tcase_core, to_lower_test4);
    tcase_add_test(tcase_core, to_lower_test5);
    tcase_add_test(tcase_core, to_lower_test6);
    tcase_add_test(tcase_core, to_lower_test7);
    suite_add_tcase(suite, tcase_core);
    return suite;
}
