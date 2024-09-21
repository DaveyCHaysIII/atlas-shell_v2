CFLAGS := -Wall -Werror -Wextra -pedantic
NAME := hsh

.PHONY := all clean

all: $(NAME)

$(NAME): *.c
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -f hsh