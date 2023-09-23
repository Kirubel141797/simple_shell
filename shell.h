#ifndef _SHELL_H_
#define _SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>


/* for read or write buff*/
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


/* for command chain */
#define CMD_NORM         0
#define CMD_OR                1
#define CMD_AND                2
#define CMD_CHAIN        3


/* for converting_number() */
#define CONVERT_LOWERCASE        1
#define CONVERT_UNSIGNED        2


/* for using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0


#define HIST_FILE        ".simple_shell_history"
#define HIST_MAX        4096


extern char **environ;




/**
 * struct liststr - singly linked list
 * @num: A number field
 * @str: the strings.
 * @next: points to a next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_i;


/**
 *struct passinfo - contains pseudo-arguements to pass into the function,
 *                allows uniform prototype for function pointer struct
 *@arg: The string generate from getline containing arguement.
 *@argv: array of a string generates from arg
 *@path: The strings path for the current command
 *@argc: An argument count
 *@line_count: An error count
 *@err_num: An error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: A program filename
 *@env: A linked list local copy of environ
 *@environ: A custom modified copy of environ from LL env
 *@history: A history node
 *@alias: A alias node
 *@env_changed: on if environ was changed
 *@status: A return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: An fd from which to read line input
 *@histcount: A history line number count
 */
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
	list_i *env;
	list_i *history;
	list_i *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_i;


#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}


/**
 *struct builtin - contains a builtin string and related function
 *@type: builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_i *);
} builtin_table;




/* shloop.c */
int hsh(info_i *, char **);
int find_builtin(info_i *);
void find_cmd(info_i *);
void fork_cmd(info_i *);


/* _parser.c */
int is_cmd(info_i *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_i *, char *, char *);


/* loophsh.c */
int loophsh(char **);


/* _errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);


/* _string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);


/* _string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);


/* _exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);


/* _tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);


/* _realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);


/* _memory.c */
int bfree(void **);


/* _atoi.c */
int interactive(info_i *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);


/* _errors1.c */
int _erratoi(char *);
void print_error(info_i *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);


/* _builtin.c */
int _myexit(info_i *);
int _mycd(info_i *);
int _myhelp(info_i *);


/* _builtin1.c */
int _myhistory(info_i *);
int _myalias(info_i *);


/*_getline.c */
ssize_t get_input(info_i *);
int _getline(info_i *, char **, size_t *);
void sigintHandler(int);


/* _getinfo.c */
void clear_info(info_i *);
void set_info(info_i *, char **);
void free_info(info_i *, int);


/* _environ.c */
char *_getenv(info_i *, const char *);
int _myenv(info_i *);
int _mysetenv(info_i *);
int _myunsetenv(info_i *);
int populate_env_list(info_i *);


/* _getenv.c */
char **get_environ(info_i *);
int _unsetenv(info_i *, char *);
int _setenv(info_i *, char *, char *);


/* _history.c */
char *get_history_file(info_i *info);
int write_history(info_i *info);
int read_history(info_i *info);
int build_history_list(info_i *info, char *buf, int linecount);
int renumber_history(info_i *info);


/* _lists.c */
list_i *add_node(list_i **, const char *, int);
list_i *add_node_end(list_i **, const char *, int);
size_t print_list_str(const list_i *);
int delete_node_at_index(list_i **, unsigned int);
void free_list(list_i **);


/* _lists1.c */
size_t list_len(const list_i *);
char **list_to_strings(list_i *);
size_t print_list(const list_i *);
list_i *node_starts_with(list_i *, char *, char);
ssize_t get_node_index(list_i *, list_i *);


/* _vars.c */
int is_chain(info_i *, char *, size_t *);
void check_chain(info_i *, char *, size_t *, size_t, size_t);
int replace_alias(info_i *);
int replace_vars(info_i *);
int replace_string(char **, char *);


#endif
