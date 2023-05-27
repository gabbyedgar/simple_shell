#include "shell.h"

/**
 * c_dir - checks if ':' is in the current directory.
 * @path: path string
 * @i: index
 * Return: 1 if the path is searchable in the current directory, 0 otherwise.
 */
int c_dir(const char *path, int i)
{
	while (path[i] != ':' && path[i] != '\0')
		i++;

	return (path[i] == ':');
}

/**
 * _loc - locates a command
 *
 * @cmd: command name
 * @_environ: environment variable
 * Return: location of the command.
 */
char *_loc(const char *cmd, char **_environ)
{
	char *path = _getenv("PATH", _environ);

	if (!path)
		return (NULL);

	int cmd_len = _strlen(cmd);
	char *token_path = _strtok(_strdup(path), ":");
	struct stat st;

	while (token_path)
	{
		char *dir = _strcat(_strcat(_strdup(token_path), "/"), cmd);

		if (is_cdir(path, _strlen(token_path)))
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
		}

		if (stat(dir, &st) == 0)
		{
			free(path);
			return (dir);
		}

		free(dir);
		token_path = _strtok(NULL, ":");
	}

	free(path);

	if (stat(cmd, &st) == 0)
		return (_strdup(cmd));

	return (NULL);
}

/**
 * is_exec - determines if it is an executable
 *
 * @datash: data structure
 * Return: 0 if it is not an executable, otherwise returns the index.
 */
int is_exec(data_shell *datash)
{
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
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else
			break;
	}

	if (i == 0)
		return (0);

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

	if (_strcmp(datash->args[0], dir) != 0)
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
	else
	{
		pid_t wpd;
		int state;

		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));

		datash->status = state / 256;
	}
	return(1);
}
