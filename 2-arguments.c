#include "shell.h"

/**
 * cmd_history - this displays the history of the command line preceded with
 * line numbers starting from 0
 * @info: this structure contains potential argument
 *
 * Return: 0
 */

int cmd_history(info_t *info)
{
	print_list(info->history_node);
	return (0);
}

/**
 * my_allias - converts alias to strn
 * @info: this structure contains potential argument
 * @strn: string
 *
 * Return: 0, 1
 */

int my_allias(info_t *info, char *strn)
{
	char *b, c;
	int r;

	b = _strnchr(strn, '=');
	if (!b)
		return (1);
	c = *b;
	*b = 0;
	r = remove_node_at_index(&(info->allias),
			node_index(info->allias, node_start(info->allias, strn, -1)));
	*b = c;
	return (r);
}

/**
 * adjust_allias - this adjusts the alias to string
 * @info: this structure contains potential argument
 * @strn: string
 *
 * Return: 0, 1
 */

int adjust_allias(info_t *info, char *strn)
{
	char *b;

	b = _strnchr(strn, '=');
	if (!b)
		return (1);
	if (!*++b)
		return (my_allias(info, strn));

	my_allias(info, strn);
	return (node_ad_end(&(info->allias), strn, 0) == NULL);
}

/**
 * inscribe_allias - this inscribes or print an alias string
 * @ad_node: the node of the alias
 *
 * Return; 1, 0
 */

int inscribe_allias(list_t *ad_node)
{
	char *b = NULL, *i = NULL;

	if (ad_node)
	{
		b = _strnchr(ad_node->strn, '=');
		for (i = ad_node->strn; i <= b; i++);
                _putchar(*i);
		_putchar('\'');
		_puts(b + 1);
		_puts("'\n");

		return (0);
	}
	return (1);
}

/**
 * my_allias - imitates the alias arguments
 * @info: this structure contains potential argument
 *
 * Return: 0
 */

int my_allias(info_t *info)
{
	int j = 0;
	char *b = NULL;
	list_t *ad_node = NULL;

	if (info->argc == 1)
	{
		ad_node = info->allias;
		while (ad_node)
		{
			inscribe_allias(ad_node);
			ad_node = ad_node->next;
		}
		return (0);
	}
	for (j = 1; info->argv[j]; j++)
	{
		b = _strnchr(info->argv[j], '=');
		if (b)
			adjust_allias(info, info->argv[j]);
		else
			inscribe_allias(node_start(info->allias, info->argv[j],
						'='));
	}

	return (0);
}
