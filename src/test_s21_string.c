// #include "tests_includes/s21_tests.h"
// #include <locale.h>
// #include <check.h>

// int main(void) {
//     run_tests();

//     return 0;
// }

// void run_testcase(Suite *testcase) {
//     setlocale(LC_ALL, "");
//     static int counter_testcase = 1;

//     if (counter_testcase > 1)
//         putchar('\n');
//     printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
//     counter_testcase++;

//     SRunner *sr = srunner_create(testcase);

//     srunner_set_fork_status(sr, CK_NOFORK);
//     srunner_run_all(sr, CK_NORMAL);

//     srunner_free(sr);
//     sleep(1);
// }

// void run_tests(void) {
//     Suite *list_cases[] = {
//         memcpy_suite_create(), memmove_suite_create(), strcat_suite_create(),
//         strncat_suite_create(), strchr_suite_create(), strcmp_suite_create(),
//         strcpy_suite_create(), strncpy_suite_create(), strcspn_suite_create(),
//         strrchr_suite_create(), strspn_suite_create(), strstr_suite_create(),
//         to_lower_suite_create(), strlen_suite_create(),s21_NULL};

//     for (Suite **current_testcase = list_cases; *current_testcase != s21_NULL;
//          current_testcase++) {
//         run_testcase(*current_testcase);
//     }
// }

int main() {}