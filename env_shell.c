#include "main.h"
/**
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);



/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 * @_environ: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;
		}
	}	return (ptr_env + mov);
}


