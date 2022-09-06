CC:=gcc
LD:=ld

CFLAGS:=-Wall -Wextra -g -std=c11
LDFLAGS:=

BIN:=bin
OBJ:=obj
SRC:=src

TARGET:=$(BIN)/dbms

SRCS:=$(shell find $(SRC) -type  f -name "*.c")
OBJS:=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

DIRS:=$(patsubst $(SRC)/%, $(OBJ)/%, $(shell find $(SRC)/ -mindepth 1 -type d))


.PHONY: all clean dirs

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

dirs:
	@mkdir $(DIRS)

clean:
	@rm -rf $(OBJ)/*
	@rm -rf $(BIN)/*
