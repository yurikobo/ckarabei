1 Саша
void *memchr(const void *str, int c, size_t n)
Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str.


2 Тимофей
int memcmp(const void *str1, const void *str2, size_t n)
Сравнивает первые n байтов str1 и str2.


3 Андрей
void *memcpy(void *dest, const void *src, size_t n)
Копирует n символов из src в dest.


4 Андрей
void *memmove(void *dest, const void *src, size_t n)
Еще одна функция для копирования n символов из str2 в str1.


5 Олег
void *memset(void *str, int c, size_t n)
Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.


6
char *strcat(char *dest, const char *src)
Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest.


7
char *strncat(char *dest, const char *src, size_t n)
Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов.


8 Стас
char *strchr(const char *str, int c)
Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.


9
int strcmp(const char *str1, const char *str2)
Сравнивает строку, на которую указывает str1, со строкой, на которую указывает str2.


10
int strncmp(const char *str1, const char *str2, size_t n)
Сравнивает не более первых n байтов str1 и str2.


11
char *strcpy(char *dest, const char *src)
Копирует строку, на которую указывает src, в dest.


12
char *strncpy(char *dest, const char *src, size_t n)
Копирует до n символов из строки, на которую указывает src, в dest.


13
size_t strcspn(const char *str1, const char *str2)
Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2.


14
char *strerror(int errnum)
Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает указатель на строку с сообщением об ошибке. Нужно объявить макросы, содержащие массивы сообщений об ошибке для операционных систем mac и linux. Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС осуществляется с помощью директив.


15 Олег
size_t strlen(const char *str)
Вычисляет длину строки str, не включая завершающий нулевой символ.


16
char *strpbrk(const char *str1, const char *str2)
Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.


17
char *strrchr(const char *str, int c)
Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.


18
size_t strspn(const char *str1, const char *str2)
Вычисляет длину начального сегмента str1, который полностью состоит из символов str2.


19
char *strstr(const char *haystack, const char *needle)
Находит первое вхождение всей строки needle (не включая завершающий нулевой символ), которая появляется в строке haystack.


20
char *strtok(char *str, const char *delim)
Разбивает строку str на ряд токенов, разделенных delim.