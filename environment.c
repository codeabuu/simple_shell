#include "shell.h"

/**
* _myenvironment - prints current env
* @info: Struct containing potential args. Used to maintain
*          constant function prototype.
* Return: Always 0
*/
int _myenvironment(info_t *info)
{
	print_ls_string(info->env);
	return (0);
}

/**
* _getenviron - gets value of an environ var
* @info: Structure containing potential arguments. Used to maintain
* @name: env var name
*
* Return: the value
*/
char *_getenviron(info_t *info, const char *name)
{
	list_t *node;
	char *p;

	for (node = info->env; node != NULL; node = node->next)
	{
	p = starts_with(node->str, name);
	if (p && *p)
		return (p);
	}
	return (NULL);
}

/**
* _mysetenviron - Initialize a new env var,
*             or modify an existing one
* @info: Structure containing potential arguments. Used to maintain
*        constant function prototype.
*  Return: Always 0
*/
int _mysetenviron(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
	{
		return (0);
	}
	return (1);
}

/**
* _myunsetenviron - Rem environment var
* @info: Structure containing potential arguments. Used to maintain
*        constant function prototype.
* Return: Always 0
*/
int _myunsetenviron(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	i = 1;
	while (i <= info->argc)
	{
	_unsetenv(info, info->argv[i]);
	i++;
	}
	return (0);
}

/**
* populate_env_list - populates environment linked ls
* @info: Structure containing potential arguments. Used to maintain
*          constant function prototype.
* Return: Always 0
*/
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	i = 0;
	while (environ[i])
	{
		add_node_end(&node, environ[i], 0);
		i++;
	}
	info->env = node;
	return (0);

}
