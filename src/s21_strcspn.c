#include "s21_string.h"
//13 elwoodju
s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t len = s21_strlen(str1);
    for (s21_size_t i = 0; str2[i]!='\0'; i++) {
        for (s21_size_t j = 0; str1[j]!='\0'; j++) {
            if ((str1[j]==str2[i]) && (len > j)) len = j;
        }
    }
return len;
}