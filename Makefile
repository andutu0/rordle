CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11
SRC = src/main.c src/game.c src/utils.c
OBJ = $(SRC:.c=.o)
BIN = rordle

.PHONY: all clean run

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# implicit rule: %.o depends on %.c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(OBJ) $(BIN)
