CC = gcc

OUT_DIR = ./out
SRC_DIR = ./src
LOAD_SRC_DIR = ./src_load
LOAD_OUT = ./load_out
UNIT_DIR = ./unit_tests
LIBS_DIR = ./libs

INC_DIR = ./inc

CFLAGS = -std=c99 
UFLAGS = -lcheck -lm

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

LOAD_SRC = $(wildcard $(LOAD_SRC_DIR)/*.c)
LOAD_OBJ = $(LOAD_SRC:$(LOAD_SRC_DIR)/%.c=$(LOAD_OUT)/%.o)

UNIT_SRC = $(wildcard $(UNIT_DIR)/*.c)
UNIT_OBJ = $(UNIT_SRC:$(UNIT_DIR)/%.c=$(OUT_DIR)/%.o)

LIBS := $(wildcard $(LIBS_DIR)/*.c)

STATIC_LIBS := $(LIBS:$(LIBS_DIR)/%.c=$(LIBS_DIR)/lib%.a)
DYNAMIC_LIBS := $(LIBS:$(LIBS_DIR)/%.c=$(LIBS_DIR)/lib%.so)

INCLUDES = -I$(INC_DIR)

$(shell mkdir $(OUT_DIR))
$(shell mkdir $(LOAD_OUT))

all: dynamic_app.exe static_app.exe dynamic_load_app.exe

#Static

static_app.exe: $(OBJS) $(STATIC_LIBS)
	$(CC) $(OBJS) $(STATIC_LIBS) -o static_app.exe

$(LIBS_DIR)/lib%.a: $(OUT_DIR)/%.o
	ar rc $@ $<

#Dynamic link

dynamic_app.exe: $(OBJS) $(DYNAMIC_LIBS)
	$(CC) $(OBJS) $(DYNAMIC_LIBS) -o dynamic_app.exe

$(LIBS_DIR)/lib%.so: $(OUT_DIR)/%.o
	$(CC) -shared $< -o $@

#Dynamic load

dynamic_load_app.exe: $(LOAD_OBJ) $(LIBS_DIR)/load_lib.so
	$(CC) $(LOAD_OBJ) -ldl -o $@

$(LIBS_DIR)/load_lib.so: $(OUT_DIR)/mysort.o $(OUT_DIR)/io_file.o
	$(CC) -shared $(OUT_DIR)/mysort.o $(OUT_DIR)/io_file.o -o $@

$(LOAD_OUT)/%.o: $(LOAD_SRC_DIR)/%.c
	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@

#OBJS
$(OUT_DIR)/%.o: $(LIBS_DIR)/%.c 
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@ 

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

-include $(OUT_DIR)/*.d

clean:
	rm -rf $(OUT_DIR) $(LOAD_OUT) $(LIBS_DIR)/*.so $(LIBS_DIR)/*.a app.exe static_app.exe dynamic_app.exe dynamic_load_app.exe

.PHONY: clean
