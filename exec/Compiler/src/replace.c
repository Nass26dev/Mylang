#include "../include/compiler.h"

char *replace_loop(char *line)
{
    char *mdf_line;

    mdf_line = replace_word(line, "tant que", "while");
    if (!mdf_line)
        return (NULL);
    mdf_line = replace_word(mdf_line, "faire", "do");
    if (!mdf_line)
        return (NULL);
    mdf_line = replace_word(mdf_line, "pour", "for");
    return (mdf_line);
}

char *replace_terms(char *line)
{
    char *mdf_line;

    mdf_line = replace_word(line, "si", "if");
    if (!mdf_line)
        return (NULL);
    mdf_line = replace_word(mdf_line, "sinon si", "else if");
    if (!mdf_line)
        return (NULL);
    mdf_line = replace_word(mdf_line, "sinon", "else");
    return (mdf_line);
}

char *replace_var(char *line)
{
    char *mdf_line;

    mdf_line = replace_word(line, "nombre", "int");
    if (!mdf_line)
        return (NULL);
    mdf_line = replace_word(mdf_line, "car", "char");
    if (!mdf_line)
        return (NULL);
    mdf_line = replace_word(mdf_line, "flottant", "float");
    if (!mdf_line)
        return (NULL);
    mdf_line = replace_word(mdf_line, "statique", "static");
    return (mdf_line);
}

char *replace_define(char *line)
{
    char *mdf_line;

    mdf_line = replace_word(line, "definir", "define");
    if (!mdf_line)
        return (NULL);
    mdf_line = replace_word(mdf_line, "inclure", "include");
    if (!mdf_line)
        return (NULL);
    mdf_line = replace_word(mdf_line, "retourner", "return");
    return (mdf_line);
}

char *replace_function(char *line)
{
    char *mdf_line;

    mdf_line = replace_word(line, "afficher", "printf");
    return (mdf_line);
}