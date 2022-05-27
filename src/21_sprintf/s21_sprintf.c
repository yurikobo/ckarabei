#include "./s21_sprintf.h"
#include <stdarg.h>

int s21_sprintf(char *str, const char *format, ...) {
    str[0] = '\0';
    va_list arg;
    va_start(arg, format);
    int it_str = 0, it_for = 0, error = 0;
    while (format[it_for] != '\0') {
        if ((format[it_for] == '%')  && (format[it_for + 1] != 0)) {
            it_for++;
            char token[MAX_SIZE] = {0};
            char temp_str[MAX_SIZE] = {0};
            it_for+= get_tok(token, format, it_for);
            if (token[0] != 0) {
                parsing p = {-1, 0, 0, 48, 32, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48};
                pars_token(arg, &p, token);
                ini_temp(arg, token, format, &it_for, temp_str);
                correct(&p, temp_str);
                if (temp_str[0] != 0) {
                        strfor(p, temp_str);
                } else {
                    if (token[s21_strlen(token) - 1] == 'c') {
                        it_str += form_cnul(p, token, temp_str) + s21_strlen(format) - it_for;
                        s21_strcat(str, temp_str);
                        str[s21_strlen(str)] = '\0';
                        break;
                    }
                    if (token[s21_strlen(token) - 1] == 's')
                        s21_strcpy(temp_str, "(null)");
                }
                s21_strcat(str, temp_str);
                it_str+= s21_strlen(temp_str);
            }
            continue;
        } else {
            if ((format[it_for] == '%')  && (format[it_for + 1] == 0)) {
                str[it_str] = '\0';
                break;
            }
        }
        str[it_str++] = format[it_for++];
        str[it_str] = '\0';
    }
    va_end(arg);
    return err_res(it_str, error);
}

// Обработка ошибок
int err_res(int it_str, int error) {
    int res = -1;
    if (error == 0)
        res = it_str;
    return res;
}

// Инициализация буфера temp_str
void ini_temp(va_list arg, const char *token, const char *format, int *it_for, char *temp_str) {
    if (id_char(token[s21_strlen(token) - 1], SPEC) != 1) {
        if (format[*it_for] != 0) {
            add_char(format[*it_for], -1, temp_str);
            *it_for = *it_for + 1;
        }
    } else {
        if (token[s21_strlen(token) - 1] == '%') {
                add_char(37, (-1), temp_str);
        } else {
            get_arg(arg, token, temp_str);
        }
    }
}

// Функция получения аргумента
void get_arg(va_list arg, const char *token, char *temp_str) {
    int len = s21_strlen(token);
    char *st = S21_NULL;
    switch (token[len - 1]) {
        case 'c': add_char(va_arg(arg, int), 1, temp_str);
            break;
        case 's': st = va_arg(arg, char*);
            if (st) s21_strcpy(temp_str, st);
            break;
        case 'd': case 'i':
            if (id_char(108, token) == 1) {
                num_to_str(temp_str, va_arg(arg, long long int), 10);
            } else {
                if (id_char(104, token) == 1) {
                    num_to_str(temp_str, (short int)va_arg(arg, int), 10);
                } else {
                    num_to_str(temp_str, va_arg(arg, int), 10);
                }
            }
            break;
        case 'f':
            if (id_char(76, token) == 1) {
                float_to_str(temp_str, va_arg(arg, long double));
            } else {
                float_to_str(temp_str, va_arg(arg, double));
            }
            break;
        case 'u':
            if (id_char(108, token) == 1) {
                num_to_str(temp_str, va_arg(arg, unsigned long int), 10);
            } else {
                if (id_char(104, token) == 1) {
                    num_to_str(temp_str, (unsigned short int)va_arg(arg, unsigned int), 10);
                } else {
                    num_to_str(temp_str, va_arg(arg, unsigned int), 10);
                }
            }
            break;
    }
}

/* Функция разбирает строку token ("...s") на правила форматирования
 struct parsing, корректирует их под стандарт и условия,
форматирует строку temp_str в соответствии с правилами */
void strfor(parsing p, char *temp_str) {
    if (p.spec == 'c')
        form_char(p, temp_str);
    if (p.spec == 's')
        form_str(p, temp_str);
    if (p.spec == 'd')
        form_int(p, temp_str);
    if (p.spec == 'f')
        form_float(p, temp_str);
    if ((p.spec == '0') || (p.spec == '%'))
        form_perc(p, temp_str);
}

