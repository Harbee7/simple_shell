#include "shell.h"

/**
 * am_active - returns true if sherll is in a active mode
 * @inform: the struct address
 *
 * Return: 1, 0
 */

int am_active(inform_t *inform)
{
	return (isatty(STDIN_FILENO) && inform->readfd <= 2);
}

/**
 * is_dels - to check if a char is delimeter
 * @a: characteer to check
 * @dels: the del string
 *
 * Return: 1, 0
 */

int is_dels(char a, char *dels)
{
	while (*dels)
		if (*dels++ == a)
			return (1);
		else
			return (0);
}

/**
 * _atoi - used to convert a string to an integer
 * @b: string to be converted
 *
 * Return: 0, 1
 */

int _atoi(char *b)
{
	int j, sign = 1, flag = 0, op;
	unsigned int r = 0;

	for (j = 0; b[j] != '\0' && flag != 2; j++)
	{
		if (b[j] == '-')
			sign *= -1;

		if (b[j] >= '0' && b[j] <= '9')
		{
			flag = 1;
			r *= 10;
			r += (b[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		op = -r;
	else
		op = r;

	return (op);
}

/**
 * is_alpha - to check for alphabetic char
 * @c: input value
 *
 * Return: 1, if c is alphabetic, 0 if otherwise
 */

int is_alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
