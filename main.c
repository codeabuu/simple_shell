#include "shell.h"

/**
 * main - entry point
* @argc: arg count
* @argv: arg vector
*
* Return: 0 on success, 1 on error
*/

int main(int argc, char **argv)
{
	info_t info = INFO_INIT;
	int fd = 2;

	__asm__ ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eputs(": 0: Can't open ");
				_eputs(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info.readfd = fd;
	}
	populate_env_list(&info);
	read_history(&info);
	hsh(&info, argv);
	return (EXIT_SUCCESS);
}

