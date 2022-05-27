#include <stdlib.h>
#include <stdio.h>
#include "./s21_string.h"

void *s21_to_lower(const char *str) {
    int i = 0;
    for (; *(str + i) && *(str + i) != '\0'; i++) {   // заменить на strlen
        continue;
    }
    char *cpy = malloc(sizeof(char) * (i + 1));
    for (int j = 0; j != i + 1; j++) {
        if ('A' <= *(str + j) && *(str + j) <= 'Z') {
            *(cpy + j) = *(str + j) + 32;
        } else {
            *(cpy + j) = *(str + j);
        }

    }
    return cpy;
}

