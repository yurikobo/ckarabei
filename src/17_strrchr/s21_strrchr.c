// Copyright 2022 21-school.ru

#include "./s21_strrchr.h"

char *s21_strrchr(const char *str, int c) {
    char* res = s21_NULL;
    int i = 0;
    c = c % 256;
    if (c < 0) {
        c = 256 + c;
    }
    for (; *(str + i) && *(str + i) != '\0'; i++) {  // Заменить на strlen
        continue;                                    //
    }                                                //
    while ((*(str + (i - 1)) && *(str + i) != c && i >= 1)) {
        i--;
    }
    if (c == *(str + i)) {
        res = (char*)(str + i);
    }
    return res;
}
