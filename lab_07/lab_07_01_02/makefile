CC = gcc

OUT_DIR = ./out
SRC_DIR = ./src
UNIT_DIR = ./unit_tests

INCS = -I inc

CFLAGS = -std=c99 -Wall -Werror -pedantic -Wextra -Wvla
UFLAGS = -lcheck -lm

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

$(shell mkdir $(OUT_DIR))

all: app.exe unit_tests.exe

app.exe: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

unit_tests.exe: $(OUT_DIR)/mysort.o $(OUT_DIR)/check_key.o
	$(CC) -o $@ $^ $(UFLAGS)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

$(OUT_DIR)/check_key.o: $(UNIT_DIR)/check_key.c
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	rm -rf $(OUT_DIR) app.exe unit_tests.exe

.PHONY: clean
