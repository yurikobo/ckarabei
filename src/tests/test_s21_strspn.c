// Copyright 2022 21-school.ru
#include "../s21_string.h"

START_TEST(strspn_test) {
    char str[] = "Hello world\0";
    char str_c[] = "el";
    ck_assert_int_eq(strspn(str, str_c), s21_strspn(str, str_c));
}
END_TEST

START_TEST(strspn_test1) {
    char str1[] = "Hello world\n\0";
    char str1_c[] = "llo";
    ck_assert_int_eq(strspn(str1, str1_c), s21_strspn(str1, str1_c));
}
END_TEST

START_TEST(strspn_test2) {
    char str2[] = "aaaaaaabbbbbbbbbccccccccddddddd\n\0";
    char str2_c[] = "ab";
    ck_assert_int_eq(strspn(str2, str2_c), s21_strspn(str2, str2_c));
}
END_TEST

START_TEST(strspn_test3) {
    char str3[] = "2222111111133333355554444\n\0";
    char str3_c[] = "9";
    ck_assert_int_eq(strspn(str3, str3_c), s21_strspn(str3, str3_c));
}
END_TEST

START_TEST(strspn_test4) {
    char str4[] = "!!!!!asdfa";
    char str4_c[] = "!a";
    ck_assert_int_eq(strspn(str4, str4_c), s21_strspn(str4, str4_c));
}
END_TEST

START_TEST(strspn_test5) {
    char str5[] = "HeLLo WorLd";
    char str5_c[] = "el";
    ck_assert_int_eq(strspn(str5, str5_c), s21_strspn(str5, str5_c));
}
END_TEST

START_TEST(strspn_test6) {
    char str6[] = "hello world\0";
    char str6_c[] = "HELLO WORLD\0";
    ck_assert_int_eq(strspn(str6, str6_c), s21_strspn(str6, str6_c));
}
END_TEST

START_TEST(strspn_test7) {
    char str[] = "Hello world\0";
    char str_c[] = "";
    ck_assert_int_eq(strspn(str, str_c), s21_strspn(str, str_c));
}
END_TEST

START_TEST(strspn_test8) {
    char str1[] = "";
    char str1_c[] = "Hello wold\n\0";
    ck_assert_int_eq(strspn(str1, str1_c), s21_strspn(str1, str1_c));
}
END_TEST

START_TEST(strspn_test9) {
    char str2[] = "a\n\0";
    char str2_c[] = "\n\0";
    ck_assert_int_eq(strspn(str2, str2_c), s21_strspn(str2, str2_c));
}
END_TEST

START_TEST(strspn_test10) {
    char str3[] = " \n\0";
    char str3_c[] = "\0";
    ck_assert_int_eq(strspn(str3, str3_c), s21_strspn(str3, str3_c));
}
END_TEST

START_TEST(strspn_test11) {
    char str4[] = "Hello World";
    char str4_c[] = "123";
    ck_assert_int_eq(strspn(str4, str4_c), s21_strspn(str4, str4_c));
}
END_TEST

START_TEST(strspn_test12) {
    char str5[] = "Hello World\n\0";
    char str5_c[] = "\n\0";
    ck_assert_int_eq(strspn(str5, str5_c), s21_strspn(str5, str5_c));
}
END_TEST

START_TEST(strspn_test13) {
    char str6[] = "Hello World\0";
    char str6_c[] = "d\0";
    ck_assert_int_eq(strspn(str6, str6_c), s21_strspn(str6, str6_c));
}
END_TEST

START_TEST(strspn_test14) {
    char str[] = "Hello wold\0";
    char str_c[] = "d\n";
    ck_assert_int_eq(strspn(str, str_c), s21_strspn(str, str_c));
}
END_TEST


Suite *strspn_suite_create(void) {
    Suite *suite = suite_create("strspn_test");
    TCase *tcase_core = tcase_create("Core of strspn_test");
    tcase_add_test(tcase_core, strspn_test);
    tcase_add_test(tcase_core, strspn_test1);
    tcase_add_test(tcase_core, strspn_test2);
    tcase_add_test(tcase_core, strspn_test3);
    tcase_add_test(tcase_core, strspn_test4);
    tcase_add_test(tcase_core, strspn_test5);
    tcase_add_test(tcase_core, strspn_test6);
    tcase_add_test(tcase_core, strspn_test7);
    tcase_add_test(tcase_core, strspn_test8);
    tcase_add_test(tcase_core, strspn_test9);
    tcase_add_test(tcase_core, strspn_test10);
    tcase_add_test(tcase_core, strspn_test11);
    tcase_add_test(tcase_core, strspn_test12);
    tcase_add_test(tcase_core, strspn_test13);
    tcase_add_test(tcase_core, strspn_test14);
    suite_add_tcase(suite, tcase_core);

    return suite;
}
