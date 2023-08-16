CC = gcc
# CFLAGS = -Wall -Wextra
CFLAGS=-g -fsanitize=address

.PHONY: all clean run_main run_test_utls

all: main test_utils

run_main: main
	./main

run_test_utls: test_utils
	./test_utils

main: main.o utils.o
	$(CC) $(CFLAGS) -o main main.o utils.o

test_utils: test_utils.o utils.o
	$(CC) $(CFLAGS) -o test_utils test_utils.o utils.o

main.o: main.c utils.h
	$(CC) $(CFLAGS) -c main.c

test_utils.o: test_utils.c utils.h
	$(CC) $(CFLAGS) -c test_utils.c


utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c


clean:
	rm -f main test_utils *.o