// Функция форматирует вывод при отсутствующем спецификаторе
void form_perc(parsing p, char *temp_str) {
    if (p.width_num > 1)
        add_char(p.zero_fro, (p.minus) * (p.width_num - 1), temp_str);
}

// Функция форматирует строку при c == 0
int form_cnul(parsing p, const char *token, char *temp_str) {
    if (id_char(45, token) != 1)
        if (p.width_num > 1)
            add_char(32, ((-1) * (p.width_num - 1)), temp_str);
    return (p.width_num > 1 ? p.width_num : 1);
}

// Функция форматирует вывод числа типа double
void form_float(parsing p, char *temp_str) {
    int len = s21_strlen(temp_str);
    int index_point = my_memchr(temp_str, 46);
    if (p.accuracy_num == 0) {  // обработка точности
        round_in_str((index_point + p.hash), temp_str);
    } else {
        int dec = len - index_point - 1;
        if (p.accuracy_num < dec)
            round_in_str((index_point + p.accuracy_num + 1), temp_str);
        else
            add_char(48, (p.accuracy_num - dec), temp_str);
    }
    len = s21_strlen(temp_str);
    if (p.plus != '0') {  // обработка знака
        if ((p.minus == 1) || (p.width_num <= len) || (p.zero_fro == 32))
            add_char(p.plus, -1, temp_str);
    }
    len = s21_strlen(temp_str);
    if (len < p.width_num) {  // преобразование ширины
        add_char(p.zero_fro, (p.minus * (p.width_num - len)), temp_str);
        if ((p.plus != '0') && (p.zero_fro == '0')) {  // доработка знака
            cut_str(-1, temp_str);
            add_char(p.plus, -1, temp_str);
        }
    }
}

// Функция форматирует вывод целого числа
void form_int(parsing p, char *temp_str) {
    int len = s21_strlen(temp_str);
    // преобразование ширины при отсутствии точности
    if (p.accuracy_num == 0) {
        if (p.plus != '0') {  // обработка знака
            if ((p.minus == 1) || (p.width_num <= len) || (p.zero_fro == 32))
                add_char(p.plus, -1, temp_str);
        }
        len = s21_strlen(temp_str);
        if (len < p.width_num) {  // преобразование ширины
            add_char(p.zero_fro, (p.minus * (p.width_num - len)), temp_str);
            if ((p.plus != '0') && (p.zero_fro == '0')) {  // доработка знака
                cut_str(-1, temp_str);
                add_char(p.plus, -1, temp_str);
            }
        }
    }
    // преобразование точности
    if (p.accuracy_num != 0) {
        len = s21_strlen(temp_str);
        // обработка знака
        if (p.plus != '0') {
            if ((p.accuracy_num <= len) || (p.zero_end == 32))
                add_char(p.plus, -1, temp_str);
        }
        // преобразование точности
        len = s21_strlen(temp_str);
        if (p.accuracy_num > len) {
            int n = (p.zero_end == '0' ? (-1): p.minus);
            add_char(p.zero_end, (n * (p.accuracy_num - len)), temp_str);
            if ((p.plus != '0') && (p.zero_end == '0')) {
                add_char(p.plus, -1, temp_str);
            }
        }
    }
    // доработка ширины после точности
    len = s21_strlen(temp_str);
    if ((p.width_num > len) && (p.gap_num == 0))
        add_char(32, (p.minus * (p.width_num - len)), temp_str);
}
// Функция форматирует вывод символа
void form_char(parsing p, char *temp_str) {
    int len = s21_strlen(temp_str);
    if (len < p.width_num)
        add_char(p.zero_fro, (p.minus * (p.width_num - len)), temp_str);
}

// Функция форматирует вывод строки
void form_str(parsing p, char *temp_str) {
    int len = s21_strlen(temp_str);
    if (p.length_l == 0) {
        if ((p.point == 1) && (p.accuracy_num < len)) {  // есть точка
            if (p.accuracy_num == 0)
                temp_str[0] = '\0';  // удаляем строку
            else   // усекаем строку
                cut_str((len - p.accuracy_num), temp_str);
        }
        len = s21_strlen(temp_str);
        if (len < p.width_num)  // преобразование ширины
            add_char(p.zero_fro, (p.minus * (p.width_num - len)), temp_str);
    } else {  // обработка длины
        cut_str(len, temp_str);  // удаление строки
        if ((p.point == 1) && (p.accuracy_num == 0) && (p.width_num != 0))
            add_char(p.zero_fro, p.width_num, temp_str);
    }
}

