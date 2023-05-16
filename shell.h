#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcnti.h>
#include <sys/stat.h>

/* Header files for read and write buffer */
#define READ_BUFFER_SIZE 1024
#define WRITE_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

/* Header files to convert number */
#define CONVERT_TO_LOWERCASE 1
#define CONVERT_TO_UNSIGNED 2

/* Header files used for system getline */
#define _GETLINE 0
#define _STRTOK 0

/* Header files for command chain */
#define CMD_NORMAL 0
#define CMD_AND 1
#define CMD_OR 2
#define CMD_CHAIN 3

/* Header files used to set the name and size of history file */
#define HISTORY_FILE 
#define HISTORY_MAX 4096

/* Header files used to declare the global variable environment
 * which is usaed to access environmental variables */
extern char **environ;

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
	struct liststrn *next_node
} list_t;

/**
 * structure info - contains some info to pass into a function
 * @arg: argument
 * @argc: argument count
 * @argv: argument vector
 * @error_count: error count
 * @path: string path
 * @error_number: error number for exit
 * @flag_count: if on, count the line of input
 * @file_name: program file name
 * @local_env: the linked list local copy of environ
 * @modifed_environ: modified copy of environ
 * @alias: alias node
 * @environ_changed: on if environment was changed
 * @history_node: history node
 * @status: return status
 * @cmd_buffer: address of pointer to cmd_buffer
 * @readfd: the fd from which to read line input
 * @cmd_buffer_type: cmd buffer type
 * @history_count: history line number count
 */

typedef structure info
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
	list_t *local_env;
	list_t *allias;
	char **modified_environ;
	int environ_changed;
	int status;
	char **cmd_buffer;
	int readfd;
	int cmd_buffer_type;
	int history_count;
} inform_t;

#define INFORM_INIT\
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * structure builtin - contains builtin string
 * @funct: function
 * @flag_type: builtin command flag type
 */

typedef structure builtin
{
	char *flag_type;
	int (*funct)(inform_t*);
} builtin_tab;

/* 0-betty.c */
int am_active(inform_t *inform);
int is_dels(char, char *);
int _atoi(char *);
int is_alpha(int);
