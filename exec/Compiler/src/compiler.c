#include "../include/compiler.h"

int is_quotation_mark(char c) {
    return (c == '"');
}

char *replace_word(char *str, const char *old_word, const char *new_word)
{    
    t_replace r;

    r.len_old = strlen(old_word);
    r.len_new = strlen(new_word);
    r.count = 0;
    r.ins = str;
    while ((r.ins = strstr(r.ins, old_word))) {
        r.before = r.ins - 1;
        r.after = r.ins + r.len_old;
        if ((r.before >= str && is_quotation_mark(*r.before)) || (r.after && is_quotation_mark(*r.after))) {
            r.ins += r.len_old;
            continue;
        }
        r.count++;
        r.ins += r.len_old;
    }
    if (r.count == 0) {
        return str;
    }
    r.result = malloc(strlen(str) + (r.len_new - r.len_old) * r.count + 1);
    if (!r.result) {
        return NULL;
    }
    r.temp = r.result;
    r.ins = str;
    while (r.count--)
    {
        r.occurrence = strstr(r.ins, old_word);
        r.len_front = r.occurrence - r.ins;
        r.temp = strncpy(r.temp, r.ins, r.len_front) + r.len_front;
        r.before = r.occurrence - 1;
        r.after = r.occurrence + r.len_old;
        if (!(r.before >= str && is_quotation_mark(*r.before)) && !(r.after && is_quotation_mark(*r.after)))
            r.temp = strcpy(r.temp, new_word) + r.len_new;
        else
            r.temp = strncpy(r.temp, r.occurrence, r.len_old) + r.len_old;
        r.ins = r.occurrence + r.len_old;
    }
    strcpy(r.temp, r.ins);
    return (r.result);
}

char *change_line(char *line)
{
    line = replace_loop(line);
    if (!line)
        return (NULL);
    line = replace_define(line);
    if (!line)
        return (NULL);
    line = replace_function(line);
    if (!line)
        return (NULL);
    line = replace_terms(line);
    if (!line)
        return (NULL);
    line = replace_var(line);
    return (line);
}

void compile(char *file_name, t_line *start)
{
    int fd;
    t_line *current;
    char *mdf_line;

    fd = open(file_name, O_WRONLY, 0777);
    if (fd == -1)
    {
        free_lst(start);
        unlink(file_name);
        free(file_name);
        close(fd);
        perror("open error");
        exit(EXIT_FAILURE);
    }
    current = start;
    while (current)
    {
        mdf_line = change_line(current->line);
        if (!mdf_line)
        {
            perror("malloc error");
            free_lst(start);
            unlink(file_name);
            free(file_name);
            close(fd);
            exit(EXIT_FAILURE);
        }
        write(fd, mdf_line, strlen(mdf_line));
        free(mdf_line);
        current = current->next;
    }
    close(fd);
}
