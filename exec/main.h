#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_line
{
    char *line;
    struct s_line *next;
}t_line;

t_line *parser(char *name);
char *create_temp_file(void);
void compile(char *file_name, t_line *start);
void free_lst(t_line *start);
