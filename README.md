

<!----------------------- INTRODUCTION ----------------------->
<!----------------------- !end! INTRODUCTION -----------------------> 
## 📝 INTRODUCTION

+ **OBJECTIVE**

  This project is about programming a function that returns a line read from a file descriptor.

+ **PROTOTYPE**

	`char *get_ext_line(int fd);`

+ **REQUIREMENTS**
	- Repeated calls (e.g., using a loop) to the function should let you read the text file pointed to by the file descriptor, one line at a time.
  - The function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.
  - The returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.

+ **MAKEFILE**
	- Must not relink
	- The project will be compiled with the flags **-Wall -Wextra -Werror**
	- Must at least contain the rules **$(NAME), all, clean, fclean** and **re**


Check the complete [SUBJECT](https://github.com/letdummer/42_get_next_line/blob/main/subject/en.subject.pdf) (version 12 - dez/2024).


<!----------------------- !end! INTRODUCTION -----------------------> 
<!----------------------- SUMMARY OF STEPS ----------------------->

<details open>
<summary>

##  📝 STEP BY STEP
</summary>
[soon]
<!--
- [Beauty name for the link](#name_of_summary)<br>
- [References](#references)<br>
-->

</details>

<!----------------------- !end! SUMMARY OF STEPS ----------------------->

## HOW TO USE

To compile:

`cc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -o program && ./program`

or use the script **run.sh**

`./run.sh`


<!----------------------- REFERENCES ----------------------->

## 🔎 References

- [File descriptor](https://stackoverflow.com/questions/5256599/what-are-file-descriptors-explained-in-simple-terms)<br>
- [Static variable](https://www.shiksha.com/online-courses/articles/static-variable-in-c-how-to-declare-and-use-it/)<br>
- [Video tutorial](https://www.youtube.com/watch?v=scXWLP8uhDU&ab_channel=OliveStem)<br>
- [Manual read()](https://man7.org/linux/man-pages/man2/read.2.html)<br>
- [Manual open()](https://man7.org/linux/man-pages/man2/open.2.html)<br>
- [Tester](https://github.com/Tripouille/gnlTester)

<!----------------------- !end! REFERENCES ----------------------->
