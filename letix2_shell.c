#include "main.h"


/**
 * _reallocdp - reallocates a memory block of a double pointer.
 * @ptr: double pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));
unsigned int i, j;
	int equal;

	for (i = 0; str[i]; i++)
	{
		equal = 0;
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				equal = 1;
				break;
			}
		}
		if (!equal)
			return 0;
	}
	return 1;
}

	return (newptr);
}
