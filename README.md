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
        
$
AUTHORS: James Njoroge - 1631j@github.com
