#include "shell.h"

/**
 * cmd_history - this displays the history of the command line preceded with
 * line numbers starting from 0
 * @inform: this structure contains potential argument
 *
 * Return: 0
 */

int cmd_history(inform_t *inform)
{
	print_list(inform->history_node);
	return (0);
}

/**
 * my_alias - converts alias to strn
 * @inform: this structure contains potential argument
 * @strn: string
 *
 * Return: 0, 1
 */

int my_alias(inform_t *inform, char *strn)
{
	char *b, c;
	int r;

	b = _strnchr(strn, '=');
	if (!b)
		return (1);
	c = *b;
	*b = 0;
	r = remove_node_at_index(&(inform->alias),
			node_index(inform->alias, node_start(inform->alias, strn, -1)));
	*b = c;
	return (r);
}

/**
 * adjust_alias - this adjusts the alias to string
 * @inform: this structure contains potential argument
 * @strn: string
 *
 * Return: 0, 1
 */

int adjust_alias(inform_t *inform, char *strn)
{
	char *b;

	b = _strnchr(strn, '=');
	if (!b)
		return (1);
	if (!*++b)
		return (my_alias(inform, strn));

	my_alias(inform, strn);
	return (node_ad_end(&(inform->alias), strn, 0) == NULL);
}

/**
 * inscribe_alias - this inscribes or print an alias string
 * @ad_node: the node of the alias
 *
 * Return; 1, 0
 */

int inscribe_alias(list_t *ad_node)
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
 * my_alias - imitates the alias arguments
 * @inform: this structure contains potential argument
 *
 * Return: 0
 */

int my_alias(inform_t *inform)
{
	int j = 0;
	char *b = NULL;
	list_t *ad_node = NULL;

	if (inform->argc == 1)
	{
		ad_node = inform->alias;
		while (ad_node)
		{
			inscribe_alias(ad_node);
			ad_node = ad_node->next;
		}
		return (0);
	}
	for (j = 1; inform->argv[j]; j++)
	{
		b = _strnchr(inform->argv[j], '=');
		if (b)
			adjust_alias(inform, inform->argv[j]);
		else
			inscribe_alias(node_start(inform->alias, inform->argv[j],
						'='));
	}

	return (0);
}
