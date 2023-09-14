Description:

simple_shell is a command line interpreter, or shell, in the tradition of the first Unix shell written by Ken Thompson in 1971. This shell is intentionally minimalistic, yet includes the basic functionality of a traditional Unix-like command line user interface. Standard functions and system calls employed in simple_shell include: access, execve, exit, fork, free, getline, malloc, perror, stat, wait, write.
File Structure

    AUTHORS - List of contributors to this repository.

    man_1_simple_shell - Manual page for the simple_shell.

    shell.h - program header file.

    get_fun.c - major builtin functions
        get_comd_fun - checks to see if the user's command matches a builtin.
        get_exit - exits the shell with the option of a specified status.
        get_env - prints the shell's environment variables to the standard output.

    environment.c - functions related to the environment:
        make_env - creates the shell's environment from the parent process.
        free_env - frees the shell's environment.

    path.c - functions related to executing commands:
        path_execute - executes a command in the PATH.
        find_path - finds the PATH environment variable.
        _path - checks if the command is in the PATH.
        exe_path_dir - executes a command with an absolute path.
        check_for_dir - checks if the command contains an absolute path.

    simple_shell.c - essential functions to the shell:
        main - the main function of the program.

    strfun.c - functions related to string manipulation:
        _puts - writes a string to standart output.
        _strdup - duplicates a string.
        _strcmp - compares two strings.
        _strcat - concatenates two strings with a / in the middle.
        _strlen - calculates the length of a string.

    tokenizer.c - tokenizing function:
        _tokenizer - creates an array of tokens from a buffer with a specified delimiter.
        N_realloc - a custom realloc function for arrays of pointers.

Flowchart (main):

enter image description here
Requirements:

simple_shell is designed to run in the Ubuntu 14.04 LTS linux environment and to be compiled using the GNU compiler collection v. gcc 4.8.4 with flags-Wall, -Werror, -Wextra, and -pedantic.
Installation:

    Clone this repository: https://github.com/TheMasterTz/simple_shell.git
    Change directories into the repository: cd simple_shell
    Compile: gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
    Run the shell in interactive mode: ./hsh
    Or run the shell in non-interactive mode: example echo "pwd" | ./hsh

Example of Use:

Run the executable in your terminal after compiling:

~/shell$ ./shell
$ ls -la
total 96
drwxr-xr-x 1 runner runner   184 Aug 23 18:24 .
drwxrwxrwx 1 runner runner    74 Aug 23 22:10 ..
-rw-r--r-- 1 runner runner   177 Aug 23 16:37 .breakpoints
-rw-r--r-- 1 runner runner   458 Aug 22 16:59 environment.c
-rw-r--r-- 1 runner runner   953 Aug 23 16:39 error.c
-rw-r--r-- 1 runner runner   668 Aug 22 20:15 get_fun.c
-rwxr-xr-x 1 runner runner 18216 Aug 23 16:42 main
-rw-r--r-- 1 runner runner   932 Aug 23 00:20 main.c
-rw-r--r-- 1 runner runner  1852 Aug 23 00:24 Path.c
-rwxr-xr-x 1 runner runner 18072 Aug 23 18:24 shel
-rwxr-xr-x 1 runner runner 18072 Aug 23 00:24 shell
-rw-r--r-- 1 runner runner  1542 Aug 23 00:17 shell.h
-rw-r--r-- 1 runner runner  1381 Aug 22 21:00 strfun.c
-rw-r--r-- 1 runner runner   810 Aug 22 16:46 tokenizer.c
$
AUTHORS: James Njoroge - 1631j@github.com
