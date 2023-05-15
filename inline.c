#include "shell.h"

/**
* _myquit - will exit shell
* @info: Struct containing potential args.
* constant function prototype.
* Return: exits with given exit status
* (0) if info.argv[0] != "exit"
*/
int _myquit(info_t *info)
{
	int exitconfirm;
if (!info->argv[1])
{
info->err_num = -1;
return (-2);
}

exitconfirm = _eratoi(info->argv[1]);
if (exitconfirm == -1)
{
info->status = 2;
print_err(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}

info->err_num = exitconfirm;
return (-2);
}

/**
* _myassist - changes current dir of the process
* @info: Structure containing potential args.
* constant function prototype.
* Return: Always 0
*/
int _myassist(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

/**
* _mycdir - changes current dir of the process
* @info: Structure containing potential args.
* constant function prototype.
* Return: Always 0
*/
int _mycdir(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenviron(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _getenviron(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenviron(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenviron(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = _getenviron(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_err(info,  "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenviron(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
