#include "main.h"

/**
 * aux_help_alias - Help information for the builtin alias.
 * Return: no return
 */
void aux_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";
char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tChange the shell working directory.\n ";
	
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_cd - Help information for the builtin alias.
 * Return: no return
 */
void aux_help_cd(void)
{
	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}
