#ifndef SRC_TESTS_INCLUDES_S21_TESTS_H_
#define SRC_TESTS_INCLUDES_S21_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../s21_string.h"

// Suite *suite_atoi(void);
// Suite *suite_sprintf(void);
// Suite *suite_insert(void);
// Suite *suite_memchr(void);
// Suite *suite_memcmp(void);
Suite *memcpy_suite_create(void);
Suite *memmove_suite_create(void);
// Suite *suite_memset(void);
Suite *strcat_suite_create(void);
Suite *strchr_suite_create(void);
Suite *strcmp_suite_create(void);
Suite *strcpy_suite_create(void);
Suite *strcspn_suite_create(void);
// Suite *suite_strerror(void);
Suite *strlen_suite_create(void);
Suite *strncat_suite_create(void);
// Suite *suite_strncmp(void);
Suite *strncpy_suite_create(void);
// Suite *suite_strntollu(void);
// Suite *suite_strpbrk(void);
Suite *strrchr_suite_create(void);
Suite *strspn_suite_create(void);
Suite *strstr_suite_create(void);
// Suite *suite_strtok(void);
// Suite *suite_to_upper(void);
Suite *to_lower_suite_create(void);
// Suite *suite_trim(void);
// Suite *suite_sscanf(void);
// Suite *suite_strtold(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif  // SRC_TESTS_INCLUDES_S21_TESTS_H_