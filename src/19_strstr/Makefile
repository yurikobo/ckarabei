CC=gcc
CFLAGS=-c -Wall -Werror -Wextra -fprofile-arcs -ftest-coverage 
SOURCES= s21_strstr.c s21_strlen.c test_s21_strstr.c
OBJECTS=$(SOURCES:.c=.o)
OBJECTS2=$(SOURCES:.c=.gcno)
EXECUTABLE= autotest
LDFLAGS=-lgcov --coverage -lcheck

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(SOURCES:.c=.gcno) $(SOURCES:.c=.gcda) $(EXECUTABLE)

rebuild: clean make

make: $(SOURCES) $(EXECUTABLE)
