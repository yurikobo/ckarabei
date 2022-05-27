#include "s21_string.h"
//18 by elwoodju
s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t len = 0;
    for (s21_size_t i = 0; str1[i]!='\0'; i++) {
        s21_size_t count = 0;
        for (s21_size_t j = 0; str2[j]!='\0'; j++) {
            if (str1[i] == str2[j]) {
                break;
            } else {
                count++;
            }
        }
        if (count == s21_strlen(str2)) {
            break;
        } else {
            len++;
        }
    }
return len;
}
