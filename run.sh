#!/bin/bash
clear
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main.c -o program && valgrind --leak-check=full ./program