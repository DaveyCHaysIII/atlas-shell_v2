CFLAGS := -Wall -Werror -Wextra -pedantic

NAME := hsh

SRC := $(wildcard *c)

OBJ := $(SRC: .c=.o)

.PHONY := all clean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ) $(NAME)
