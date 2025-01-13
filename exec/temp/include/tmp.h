#ifndef TMP_H
#define TMP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BASE_FILENAME "file_tmp"
#define MAX_TRIES 2147483647
#define EXT ".c"

char *create_temp_file(void);

#endif