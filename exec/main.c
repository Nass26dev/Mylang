#include "main.h"

int main(int argc, char **argv)
{
	t_line *start;
	char *temp_name;

	if (argc != 2)
	{
		write(STDERR_FILENO, "invalid args", 12);
		exit (EXIT_FAILURE);
	}
	start = parser(argv[1]);
	temp_name = create_temp_file();
	printf("temp name = %s\n", temp_name);
	compile(temp_name, start);
	unlink(temp_name);
	free(temp_name);
	free_lst(start);
}
