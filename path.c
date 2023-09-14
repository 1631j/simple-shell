#include "shell.h"
/**
 * check_for_dir - checks if the command is a part of a path
 * @str: command
 *
 * Return: 1 on success, 0 on failure
 */
int check_for_dir(char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '/')
			return (1);
	}
	return (0);
}
/**
 * exe_path_dir - executes the command in the current working directory
 * @vars: pointer to struct of variables
 *
 * Return: 0 on success, 1 on failure
 */
int exe_path_dir(vars_t *vars)
{
	pid_t pid;
	struct stat buff;

	if (stat(vars->av[0], &buff) == 0)
	{
		if (access(vars->av[0], X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
				execve(vars->av[0], vars->av, vars->env);
			else
			{
				wait(&vars->status);
				return (0);
			}
		}
		else
		{
			vars->status = 127;
			return (1);
		}
	}
	return (0);
}
/**
 * find_path - finds the PATH variable
 * @env: array of environment variables
 *
 * Return: pointer to the node that contains the PATH, or NULL on failure
 */
char *find_path(char **env)
{
	char *path = "PATH=";
	unsigned int iter1, iter2;

	for (iter1 = 0; env[iter1]; iter1++)
	{
		for (iter2 = 0; iter2 < 5; iter2++)
			if (path[iter2] != env[iter1][iter2])
				break;
		if (iter2 == 5)
			break;
	}
	return (env[iter1]);
}
/**
 * path_execute - executes a command in the path
 * @check: full path to the command
 * @vars: pointer to struct of variables
 *
 * Return: 0 on succcess, 1 on failure
 */
int path_execute(char *check, vars_t *vars)
{
	pid_t pid;

	if (access(check, X_OK) == 0)
	{
		pid = fork();
		if (pid == 0)
			execve(check, vars->av, vars->env);
		else
		{
			wait(&vars->status);
			return (0);
		}
	}
	else
	{
		vars->status = 127;
		return (1);
	}
	return (0);
}
/**
 * _path - checks if the command is in the PATH
 * @vars: variables
 *
 * Return: void
 */
void _path(vars_t *vars)
{
	unsigned int i = 0, iter;
	char *path, *path_dup = NULL, *check_path = NULL;
	char **path_token = NULL;
	struct stat buff;

	if (check_for_dir(vars->av[0]))
		i = exe_path_dir(vars);
	else
	{
		path = find_path(vars->env);
		if (path != NULL)
		{
			path_dup = _strdup(path);
			path_token = _tokenizer(path_dup, ":");
			for (iter = 0; path_token[iter]; iter++)
			{
				check_path = _strcat(path_token[iter], vars->av[0]);
				if (stat(check_path, &buff) == 0)
				{
					i = path_execute(check_path, vars);
					free(check_path);
					break;
				}
				free(check_path);
			}
			free(path_dup);
			if (path_token == NULL)
			{
				vars->status = 127;
				get_exit(vars);
			}
		}
		if (path == NULL || path_token[iter] == NULL)
		{
			print_error(vars, ": command not found\n");
			vars->status = 127;
		}
		free(path_token);
	}
	if (i == 1)
		get_exit(vars);
}
