#include "main.h"

/**
  * @datash: data relevant (args)
 * Return: 1 on success.
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

		if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
