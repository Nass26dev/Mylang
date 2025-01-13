#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_line
{
    char *line;
    struct s_line *next;
}t_line;

// get_next_line.c
char	*get_next_line(int fd);
void free_lst(t_line *start);
void add_node(t_line **start, char *line);
t_line *parser(char *name);

#endif