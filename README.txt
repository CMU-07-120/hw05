07-120 Introduction to Software Construction
hw05 - A Wordle Refactor

Files you will modify:
    wordle.h            - The header file you will modify/refactor
    wordle.c            - The program you will modify/refactor
    test_wordle.c       - Test file for wordle.c

Files you won't modify:
    wordlist.c          - The word list as a 2309-length array
    wordlist.h          - The header file for the word list and it's length
    contracts.h         - This file gives us ENSURES/REQUIRES contracts

==========================================================

Compiling and running sort functions:
    % gcc -Wall -Wextra -Wshadow -Werror -std=c99 -pedantic -g -DDEBUG -o test_wordle test_wordle.c
    % ./test_wordle
