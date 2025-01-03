!/bin/bash
clear
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main.c -o program && ./program


# move this line to between '&&' and './program'
#
#valgrind -s --leak-check=full 