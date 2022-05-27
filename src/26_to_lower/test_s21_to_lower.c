#include <stdlib.h>
#include <check.h>
#include "./s21_to_lower.h"

// int main() {
//     char str1[1000000] = "THIS IS UPPER REGISTER";
//     char *str_l1 = s21_to_lower(str1);
//     printf("1.%s\n", str_l1);
//     free(str_l1);
//     char str2[] = "ThIs Is MiXeD rEgIsTeR";
//     char *str_l2 = s21_to_lower(str2);
//     printf("2.%s\n", str_l2);
//     free(str_l2);
//     char str3[] = "this is lower register";
//     char *str_l3 = s21_to_lower(str3);
//     printf("3.%s\n", str_l3);
//     free(str_l3);
//     char str4[] = "123";
//     char *str_l4 = s21_to_lower(str4);
//     printf("4.%s\n", str_l4);
//     free(str_l4);
//     char str5[] = "!@#";
//     char *str_l5 = s21_to_lower(str5);
//     printf("5.%s\n", str_l5);
//     free(str_l5);
//     char str6[] = "\0";
//     char *str_l6 = s21_to_lower(str6);
//     printf("6.%s\n", str_l6);
//     free(str_l6);
//     char str7[] = "";
//     char *str_l7 = s21_to_lower(str7);
//     printf("7.%s\n", str_l7);
//     free(str_l7);
//     return 0;
// }


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

int main(void) {
    int failed_count = 0;
    Suite *suite = to_lower_suite_create();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_NORMAL);
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return (failed_count != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
