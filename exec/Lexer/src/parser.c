#include "../include/lexer.h"

int	open_file(char *name)
{
	int fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		perror("open error");
		exit (EXIT_FAILURE);
	}
    return (fd);
}

t_line *parse_file(int fd)
{
    t_line *start;

    start = NULL;
    char *str;

    while (1)
    {
        str = get_next_line(fd);
        if (!str)
            break ;
        add_node(&start, str);
        free(str);
    }
    return (start);
}

t_line *parser(char *name)
{
    t_line *start;
    int fd;

    fd = open_file(name);
    start = parse_file(fd);
    return (start);
}
