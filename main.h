#ifndef  _MAIN_H_
#define  _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;


/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct 
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} 

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct 
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;





int _history(info_t *info)
int unset_alias(info_t *info, const char *str)
int set_alias(info_t *info, const char *str)
int print_alias(list_t *node
int _myalias(info_t *info)
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
char *error_get_cd(data_shell *datash)
char *error_not_found(data_shell *datash)
char *error_shellexit(data_shell *datash)
int _env(info_t *info)
char *_envget(info_t *info, const char *name)
int _setenv(info_t *info)
int _unsetenv(info_t *info)
int populate_env(info_t *info)
void line_get(char **lineptr, size_t *n, char *buffer, size_t j)
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
int get_help(data_shell *datash)
int get_error(data_shell *datash, int eval)
int shell_exit(data_shell *datash)
int exec_line(data_shell *datash)
char *copy_info(char *name, char *value)
void setenv(char *name, char *value, data_shell *datash)
int _unsetenv(data_shell *datash)
char *_getenv(const char *name, char **_environ)
int _env(data_shell *datash)
int c_dir(const char *path, int i)
char *_loc(const char *cmd, char **_environ)
int is_exec(data_shell *datash)
int check_error(const char *dir, data_shell *datash)
int cmd_exec(data_shell *datash)
int cd_shell(data_shell *datash)
int is_changedir(const char *dir)
int is_changeh(const char *dir)
void rev_string(char *s)
char *_strdup(const char *s)
int _strlen(const char *s)
int cmp_chars(char str[], const char *delim)
char *_strtok(char str[], const char *delim)
int _isdigit(const char *s)
char *_strcat(char *dest, const char *src)
char *_strcpy(char *dest, char *src)
int _strcmp(char *s1, char *s2)
char *_strchr(char *s, char c)
int _strspn(char *s, char *accept)
int get_len(int n)
char *aux_ints(int n)
int _atoi(char *s)
void _memcpy(void *dest, const void *src, unsigned int size)
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
void free_rvar_list(r_var **head)
sep_list *add_sep_node_end(sep_list **head, char sep)
void free_sep_list(sep_list **head)
line_list *add_line_node_end(line_list **head, char *line)
void free_line_list(line_list **head)

#endif
