#include "./s21_string.h"
//9 elwoodju в работе -- возвращает только 1 0 -1 ??????
int s21_strcmp(const char *str1, const char *str2) {
    int out = 0;
    for (int i = 0; (str1[i] != '\0')||(str2[i] != '\0'); i++) {
        if (str1[i] != str2[i]) {
            out = str1[i] - str2[i];
            break;
        }
    }
    if (s21_strlen(str1) == 0 && s21_strlen(str2) == 0) out = 0;
    return out;
}