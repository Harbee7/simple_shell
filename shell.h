#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

/* Header files for read and write buffer */
#define READ_BUFFER_SIZE 1024
#define WRITE_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

/* Header files used for system getline */
#define _GETLINE 0
#define _STRNTOK 0

/* Header files for command chain */
#define CMD_NORMAL 0
#define CMD_AND 1
#define CMD_OR 2
#define CMD_CHAIN 3

/* to convert_number */
#define CONVERT_TO_LOWERCASE 1
#define CONVERT_TO_UNSIGNED 2

/* Header files used to set the name and size of history file */
#define HISTORY_FILE 
#define HISTORY_MAX 4096

/* Header files used to declare the global variable environment
 * which is usaed to access global variables */
extern char **global;

/**
 * struct liststrn - singly linked list
 * @a: number field
 * @strn: the string
 * @next_node: points to the next node
 */

typedef struct liststrn
{
	int a;
	char *strn;
	struct liststrn *next_node;
} list_t;

/**
 * struct info - contains some info to pass into a function
 * @arg: argument
 * @argc: argument count
 * @argv: argument vector
 * @error_count: error count
 * @path: string path
 * @error_number: error number for exit
 * @flag_count: if on, count the line of input
 * @file_name: program file name
 * @local_global: the linked list local copy of global var
 * @modifed_global: modified copy of global var
 * @alias: alias node
 * @global_changed: on if global var was changed
 * @history_node: history node
 * @status: return status
 * @cmd_buffer: address of pointer to cmd_buffer
 * @readfd: the fd from which to read line input
 * @cmd_buffer_type: cmd buffer type
 * @history_count: history line number count
 */

typedef struct info
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int error_count;
	int error_number;
	int flag_count;
	char *file_name;
	list_t *history_node;
	list_t *local_global;
	list_t *allias;
	char **modified_global;
	int global_changed;
	int status;
	char **cmd_buffer;
	int readfd;
	int cmd_buffer_type;
	int history_count;
} info_t;


/**
 * struct arguments - contains builtin string
 * @funct: function
 * @flag_type: builtin command flag type
 */

typedef struct arguments
{
	char *flag_type;
	int (*funct)(info_t*);
} arguments_tab;

/* 0-betty.c */
int am_active(info_t *info);
int is_dels(char, char *);
int is_alpha(int);
int _atoi(char *);

/* 1-UNIX.c */
int my_exit(info_t *);
int my_help(info_t *);
int change_dir(info_t *);
int _putchar(char c);

/* 2-arguments.c */
int cmd_history(info_t *);
int my_allias(info_t *);
int adjust_allias(info_t *);
int inscribe_allias(list_t *ad_node);
int my_allias(info_t *);

/* 3-PATH.c */
char *get_global(info_t *, const char *);
int my_global(info_t *);
int set_global(info_t *);
int unset_global(info_t *);
int populate_global_list(info_t *);

/* 4-exit.c */

#endif
