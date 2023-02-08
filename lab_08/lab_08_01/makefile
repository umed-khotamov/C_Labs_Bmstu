CC = gcc

OUT_DIR = ./out
SRC_DIR = ./src
UNIT_DIR = ./unit_tests

INC_DIR = ./inc

CFLAGS = -std=c99 -Wall -Werror -pedantic -Wextra -Wfloat-conversion -Wvla
UFLAGS = -lcheck -lm

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)
DEP = $(SRC:$(SRC_DIR)/%.c=$(OUT_DIR)/%.d)

UNIT_SRC = $(wildcard $(UNIT_DIR)/*.c)
UNIT_OBJ = $(UNIT_SRC:$(UNIT_DIR)/%.c=$(OUT_DIR)/%.o)

INCLUDES = -I$(INC_DIR)

$(shell mkdir $(OUT_DIR))

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c 
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c -o $@ $<

$(OUT_DIR)/%.o: $(UNIT_DIR)/%.c 
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c -o $@ $<

app.exe: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

unit_tests.exe: $(OUT_DIR)/matrix.o $(OUT_DIR)/check_alloc.o
	$(CC) -o $@ $^ $(UFLAGS)

-include $(OUT_DIR)/*.d

clean:
	rm -rf $(OUT_DIR) app.exe unit_tests.exe

.PHONY: clean
