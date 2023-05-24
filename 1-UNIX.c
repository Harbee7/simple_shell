#include "shell.h"

/**
 * my_exit - it exits the shell
 * @info: this structure contains potential argument
 *
 * Return: 0
 */

int my_exit(info_t *info)
{
	int e;

	if (info->argv[1])
	{
		e = erroratoi(info->argv[1]);
		if (e == -1)
		{
			info->status  = 2;
			print_error(info, "incorrect number: ");
			_puts(info->argv[1]);
			_putchar('\n');
			return (1);
		}

		info->errror_number = _erroratoi(info->argv[1]);
		return (-2);
	}
	info->error_number = -1;
	return (-2);
}

/**
 * my_help - it changes the current dir of the whole process
 * @info: this structure contains potential argument
 *
 * Return: 0
 */

int my_help(info_t *info)
{
	char **c;

	c = info->argv;
	_puts("please help. This function is not yet implemented \n");
	if (0)
		_puts(*c);
	return (0);
}

/**
 * change_dir - changes the current directory of the whole process
 * @info: this structure contains potential argument
 *
 * Return: 0
 */

int change_dir(info_t *info)
{
	char *c, *d, buffer[1024];
	int ch;

	c = getcwd(buffer, 1024);
	if (!c)
		_puts("TODO: >>getcwd this is a failure emessage here<<\n");
	if (!info->argv[1])
	{
		d = getenv(info, "HOMEDIRECTORY=");
		if (!d)
				chdir((dir = getenv(info, "PRINTWORKINGDIRECTORY="))
						? dir : "/");
		else
			ch = chdir(dir);
	}
	else if (_strncmp(info->argv[1], "-") == 0)
	{
		if (!getenv(info, "OLDPRINTWORKINGDIRECTORY="))
		{
			_puts(c);
			_putchar('\n');
			return (1);
		}
		_puts(getenv(info, "OLDPRINTWORKINGDIRECTORY=")), _putchar('\n');
			chdir((dir = getenv(info, "OLDPRINTWORKINGDIRECTORY=")) ? dir : "/");
	}
	else
		ch = chdir(info->argv[1]);
	if (ch == -1)
	{
		print_error(info, "I can't change directory to ");
		_puts(info->argv[1], _putchar('\n'));
	}
	else
	{
		_setenv(info, "OLDPRINTWORKINGDIRECTORY", getenv(info,
					"PRINTWORKINGDIRECTORY="));
		_setenv(info, "PRINTWORKINGDIRECTORY", getcwd(buffer, 1024));
	}
	return (0);
}
