#include "main.h"

/**
 * @datash: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(data_shell *datash, int eval)
{
	struct {
		int error_code;
		char* (*error_function)(data_shell *);
	} error_codes[] = {
		{-1, error_env},
		{126, error_path_126},
		{127, error_not_found},
		{2, error_exit_cd}
	};
	int i;

	char *error = NULL;

	for (i = 0; i < sizeof(error_codes) / sizeof(error_codes[0]); i++)
	{

	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}
