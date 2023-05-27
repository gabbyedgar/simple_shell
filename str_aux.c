#include "main.h"

/**
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 *
 * Return: Always 0
 */
void rev_string(char *s)
{
	int count = 0, i, j;
	char *str, temp;

	for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}	
	}
}
