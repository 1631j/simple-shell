#include "shell.h"

/**
 * get_comd_fun - compares the functions
 * @vars: struct
 * Return: 0
 */
void (*get_comd_fun(vars_t *vars)) (vars_t *vars)
{
	unsigned int iter;

	builtins_t comds[] = {
		{"exit", get_exit},
		{"env", get_env},
		{NULL, NULL}
	};
	for (iter = 0; comds[iter].f != NULL; iter++)
	{
		if (_strcmp(vars->av[0], comds[iter].name) == 0)
			break;
	}
	if (comds[iter].f != NULL)
		comds[iter].f(vars);

	return (comds[iter].f);
}

/**
 * get_env - environment variables
 * @vars: struct
 * Return: env
 */
void get_env(vars_t *vars)
{
	unsigned int iter;

	for (iter = 0; vars->env[iter]; iter++)
	{
		_puts(vars->env[iter]);
		_puts("\n");
	}
	vars->status = 0;
}

/**
 * get_exit - function exit
 * @vars: struct
 * Return: 0
 */
void get_exit(vars_t *vars)
{
	free(vars->buffer);
	free(vars->av);
	free(vars->commands);
	free_env(vars->env);
	exit(vars->status);
}
