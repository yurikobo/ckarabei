NAME = "s21_sprintf"
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

ASNT = -fsanitize=address -g
# $(ASNT)

COV = --coverage
CHE = -lcheck -lm -lpthread

MAIN = check_test.c

LIB = s21_sprintf.c s21_string.c
LOBCT = $(LIB: .c=.o)
#ИЗ СТРИНГА ВЫТАЩИТЬ ФУНКЦИИ И ПРОВЕРИТЬ РАБОТУ

SOURCES = $(MAIN) $(LIB)
OBJECTS = $(SOURCES: .c=.o)

PATH1 = .
EXEFILE = test.out

all: check test
	
s21_string.a:
	$(CC) $(CFLAGS) $(LIB)
	ar -r s21_string.a $(LOBCT)
	
test: $(OBJECTS)
	$(CC) $(ASNT) $(COV) $(CHE) $(OBJECTS)  -o $(EXEFILE)

.c.o:
	$(CC) $(ASNT) $(COV) $(CFLAGS) $(SOURCES)

check:
	checkmk clean_mode=1 check_test.check > check_test.c

#asan:
#    gcc -o $(PATH1)/$(EXEFILE) -fsanitize=address -g $(SOURCES) && $(PATH1)/$(EXEFILE)

report:
	gcov $(LIB) -m -k -f
	lcov -t “s21_spintf” -o s21_spintf.info -c -d .
	genhtml -o report s21_spintf.info
	open ./report/index.html

backup:
	ar -r ../Backup/$(NAME).zip $(SOURCES)

leaks:
	  leaks -atExit -- $(PATH1)/$(EXEFILE)
	  
cpp:
	cppcheck $(SOURCES) ./s21_sprintf.h
	
lint:
	cp /Users/tyeneala/Desktop/my_project/test_C/CPPLINT.cfg ./
	python3 /Users/tyeneala/Desktop/my_project/test_C/cpplint.py --extensions=c $(LIB) ./s21_sprintf.h


clean:
	rm -rf *.o *.cfg *.gcno *.gcda *.out *.dSYM *.gcov *.info *.out *.a


rebuild: clean all

