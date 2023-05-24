#include "shell.h"

/**
 * my_exit - it exits the shell
 * @inform: this structure contains potential argument
 *
 * Return: 0
 */

int my_exit(inform_t *inform)
{
	int e;

	if (inform->argv[1])
	{
		e = erroratoi(inform->argv[1]);
		if (e == -1)
		{
			inform->status  = 2;
			print_error(inform, "incorrect number: ");
			_eputs(inform->argv[1]);
			_eputchar('\n');
			return (1);
		}

		inform->errror_number = _erroratoi(inform->argv[1]);
		return (-2);
	}
	inform->error_number = -1;
	return (-2);
}

/**
 * my_help - it changes the current dir of the whole process
 * @inform: this structure contains potential argument
 *
 * Return: 0
 */

int my_help(inform_t *inform)
{
	char **c;

	c = inform->argv;
	_puts("please help. This function is not yet implemented \n");
	if (0)
		_puts(*c);
	return (0);
}

/**
 * change_dir - changes the current directory of the whole process
 * @inform: this structure contains potential argument
 *
 * Return: 0
 */

int change_dir(inform_t *inform)
{
	char *c, *d, buffer[1024];
	int ch;

	c = getcwd(buffer, 1024);
	if (!c)
		_puts("TODO: >>getcwd this is a failure emessage here<<\n");
	if (!inform->argv[1])
	{
		d = _getenv(inform, "HOMEDIRECTORY=");
		if (!d)
				chdir((dir = _getenv(inform, "PRINTWORKINGDIRECTORY="))
						? dir : "/");
		else
			ch = chdir(dir);
	}
	else if (_strncmp(inform->argv[1], "-") == 0)
	{
		if (!_getenv(inform, "OLDPRINTWORKINGDIRECTORY="))
		{
			_puts(c);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inform, "OLDPRINTWORKINGDIRECTORY=")), _putchar('\n');
			chdir((dir = _getenv(inform, "OLDPRINTWORKINGDIRECTORY=")) ? dir : "/");
	}
	else
		ch = chdir(inform->argv[1]);
	if (ch == -1)
	{
		print_error(inform, "I can't change directory to ");
		_eputs(inform->argv[1], -eputchar('\n');
	}
	else
	{
		_setenv(inform, "OLDPRINTWORKINGDIRECTORY", _getenv(inform,
					"PRINTWORKINGDIRECTORY="));
		_setenv(inform, "PRINTWORKINGDIRECTORY", getcwd(buffer, 1024));
	}
	return (0);
}
