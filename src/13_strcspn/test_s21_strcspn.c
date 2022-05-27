// Copyright 2022 21-school.ru

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>
#include "./s21_string.h"

START_TEST(strcspn_test) {
    char str[] = "Hello world\0";
    char str_c[] = "el";
    ck_assert_int_eq(strcspn(str, str_c), s21_strcspn(str, str_c));
}
END_TEST

START_TEST(strcspn_test1) {
    char str1[] = "Hello world\n\0";
    char str1_c[] = "llo";
    ck_assert_int_eq(strcspn(str1, str1_c), s21_strcspn(str1, str1_c));
}
END_TEST

START_TEST(strcspn_test2) {
    char str2[] = "aaaaaaabbbbbbbbbccccccccddddddd\n\0";
    char str2_c[] = "ab";
    ck_assert_int_eq(strcspn(str2, str2_c), s21_strcspn(str2, str2_c));
}
END_TEST

START_TEST(strcspn_test3) {
    char str3[] = "2222111111133333355554444\n\0";
    char str3_c[] = "9";
    ck_assert_int_eq(strcspn(str3, str3_c), s21_strcspn(str3, str3_c));
}
END_TEST

START_TEST(strcspn_test4) {
    char str4[] = "!!!!!asdfa";
    char str4_c[] = "!a";
    ck_assert_int_eq(strcspn(str4, str4_c), s21_strcspn(str4, str4_c));
}
END_TEST

START_TEST(strcspn_test5) {
    char str5[] = "HeLLo WorLd";
    char str5_c[] = "el";
    ck_assert_int_eq(strcspn(str5, str5_c), s21_strcspn(str5, str5_c));
}
END_TEST

START_TEST(strcspn_test6) {
    char str6[] = "hello world\0";
    char str6_c[] = "HELLO WORLD\0";
    ck_assert_int_eq(strcspn(str6, str6_c), s21_strcspn(str6, str6_c));
}
END_TEST

START_TEST(strcspn_test7) {
    char str[] = "Hello world\0";
    char str_c[] = "";
    ck_assert_int_eq(strcspn(str, str_c), s21_strcspn(str, str_c));
}
END_TEST

START_TEST(strcspn_test8) {
    char str1[] = "";
    char str1_c[] = "Hello wold\n\0";
    ck_assert_int_eq(strcspn(str1, str1_c), s21_strcspn(str1, str1_c));
}
END_TEST

START_TEST(strcspn_test9) {
    char str2[] = "a\n\0";
    char str2_c[] = "\n\0";
    ck_assert_int_eq(strcspn(str2, str2_c), s21_strcspn(str2, str2_c));
}
END_TEST

START_TEST(strcspn_test10) {
    char str3[] = " \n\0";
    char str3_c[] = "\0";
    ck_assert_int_eq(strcspn(str3, str3_c), s21_strcspn(str3, str3_c));
}
END_TEST

START_TEST(strcspn_test11) {
    char str4[] = "Hello World";
    char str4_c[] = "123";
    ck_assert_int_eq(strcspn(str4, str4_c), s21_strcspn(str4, str4_c));
}
END_TEST

START_TEST(strcspn_test12) {
    char str5[] = "Hello World\n\0";
    char str5_c[] = "\n\0";
    ck_assert_int_eq(strcspn(str5, str5_c), s21_strcspn(str5, str5_c));
}
END_TEST

START_TEST(strcspn_test13) {
    char str6[] = "Hello World\0";
    char str6_c[] = "d\0";
    ck_assert_int_eq(strcspn(str6, str6_c), s21_strcspn(str6, str6_c));
}
END_TEST

START_TEST(strcspn_test14) {
    char str[] = "Hello wold\0";
    char str_c[] = "d\n";
    ck_assert_int_eq(strcspn(str, str_c), s21_strcspn(str, str_c));
}
END_TEST


Suite *strcspn_suite_create(void) {
    Suite *suite = suite_create("strcspn_test");
    TCase *tcase_core = tcase_create("Core of strcspn_test");
    tcase_add_test(tcase_core, strcspn_test);
    tcase_add_test(tcase_core, strcspn_test1);
    tcase_add_test(tcase_core, strcspn_test2);
    tcase_add_test(tcase_core, strcspn_test3);
    tcase_add_test(tcase_core, strcspn_test4);
    tcase_add_test(tcase_core, strcspn_test5);
    tcase_add_test(tcase_core, strcspn_test6);
    tcase_add_test(tcase_core, strcspn_test7);
    tcase_add_test(tcase_core, strcspn_test8);
    tcase_add_test(tcase_core, strcspn_test9);
    tcase_add_test(tcase_core, strcspn_test10);
    tcase_add_test(tcase_core, strcspn_test11);
    tcase_add_test(tcase_core, strcspn_test12);
    tcase_add_test(tcase_core, strcspn_test13);
    tcase_add_test(tcase_core, strcspn_test14);
    suite_add_tcase(suite, tcase_core);

    return suite;
}
int main(void) {
    int failed_count = 0;
    Suite *suite = strcspn_suite_create();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_NORMAL);
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return (failed_count != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
