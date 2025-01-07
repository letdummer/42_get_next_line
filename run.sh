#!/bin/bash
clear
cc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -o program && ./program


# move this line to between '&&' and './program'
#
#valgrind -s --leak-check=full 