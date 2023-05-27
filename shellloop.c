#include "main.h"


/**
 * shell_loop - Loop of shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(data_shell *datash)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		loop = 0;
		free(input);
	
	}
}
const char *input = datash->args[0];
	int i = 0;

	while (input[i])
	{
		if (input[i] == '/')
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return 0;
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else
			break;
	}

	if (i == 0)
		return 0;

	struct stat st;
	if (stat(input + i, &st) == 0)
		return i;

	get_error(datash, 127);
	return -1;
}

/**
 * check_error - verifies if user has permissions to access
 *
 * @dir: destination directory
 * @datash: data structure
 * Return: 1 if there is an error, 0 if not
 */
int check_error(const char *dir, data_shell *datash)
{
	if (dir == NULL)
	{
		get_error(datash, 127);
		return 1;
	}

	if (_strcmp(datash->args[0]) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_error(datash, 126);
			return 1;
		}
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			get_error(datash, 126);
			return 1;
		}
	}

	return 0;
}
