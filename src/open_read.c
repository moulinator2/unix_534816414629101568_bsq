/*
** EPITECH PROJECT, 2023
** open_read
** File description:
** open read
*/

#include "bsq.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *open_read(const char *filepath) {
    struct stat stats;
    if (stat(filepath, &stats) == -1) {
        return NULL;
    }
    
    int a = open(filepath, O_RDONLY);
    if (a == -1) {
        return NULL;
    }

    char *lect = malloc(stats.st_size + 1);
    if (lect == NULL) {
        close(a);
        return NULL;
    }
    
    ssize_t b = read(a, lect, stats.st_size);
    if (b == -1) {
        free(lect);
        close(a);
        puts(filepath);
        return NULL;
    }

    lect[stats.st_size] = '\0';
    close(a);

    return lect;
}
