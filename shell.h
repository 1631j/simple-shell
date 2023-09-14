#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
/**
 * struct variables - stores the reserved memory of the variables
 * @av: command line arguments
 * @buffer: buffer of command
 * @env: environment variables
 * @count: count of commands entered
 * @argv: arguments at opening of shell
 * @status: exit status
 * @commands: commands to execute
 */
typedef struct variables
{
	char **av;
	char *buffer;
	char **env;
	char **argv;
	int status;
	char **commands;
} vars_t;
/**
 * struct builtins - struct for the builtin functions
 * @name: name of builtin command
 * @f: function for corresponding builtin
 */
typedef struct builtins
{
	char *name;
	void (*f)(vars_t *);
} builtins_t;

/* global variable for ^C handling */
unsigned int point;

unsigned int _strlen(char *str);
ssize_t _puts(char *str);
char *_strcat(char *strc1, char *strc2);

int _strcmp(char *s1, char *s2);
void _strcpy(char *dest, char *src);
char *_strdup(const char *strtodup);

void (*get_comd_fun(vars_t *vars)) (vars_t *vars);
void get_exit(vars_t *vars);
void get_env(vars_t *vars);

void free_env(char **env);
char **make_env(char **env);

char **N_realloc(char **ptr, size_t *size);
char **_tokenizer(char *buffer, char *delimiter);

void _path(vars_t *vars);
int exe_path_dir(vars_t *vars);
int check_for_dir(char *str);
char *find_path(char **env);
int path_execute(char *check, vars_t *vars);

void print_error(vars_t *vars, char *caract);

#endif
