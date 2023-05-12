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

