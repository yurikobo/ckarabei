// Copyright 2022 21-school.ru

#include "./s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t i;
    for (i = 0; i < n; ) {
        *(dest + i) = *(src + i);
        i++;
    }
    return dest;
}
