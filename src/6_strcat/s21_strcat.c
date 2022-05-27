// Copyright 2022 cookiebe@student.21-school.ru
#include "./s21_strcat.h"

/*
Функция strcat добавляет в строку, на которую указывает аргумент dest,
строку, на которую указывает аргумент src. Символ конца строки помещается
в конце объединенных строк.
*/

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
