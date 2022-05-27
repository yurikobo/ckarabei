// Copyright 2022 21-school.ru

#include "./s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
    int i = 0;
    for (; *(src + i) && *(src + i) != '\0'; i++) {   // заменить на strlen
        continue;
    }
    for (int j = 0; j != i + 1; j++) {
        *(dest + j) = *(src + j);
    }
    return dest;
}
