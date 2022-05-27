#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#define s21_NULL (void*)0
#define s21_size_t unsigned long long
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1 by elwoodju
void *s21_memchr(const void *str, int c, s21_size_t n);

//2 by karthwas
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

//3 by cookiebe
void *s21_memcpy(void *dest, const void *src, s21_size_t n);

//4 by cookiebe
void *s21_memmove(void *dest, const void *src, s21_size_t n);

//5 by cookiebe
void *s21_memset(void *str, int c, s21_size_t n);

//6 by cookiebe
char *s21_strcat(char *dest, const char *src);

//8 yurikobo
char *s21_strchr(const char *str, int c);

//7 cookiebe
char *s21_strncat(char *dest, const char *src, s21_size_t n);

//9 elwoodju
int s21_strcmp(const char *str1, const char *str2);

//10 elwoodju
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

//11 yurikobo
char *s21_strcpy(char *dest, const char *src);

//12 yurikobo
char *s21_strncpy(char *dest, const char *src, s21_size_t n);

//13 elwoodju
s21_size_t s21_strcspn(const char *str1, const char *str2);

//15 by tyeneala
s21_size_t s21_strlen(const char *str);

//16 Karthwas
char *s21_strpbrk(const char *str1, const char *str2);

//17 yurikobo
char *s21_strrchr(const char *str, int c);

//18 by elwoodju
s21_size_t s21_strspn(const char *str1, const char *str2);

//19 by elwoodju
char *s21_strstr(char *haystack, char *needle);

//20 by elwoodju
char *s21_strtok(char *str, const char *delim);

void *s21_to_lower(const char *str);

#endif  // SRC_S21_STRING_H_