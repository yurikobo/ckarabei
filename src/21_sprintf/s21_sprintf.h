#ifndef S21_SPRINTF_H_
#define S21_SPRINTF_H_
#include <stdarg.h>

// s21_string.c
typedef long unsigned s21_size_t;

#define S21_NULL (void*)0

// s21_sprintf.c
#define PERCENT " #'*+,-.0123456789:;L_hjlqtzv"
#define SPEC "cdisufnEeGgXxpo%"

#define MAX_DOU 65  // Длина числа в функции float_to_str
#define MAX_SIZE 10240  // Рабочие массивы token и temp_str

typedef struct {
    int minus, hash, space;
    char plus, zero_fro, zero_end;
    int width_ast, width_num;
    int accuracy_ast, accuracy_num, point, gap_num, gap_zero;
    int length_h, length_l, length_d;
    char spec;
} parsing;

// s21_sprintf.c
int s21_sprintf(char *str, const char *format, ...);
int err_res(int it_str, int error);
void ini_temp(va_list arg, const char *token, const char *format, int *it_for, char *temp_str);
void get_arg(va_list arg, const char *token, char *temp_str);

// strfor.c
void strfor(parsing p, char *temp_str);
void form_float(parsing p, char *temp_str);
void form_int(parsing p, char *temp_str);
void form_char(parsing p, char *temp_str);
void form_str(parsing p, char *temp_str);
void correct(parsing *p, char *temp_str);
void pars_token(va_list arg, parsing *p, const char *token);
void form_perc(parsing p, char *temp_str);
int form_cnul(parsing p, const char *token, char *temp_str);

// general.c
char *num_to_str(char *temp_str, long long int value, int dis);
int get_tok(char *token, const char *format, int it_for);
int cut_tok(const char *token, int len);
int id_char(char c, const char *src);
void round_in_str(int i, char *temp_str);
void add_char(int c, int n, char *temp_str);
char *float_to_str(char *temp_str, long double value);
void cut_str(int n, char *temp_str);
int my_memchr(const char *str, int c);

// s21_string.c
s21_size_t s21_strlen(const char *str);
char *s21_strcat(char *dest, const char *src);
char *s21_strcpy(char *dest, const char *src);

#endif  // S21_SPRINTF_H_
