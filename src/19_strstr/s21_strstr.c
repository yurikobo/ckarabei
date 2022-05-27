#include "s21_string.h"
//19 by elwoodju
char *s21_strstr(char *haystack, char *needle) {
    char *out = s21_NULL;
    for (int i = 0; haystack[i] != '\0'; i++) {
        int count = 0;
        if (haystack[i] == needle[0]) {
        for (int j = 0; needle[j] != '\0'; j++) {
            if (haystack[i+j] == needle[j]) {
            count++;
            if (count == (int)s21_strlen(needle)) {
                out = i+haystack;
                break;
            }
            } else {
            break;
            }
        }
        }
        if (out != s21_NULL) break;
    }
    if (s21_strlen(needle) == 0) out = haystack;
    return out;
}