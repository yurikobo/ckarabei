#include "./s21_strncat.h"
/*
Добавляет строку, на которую указывает src, в конец строки, на которую
указывает dest, длиной до n символов.
*/

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char * p1 = dest, *p2 = (char*) src;
  while (*p1 != '\0') {
    p1++;
  }
  while (*p2 != '\0' && n--) {
    *p1++ = *(p2++);
  }
  *p1 = '\0';

  return dest;
}
