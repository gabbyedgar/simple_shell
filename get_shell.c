#include "main.h"

/**
 * cmd_exec - executes command lines
 *
 * @datash: data relevant (args and input)
 * Return: 1 on success.
 */
int cmd_exec(data_shell *datash)
{
	int exec = is_executable(datash);
	if (exec == -1)
		return 1;

	char *dir;
	if (exec == 0)
	{
		dir = _which(datash->args[0], datash->_environ);
		if (check_error_cmd(dir, datash) == 1)
			return 1;
	}
	else
	{
		dir = datash->args[0];
	}

	pid_t pd = fork();
	if (pd == 0)
	{
		execve(dir + exec, datash->args, datash->_environ);
	}
	else if (pd < 0)
	{
		perror(datash->av[0]);
		return 1;
	}

	return (eval);
}