// Функция корректирует правила форматирования в struct parsing
void correct(parsing *p, char *temp_str) {
    // спецификатор 'i' приравнивается к 'd'
    p->spec = (p->spec == 'i' ? 'd': p->spec);
    // заполнение нулями не производится
    if (p->minus == 1)
        p->zero_fro = 32;
    if ((p->spec == 'd') || (p->spec == 'f')) {  // обработка знакового места
        if (temp_str[0] == '-') {
            p->plus = '-';
            cut_str(-1, temp_str);
        }
        if ((p->plus == '0') && (p->space == 1)) {
            p->plus = 32;
        }
    }
    // если спецификатор 'u', флаг знака обнуляется
    p->plus = p->spec == 'u' ? '0' : p->plus;
    // спецификатор 'u' приравнивается к 'd'
    p->spec = (p->spec == 'u' ? 'd': p->spec);
    if (p->spec == 'd') {
        if (p->point == 1)  // модификатор точности
            p->zero_fro = 32;
        // обработка второго 0
        if (((p->gap_num == 0) && (p->accuracy_num != 0)) || ((p->gap_zero == 0) && (p->zero_end == '0')))
            p->zero_end = '0';
        else
            p->zero_end = 32;
    }
    if (p->spec == 'f') {  // точность по умолчанию
        if (p->point == 0)
            p->accuracy_num = 6;
    }
    if ((p->spec == 'f') || (p->spec == 'c') ||  (p->spec == 's')) {
        // перенос 0 вперед точки
        if ((p->zero_end == '0') && (p->gap_zero == 1))
            p->zero_fro = '0';
        // перенос точности в ширину
        if (p->gap_num == 1) {
            p->width_num = p->accuracy_num;
            p->accuracy_num = 0;
        }
    }
}

// Функция разбирает строку token ("...s") на правила форматирования struct parsing
void pars_token(va_list arg, parsing *p, const char *token) {
    int j = 0;
    while (token[j++] != '\0') {
        char c = token[j - 1];
        p->minus = (c == '-' ? (1) : p->minus);
        p->plus = (c == '+' ? '+' : p->plus);
        p->hash = (c == '#' ? 1 : p->hash);
        p->width_ast = (((c == '*') && (p->point == 0)) ? 1 : p->width_ast);
        p->accuracy_ast = (((c == '*') && (p->point == 1)) ? 1 : p->accuracy_ast);
        p->point = (c == '.' ? 1 : p->point);
        p->length_h = (c == 'h' ? 1 : p->length_h);
        p->length_l = (c == 'l' ? 1 : p->length_l);
        p->length_d = (c == 'L' ? 1 : p->length_d);
        p->space = (c == 32 ? 1 : p->space);
        p->spec = (id_char(c, SPEC) == 1 ? c : p->spec);
        // Обработка цифр до и после '.'
        if (id_char(c, "123456789") != 0) {
            j--;
            if ((p->point != 0) && (p->accuracy_num == 0)) {
                if (token[j - 1] != '.')
                    p->gap_num = 1;
                if ((token[j - 1] == '0') && (p->gap_zero == 0))
                    p->gap_num = 0;
            }
            int num = 0;
            while (id_char(token[j], "0123456789") != 0)
                num = num * 10 + (token[j++] - 48);
            if ((p->point == 1) && (p->accuracy_num == 0))
                p->accuracy_num = num;
            else
                p->width_num = num;
            continue;
        }
        // Обработка '0' до и после '.'
        if (c == '0') {
            if ((p->point == 1) && (token[j - 2] != '.'))
                p->gap_zero = 1;
            if (p->point == 0)
                p->zero_fro = '0';
            else
                p->zero_end = '0';
            while (token[j] == '0')
                j++;
        }
    }
    // Взятие значений длины и ширины из аргумента
       if (p->width_ast == 1)
           p->width_num = va_arg(arg, int);
       if (p->accuracy_ast == 1)
           p->accuracy_num = va_arg(arg, int);
}

/* Функция преобразует целое число value
 в системе des (2, 8, 10, 16) в строку temp_str */
