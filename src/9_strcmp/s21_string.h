#ifndef SRC_OUR_STRING_H_
#define SRC_OUR_STRING_H_


#include <stdio.h>
#include <stdlib.h>
//#include "our_string.c"
typedef long unsigned s21_size_t;
#define s21_NULL ((void *)0)

/*
+  1 memchr elwoodju
+  2 memcmp karthwas
+  3 memcpy cookiebe
+  4 memmove cookiebe
+  5 memset cookiebe
+  6 strcat cookiebe
-  7 strncat cookiebe <-
+  8 strchr yurikobo
+  9 strcmp elwoodju - правю
+ 10 strncmp elwoodju - правю
+ 11 strcpy yurikobo
+ 12 strncpy yurikobo
+ 13 strcspn elwoodju
- 14 strerror karthwas <-
+ 15 strlen tyeneala
+ 16 strpbrk karthwas <-
+ 17 strrchr yurikobo
+ 18 strspn elwoodju
+ 19 strstr elwoodju
- 20 strtok elwoodju - делаю
*/

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

//9 elwoodju
int s21_strcmp(const char *str1, const char *str2);

//10 elwoodju
int s21_strncmp(const char *str1, const char *str2, size_t n);

//11 yurikobo
char *s21_strcpy(char *dest, const char *src);

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

#endif  // SRC_OUR_STRING_H_
