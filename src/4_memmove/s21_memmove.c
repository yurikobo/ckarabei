#include <stdio.h>
#include <stdlib.h>

#include "./s21_memmove.h"

/*
Еще одна функция для копирования n символов из src в dest.
*/

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    if (dest < src) {
      char *p1 = dest;
      char *p2 = (char *)src;
      while (n--) {
        *p1++ = *p2++;
      }
    } else {
      char *p1 = dest + n;
      char *p2 = (char *)src + n;
      for (s21_size_t i = 0; i < n; i++) {
        *--p1 = *--p2;
      }
    }
    return dest;
}
