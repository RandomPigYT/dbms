CC:=gcc
LD:=ld

CFLAGS:=-Wall -Wextra -g -std=gnu17 
LDFLAGS:=

BIN:=bin
OBJ:=obj
SRC:=src

TARGET:=$(BIN)/PigSQL.out

SRCS:=$(shell find $(SRC) -type  f -name "*.c")
OBJS:=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

DIRS:=$(patsubst $(SRC)/%, $(OBJ)/%, $(shell find $(SRC)/ -mindepth 1 -type d))

CREATE_DIR_COMMAND:=./dirs.sh

.PHONY: all clean dirs

all: dirs $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

dirs:
	@$(CREATE_DIR_COMMAND) $(DIRS)

clean:
	-@rm -rf $(OBJ)/*
	-@rm -rf $(BIN)/*

run: $(TARGET)
	@./$(TARGET)

valgrind:
	@valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=./valgLogs/valgrind-out.txt \
         ./$(TARGET)
