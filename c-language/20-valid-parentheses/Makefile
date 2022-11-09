CC		= gcc
FLAGS	= -Wall -Werror -Wextra -pedantic

.PHONY: all clean

all: main

main: main.c function.c
	@${CC} main.c ${FLAGS} -o main

clean:
	@rm -rvf main
