#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @info: the parameter structure
 * @buf: the character buffer
 * @p: address of current position in buffer
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;
	int found = 0;

	switch (buf[j])
	{
		case '|':
			if (buf[j + 1] == '|')
			{
				buf[j] = 0;
				j++;
				info->cmd_buf_type = CMD_OR;
				found = 1;
			}
			break;
		case '&':
			if (buf[j + 1] == '&')
			{
				buf[j] = 0;
				j++;
				info->cmd_buf_type = CMD_AND;
				found = 1;
			}
			break;
		case ';':
			buf[j] = 0;
			info->cmd_buf_type = CMD_CHAIN;
			found = 1;
			break;
		default:
			break;
	}
	if (found)
	{
		*p = j;
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @info: the parameter structure
 * @buf: the char buffer
 * @p: address of current position in buffer
 * @i: starting position in buffer
 * @len: length of buffer
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter structure
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int i = 0;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_variables - replaces variables in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_variables(info_t *info)
{
	int i;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_str(&(info->argv[i]),
					_strdup(conv_no(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_str(&(info->argv[i]),
					_strdup(conv_no(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_str(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_str(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_str - replace string
 * @old: add of old string
 * @new: new string
 *
 * Return: 1 if replaced
 */
int replace_str(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
