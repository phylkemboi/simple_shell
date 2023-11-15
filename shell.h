#ifndef _SHELL_H
#define _SHELL_H

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

/*buffers*/
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*chain command*/
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

extern char **environ;

/*atoi.c*/
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);
/*envt.c*/
int _myenv(info_t *info);
char *_getenv(info_t *info, const char *name);
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);
int populate_env_list(info_t *info);

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

#endif