char *num_to_str(char *temp_str, long long int value, int dis) {
    int i = 0, j = 0;
    if (value != 0) {
        long long int d = (value > 0 ? value : value * -1), tmp = d;
        if ((value < 0) && (dis == 10))
            temp_str[i++] = '-';
        int len = 0;
        for (; tmp > 0; len++, j++)
            tmp /= dis;
        char *ch = "0123456789abcdef";
        for (; len > 0; len--) {
            temp_str[i + len - 1] = ch[d % dis];
            d /= dis;
        }
    } else {
        temp_str[i++] = '0';
    }
    temp_str[i + j] = '\0';
    return temp_str;
}

// Функция усекает строку на n-е количестов символов в начале (-n) или в конце (n)
void cut_str(int n, char *temp_str) {
    if (n != 0) {
        int len = s21_strlen(temp_str);
        if (n < 0) {
            for (int j = 0; j <= (len + n); j++)
                temp_str[j] = temp_str[j - n];
        } else {
            temp_str[len - n] = '\0';
        }
    }
}

// Функция возвращает i символа с в строке str или -1
int my_memchr(const char *str, int c) {
    int j = 0, len = s21_strlen(str);
    for (; j < len; j++) {
        if (str[j] == c)
            break;
    }
    return (j == len ? -1 : j);
}

// Функция преобразует значение value типа double в строку temp_str
char *float_to_str(char *temp_str, long double value) {
    int i = 0;
    if (value != 0) {
        if (value < 0)
            temp_str[i++] = '-';
        long double f = (value > 0 ? value : value * -1);
        unsigned long long int tmp = (unsigned long long int)f, d = tmp;
        f -= d;
        if (tmp > 0) {  // обработка целой части
            int len = 0, j = 0;
            for (; tmp > 0; len++, j++)
                tmp /= 10;
            for (; len > 0; len--) {
                temp_str[i + len - 1] = d % 10 + 48;
                d /= 10;
            }
            i += j;
        } else {
            temp_str[i++] = '0';
        }
        temp_str[i++] = '.';
        // обработка дробной части
        for (int intgr; (i < MAX_DOU) && (f > 0); i++) {
            intgr = (int)(f * 10);
            temp_str[i] = intgr + 48;
            f = f * 10 - intgr;
        }
    } else {
        temp_str[i++] = '0';
        temp_str[i++] = '.';
    }
    temp_str[i++] = '0';
    temp_str[i] = '\0';
    return temp_str;
}

// Функция добавляет n-количество символов с в начало (-n) и/или  в конец (n) строки
void add_char(int c, int n, char *temp_str) {
    if (n != 0) {
        int len = s21_strlen(temp_str), j;
        if (n > 0) {
            for (j = len; j < (n + len); j++)
                temp_str[j] = c;
            temp_str[j] = '\0';
        } else {
            for (j = (len - n); j >= 0; j--) {
                if (j >= (n * (-1))) {
                    temp_str[j] = temp_str[j + n];
                } else {
                    temp_str[j] = c;
                }
            }
        }
    }
}

// Функция "округляет" цифровой символ для типа float
void round_in_str(int i, char *temp_str) {
    int j = i, inc = 0;
    if (temp_str[j] == '.')
        j++;
    if (((temp_str[j] - 48) * 10 + (temp_str[j + 1] - 48)) > 50)
        inc = 1;
    j--;
    while (inc != 0) {
        if (temp_str[j] == '.')
            j--;
        if (temp_str[j] == 57) {
            temp_str[j] = 48;
            inc = 1;
            j--;
        } else {
            temp_str[j] = (int)temp_str[j] + 1;
            break;
        }
        if (j < 0) {
            add_char(49, -1, temp_str);
            i++;
            break;
        }
    }
    temp_str[i] = '\0';
}

/* Функция извлекает из format лексему начиная с индекса it_for
 и копирует ее в token, возращая длину лексемы len*/
int get_tok(char *token, const char *format, int it_for) {
    int len = 0;
    for (; format[it_for + len] != '\0'; len++) {
        if (id_char(format[it_for + len], SPEC) == 1) {
            token[len] = format[it_for + len];
            break;
        }
        if (id_char(format[it_for + len], PERCENT) != 1) {
            len--;
            break;
        }
        token[len] = format[it_for + len];
    }
    token[++len] = '\0';
    return len;
}

// Функция возвращает 1, если символ с имеется в символьной строке "src", иначе 0
int id_char(char c, const char *src) {
    int j = 0, len = s21_strlen(src);
    for (; j < len; j++) {
        if (c == src[j])
            break;
    }
    return (j == len ? 0 : 1);
}
