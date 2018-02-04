//
// Created by andreas on 2018-02-03.
//

#include "files.h"

#include <stdio.h>


void cgd_file_to_str(const char *path, char data[])
{
    if (access(path, F_OK) == -1) {
        printf("CGD_FILE_ERROR:\n"
                       "File %s does not exist.\n", path);
        return;
    }

    FILE *fp = fopen(path, "r");

    char c = 0;
    int i = 0;
    while ((c = fgetc(fp)) != EOF)
        data[i++] = c;
    data[i] = '\0';
}
