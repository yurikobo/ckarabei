#include <stdlib.h>
#include <stdio.h>
#include "./s21_to_lower.h"

void *s21_to_lower(const char *str) {
    int i = 0;
    char *cpy = malloc(sizeof(str));
    for (; *(str + i) && *(str + i) != '\0'; i++) {   // заменить на strlen
        continue;
    }
    for (int j = 0; j != i + 1; j++) {
        if ('A' <= *(str + j) && *(str + j) <= 'Z') {
            *(cpy + j) = *(str + j) + 32;
        } else {
            *(cpy + j) = *(str + j);
        }
    }
    return cpy;
}

