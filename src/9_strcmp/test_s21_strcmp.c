// Copyright 2022 21-school.ru

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>
#include "./s21_string.h"

START_TEST(strcmp_test) {
    char str[] = "Hello world\0";
    char str_c[] = "Hello world\0";
    ck_assert_int_eq(strcmp(str, str_c), s21_strcmp(str, str_c));
}
END_TEST

START_TEST(strcmp_test1) {
    char str1[] = "Hello world\n\0";
    char str1_c[] = "Hello world\n\0";
    ck_assert_int_eq(strcmp(str1, str1_c), s21_strcmp(str1, str1_c));
}
END_TEST

START_TEST(strcmp_test2) {
    char str2[] = "a\n\0";
    char str2_c[] = "a\n\0";
    ck_assert_int_eq(strcmp(str2, str2_c), s21_strcmp(str2, str2_c));
}
END_TEST

START_TEST(strcmp_test3) {
    char str3[] = " \n\0";
    char str3_c[] = " \n\0";
    ck_assert_int_eq(strcmp(str3, str3_c), s21_strcmp(str3, str3_c));
}
END_TEST

START_TEST(strcmp_test4) {
    char str4[] = " \0";
    char str4_c[] = " \0";
    ck_assert_int_eq(strcmp(str4, str4_c), s21_strcmp(str4, str4_c));
}
END_TEST

START_TEST(strcmp_test5) {
    char str5[] = "\n\0";
    char str5_c[] = "\n\0";
    ck_assert_int_eq(strcmp(str5, str5_c), s21_strcmp(str5, str5_c));
}
END_TEST

START_TEST(strcmp_test6) {
    char str6[] = "\0";
    char str6_c[] = "\0";
    ck_assert_int_eq(strcmp(str6, str6_c), s21_strcmp(str6, str6_c));
}
END_TEST

START_TEST(strcmp_test7) {
    char str[] = "Hello world\0";
    char str_c[] = "Hello wold\0";
    ck_assert_int_eq(strcmp(str, str_c), s21_strcmp(str, str_c));
}
END_TEST

START_TEST(strcmp_test8) {
    char str1[] = "Hello world\n\0";
    char str1_c[] = "Hello wold\n\0";
    ck_assert_int_eq(strcmp(str1, str1_c), s21_strcmp(str1, str1_c));
}
END_TEST

START_TEST(strcmp_test9) {
    char str2[] = "a\n\0";
    char str2_c[] = "1\n\0";
    ck_assert_int_eq(strcmp(str2, str2_c), s21_strcmp(str2, str2_c));
}
END_TEST

START_TEST(strcmp_test10) {
    char str3[] = " \n\0";
    char str3_c[] = "\n\0";
    ck_assert_int_eq(strcmp(str3, str3_c), s21_strcmp(str3, str3_c));
}
END_TEST

START_TEST(strcmp_test11) {
    char str4[] = " \0";
    char str4_c[] = "\0";
    ck_assert_int_eq(strcmp(str4, str4_c), s21_strcmp(str4, str4_c));
}
END_TEST

START_TEST(strcmp_test12) {
    char str5[] = "\n\0";
    char str5_c[] = "\0";
    ck_assert_int_eq(strcmp(str5, str5_c), s21_strcmp(str5, str5_c));
}
END_TEST

START_TEST(strcmp_test13) {
    char str6[] = "\0";
    char str6_c[] = "";
    ck_assert_int_eq(strcmp(str6, str6_c), s21_strcmp(str6, str6_c));
}
END_TEST

START_TEST(strcmp_test14) {
    char str[] = "Hello wold\0";
    char str_c[] = "Hello world\0";
    ck_assert_int_eq(strcmp(str, str_c), s21_strcmp(str, str_c));
}
END_TEST

START_TEST(strcmp_test15) {
    char str1[] = "Hello wold\n\0";
    char str1_c[] = "Hello world\n\0";
    ck_assert_int_eq(strcmp(str1, str1_c), s21_strcmp(str1, str1_c));
}
END_TEST

START_TEST(strcmp_test16) {
    char str2[] = "\n\0";
    char str2_c[] = "a\n\0";
    ck_assert_int_eq(strcmp(str2, str2_c), s21_strcmp(str2, str2_c));
}
END_TEST

START_TEST(strcmp_test17) {
    char str3[] = "\n\0";
    char str3_c[] = " \n\0";
    ck_assert_int_eq(strcmp(str3, str3_c), s21_strcmp(str3, str3_c));
}
END_TEST

START_TEST(strcmp_test18) {
    char str4[] = "\0";
    char str4_c[] = " \0";
    ck_assert_int_eq(strcmp(str4, str4_c), s21_strcmp(str4, str4_c));
}
END_TEST

START_TEST(strcmp_test19) {
    char str5[] = "\0";
    char str5_c[] = "\n\0";
    ck_assert_int_eq(strcmp(str5, str5_c), s21_strcmp(str5, str5_c));
}
END_TEST

START_TEST(strcmp_test20) {
    char str6[] = "";
    char str6_c[] = "\0";
    ck_assert_int_eq(strcmp(str6, str6_c), s21_strcmp(str6, str6_c));
}
END_TEST

Suite *strcmp_suite_create(void) {
    Suite *suite = suite_create("strcmp_test");
    TCase *tcase_core = tcase_create("Core of strcmp_test");
    tcase_add_test(tcase_core, strcmp_test);
    tcase_add_test(tcase_core, strcmp_test1);
    tcase_add_test(tcase_core, strcmp_test2);
    tcase_add_test(tcase_core, strcmp_test3);
    tcase_add_test(tcase_core, strcmp_test4);
    tcase_add_test(tcase_core, strcmp_test5);
    tcase_add_test(tcase_core, strcmp_test6);
    tcase_add_test(tcase_core, strcmp_test7);
    tcase_add_test(tcase_core, strcmp_test8);
    tcase_add_test(tcase_core, strcmp_test9);
    tcase_add_test(tcase_core, strcmp_test10);
    tcase_add_test(tcase_core, strcmp_test11);
    tcase_add_test(tcase_core, strcmp_test12);
    tcase_add_test(tcase_core, strcmp_test13);
    tcase_add_test(tcase_core, strcmp_test14);
    tcase_add_test(tcase_core, strcmp_test15);
    tcase_add_test(tcase_core, strcmp_test16);
    tcase_add_test(tcase_core, strcmp_test17);
    tcase_add_test(tcase_core, strcmp_test18);
    tcase_add_test(tcase_core, strcmp_test19);
    tcase_add_test(tcase_core, strcmp_test20);
    suite_add_tcase(suite, tcase_core);

    return suite;
}
int main(void) {
    int failed_count = 0;
    Suite *suite = strcmp_suite_create();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_NORMAL);
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return (failed_count != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
