#include "shell.h"

/**
 * print_error - prints error messages to standard error
 * @vars: pointer to struct of variables
 * @caract: message to print
 * Return: void
 */
void print_error(vars_t *vars, char *caract)
{
	_puts(vars->argv[0]);
	_puts(": ");
	_puts(vars->av[0]);
	if (caract)
		_puts(caract);
}
