#include <stdio.h>
#include <stdlib.h>

#include "./s21_memcpy.h"

/*
Копирует n символов из src в dest. При этом если есть наложения строк,
функция не сработает
*/

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *p1 = dest;
    char *p2 = (char *)src;
    while (n--) {
      *p1++ = *p2++;
    }
    return dest;
}
