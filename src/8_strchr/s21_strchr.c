// Copyright 2022 21-school.ru

#include "./s21_strchr.h"

char *s21_strchr(const char *str, int c) {
    char* res = s21_NULL;
    int i = 0;
    c = c % 256;
    if (c < 0) {
        c = 256 + c;
    }
    while (*(str + i) && *(str + i) != c) {
        i++;
    }
    if (c == *(str + i)) {
        res = (char*)(str + i);
    }
    return res;
}
