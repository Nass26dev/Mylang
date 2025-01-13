#include "../include/tmp.h"

int intlen(int num)
{
    int len;

    len = 0;
    if (num == 0) {
        return 1;
    }
    if (num < 0) {
        num = -num;
        len++;
    }
    while (num != 0) {
        num = num / 10;
        len++;
    }
    return (len);
}

char* itoa(int num) {
    int len;
    char* str;
    int i;
    int is_negative;
    
    is_negative = 0;
    i = 0;
    len = intlen(num);
    str = malloc(len + 1);
    if (str == NULL)
        return NULL;
    if (num < 0) {
        is_negative = 1;
        num = -num;
    }
    while (num != 0)
    {
        str[i++] = (num % 10) + '0';
        num = num / 10;
    }
    if (is_negative) {
        str[i++] = '-';
    }
    str[i] = '\0';
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return (str);
}

char *my_strjoin(char *s1, char *s2)
{
    char	*str;
	int		i;

	i = -1;
	str = malloc((strlen((char *)s1) + strlen((char *)s2)) + 1);
	if (!str)
		return (NULL);
	while (*s1)
		str[++i] = *s1++;
	while (*s2)
		str[++i] = *s2++;
	str[++i] = 0;
	return (str);
}

char *create_temp_file(void)
{
    int fd;
    int i;
    char *filename;
    char *temp;
    char *temp_nb;

    i = 1;
    while (i <= MAX_TRIES)
    {
        if (i == 1)
        {
            filename = malloc(strlen(BASE_FILENAME) + 1);
            temp = my_strjoin(BASE_FILENAME, EXT);
            strcpy(filename, temp);
        }
        else
        {
            filename = malloc((strlen(BASE_FILENAME) + intlen(i)) + 1);
            temp_nb = itoa(i);
            if (!temp_nb)
                return (free(filename), NULL);
            temp = my_strjoin(BASE_FILENAME, temp_nb);
            if (!temp)
                return (free(filename), free(temp_nb), NULL);
            temp = my_strjoin(temp, EXT);
            strcpy(filename, temp);
            free(temp);
        }
        fd = open(filename, O_CREAT | O_EXCL, 0777);
        if (fd != -1)
        {
            close(fd);
            return (filename);
        }
        free(filename);
        i++;
    }
    write(STDERR_FILENO, "impossible to create tmp file", 29);
    return (NULL);
}
