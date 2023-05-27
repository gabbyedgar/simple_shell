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


int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);
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
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int)
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *)




#endif
