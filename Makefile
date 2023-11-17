CC = gcc

clean:
	@rm -rf ./test_wordle

build:
	@$(CC) -Wall -Wextra -Wshadow -Werror -std=c99 -pedantic -g -DDEBUG -o test_wordle test_wordle.c

run: build
	@./test_wordle
