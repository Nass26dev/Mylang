#include "../include/compiler.h"

char *create_cmd(char *file_name)
{
    char *cmd;

    cmd = my_strjoin(CC, file_name);
    if (!cmd)
    {
        perror("malloc erorr");
        unlink(file_name);
        free(file_name);
        exit(EXIT_FAILURE);
    }
    cmd = my_strjoin(cmd, OUTPUT);
    if (!cmd)
    {
        perror("malloc error");
        unlink(file_name);
        free(file_name);
        exit(EXIT_FAILURE);
    }
    return (cmd);
}

char	*my_getenv(char *search, char **env)
{
	int	i;
	int	len;

	i = -1;
	len = strlen(search);
	while (env[++i])
	{
		if (strncmp(env[i], search, len) == 0 && env[i][len] == '=')
			return (env[i] + (len + 1));
	}
	return (NULL);
}

char	*find_path(char *cmd, char **env)
{
	char	*path;
	char	**s_path;
	char	*cmd_path;
	char	*temp;
	int		i;

	path = my_getenv("PATH", env);
	s_path = my_split(path, ':');
	i = -1;
	while (s_path[++i])
	{
		temp = my_strjoin(s_path[i], "/");
		cmd_path = my_strjoin(temp, cmd);
		free(temp);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free_splitted(s_path);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free_splitted(s_path);
	return (NULL);
}

void compile(char *file_name, char **env)
{
    char *cmd;
    char *path;
    char **s_cmd;
    pid_t pid;

    cmd = create_cmd(file_name);
    s_cmd = my_split(cmd, ' ');
    path = find_path(s_cmd[0], env);
    if (!path)
    {
        perror("error compiler");
        unlink(file_name);
        free(file_name);
        free(cmd);
        free_splitted(s_cmd);
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid == 0)
    {
        free(file_name);
        execve(path, s_cmd, env);
        free_splitted(s_cmd);
        free(path);
        free(cmd);
    }
    free(cmd);
    free(path);
    free_splitted(s_cmd);
}
