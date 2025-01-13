#ifndef COMPILER_H
#define COMPILER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

# ifndef CC
#  define CC "cc "
# endif

# ifndef OUTPUT
#  define OUTPUT " -o mylang"
# endif

typedef struct s_line
{
    char *line;
    struct s_line *next;
}t_line;

typedef struct s_replace
{
    char *result;
    char *ins;
    char *temp;
    int len_old;
    int len_new;
    int len_front;
    int count;
    int in_quotes;
    char *before;
    char *after;
    char *occurrence;
}t_replace;

void free_lst(t_line **start);
char *replace_word(char *str, const char *old_word, const char *new_word);
char *replace_loop(char *line);
char *replace_terms(char *line);
char *replace_var(char *line);
char *replace_define(char *line);
char *replace_function(char *line);
void	free_splitted(char **splitted);
char	**my_split(const char *s, char c);
char *my_strjoin(char *s1, char *s2);

#endif