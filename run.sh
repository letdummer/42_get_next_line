#!/bin/bash
clear
cc -Wall -Werror -Wextra main.c -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c -o program && ./program


# move this line to between '&&' and './program'
#
#valgrind -s --leak-check=full 

# __________________________________
# TO TEST WITH THE MAIN ARGC/ARGV
# __________________________________

#clear
#cc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -o program && ./program tests/example.txt
