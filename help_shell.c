#include "root.h"

/**
 * free_args - Frees up memory taken by args.
 * @args: A null-terminated double pointer containing commands/arguments.
 * @front: A double pointer to the beginning of args.
 */
void free_args(char **args, char **front)
{
	size_t i;

	for (i = 0; args[i] || args[i + 1]; i++)
		free(args[i]);

	free(front);
}

/**
 * get_pid - Gets the current process ID.
 * Description: Opens the stat file, a space-delimited file containing
 *              information about the current process. The PID is the
 *              first word in the file. The function reads the PID into
 *              a buffer and replace the space at the end with a \0 byte.
 *
 * Return: The current process ID or NULL on failure.
 */
char *get_pid(void)
{
	size_t i = 0;
	char *buffer;
	ssize_t file;

	file = open("/proc/self/stat", O_RDONLY);
	if (file == -1)
	{
		perror("Cant read file");
		return (NULL);
	}
	buffer = malloc(120);
	if (!buffer)
	{
		close(file);
		return (NULL);
	}
	read(file, buffer, 120);
	while (buffer[i] != ' ')
		i++;
	buffer[i] = '\0';

	close(file);
	return (buffer);
}

/**
 * get_env_value - Gets the value corresponding to an environmental variable.
 * @beginning: The environmental variable to search for.
 * @len: The length of the environmental variable to search for.
 *
 * Return: If the variable is not found - an empty string.
 *         Otherwise - the value of the environmental variable.
 *
 * Description: Variables are stored in the format VARIABLE=VALUE.
 */
char *get_env_value(char *beginning, int len)
{
	char **var_addr;
	char *rep = NULL, *temp, *var;

	var = malloc(len + 1);
	if (!var)
		return (NULL);
	var[0] = '\0';
	_strncat(var, beginning, len);

	var_addr = _getenv(var);
	free(var);
	if (var_addr)
	{
		temp = *var_addr;
		while (*temp != '=')
			temp++;
		temp++;
		rep = malloc(_strlen(temp) + 1);
		if (rep)
			_strcpy(rep, temp);
	}

	return (rep);
}

/**
 * substitute_arg - Handles variable rep.
 * @line: A double pointer containing the command and arguments.
 * @exe_ret: A pointer to the return value of the last executed command.
 *
 * Description: Replaces $$ with the current PID, $? with the return value
 *              of the last executed program, and envrionmental variables
 *              preceded by $ with their corresponding value.
 */
void substitute_arg(char **line, int *exe_ret)
{	int j, k = 0, len;
	char *rep = NULL, *old_l = NULL, *new_line;

	old_l = *line;
	for (j = 0; old_l[j]; j++)
	{
		if (old_l[j] == '$' && old_l[j + 1] &&
				old_l[j + 1] != ' ')
		{
			if (old_l[j + 1] == '$')
			{	rep = get_pid();
				k = j + 2;
			}
			else if (old_l[j + 1] == '?')
			{	rep = _itoa(*exe_ret);
				k = j + 2;
			}
			else if (old_l[j + 1])
			{
				for (k = j + 1; old_l[k] && old_l[k] != '$' && old_l[k] != ' ';)
					k++;
				len = k - (j + 1);
				rep = get_env_value(&old_l[j + 1], len);
			}
			new_line = malloc(j + _strlen(rep) + _strlen(&old_l[k]) + 1);
			if (!line)
				return;
			new_line[0] = '\0';
			_strncat(new_line, old_l, j);
			if (rep)
			{	_strcat(new_line, rep);
				free(rep);
				rep = NULL;
			}	_strcat(new_line, &old_l[k]);
			free(old_l);
			*line = new_line;
			old_l = new_line;
			j = -1;
		}
	}
}
