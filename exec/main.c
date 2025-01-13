#include "main.h"

int main(int argc, char **argv, char **env)
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
	trad(temp_name, start);
	free_lst(&start);
	compile(temp_name, env);
	unlink(temp_name);
	free(temp_name);
}
