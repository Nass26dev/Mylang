#include "../include/lexer.h"

void add_node_error(t_line *start, char *line)
{
    free_lst(&start);
    free(line);
    perror("malloc error");
    exit(EXIT_FAILURE);
}

void add_node(t_line **start, char *line)
{
    t_line *new;
    t_line *current;

    new = malloc(sizeof(t_line));
    if (!new)
        add_node_error(*start, line);
    new->line = strdup(line);
    if (!line)
        add_node_error(*start, line);
    if (!*start)
        *start = new;
    else
    {
        current = *start;
        while (current->next)
            current = current->next;
        current->next = new;
    }
}

void free_lst(t_line **start)
{
    t_line *current;
    t_line *next;

    current = *start;
    while (current)
    {
        next = current->next;
        free(current->line);
        free(current);
        current = next;
    }
}
