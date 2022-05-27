#include "./s21_sprintf.h"

// Функция вычисляет длину строки str, не включая завершающий нулевой символ.
s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for (; str[len] != 0; len++) continue;
    return len;
}
// Функция добавляет в строку dest строку src.
char *s21_strcat(char *dest, const char *src) {
  char * p1 = dest, *p2 = (char*) src;
  while (*p1 != '\0') {
    p1++;
  }
  while (*p2 != '\0') {
    *p1++ = *(p2++);
  }
  *p1 = '\0';
  return dest;
}
// временная
char *s21_strcpy(char *dest, const char *src) {
    int len = s21_strlen(src);
    for (int i = 0; i < len; i++)
        dest[i] = src[i];
    return dest;
}
