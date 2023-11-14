/*
** EPITECH PROJECT, 2023
** gestion_error_file
** File description:
** gestoin error file
*/

#include "bsq.h"
#include <stddef.h>
#include <stdlib.h>

static void get_dimens(bsq_s *bsq) {
    bsq->first_line_size = 0;

    while (bsq->buffer[bsq->first_line_size] != '\n') {
        bsq->first_line_size++;
    }

    bsq->first_line_size++;
    int j = bsq->first_line_size;
    while (bsq->buffer[j] != '\n') {
        j++;
    }
    bsq->largeur = j - (bsq->first_line_size);
}

static void create_double_tab(bsq_s *bsq) {
    get_dimens(bsq);
    bsq->map = malloc(sizeof(char *) * (bsq->longueur + 1));
    for (int i = 0; i < bsq->longueur; i++) {
        bsq->map[i] = malloc(sizeof(char) * (bsq->largeur + 1));
    }

    int x = bsq->first_line_size;
    int j = 0;
    int i = 0;

    for (i = 0;  i < bsq->longueur; i++) {
        for (j = 0; bsq->buffer[x] != '\n'; j++) {
            bsq->map[i][j] = bsq->buffer[x];
            x++;
        }
        bsq->map[i][j] = '\0';
        x++;
    }
    bsq->map[i] = NULL;
}

int gestion_error_file(const char *file_name, bsq_s *bsq) {
    bsq->buffer = open_read(file_name);

    if (bsq->buffer == NULL) {
        return FAILURE;
    }
    bsq->longueur = atoi(bsq->buffer);

    create_double_tab(bsq);
    return SUCCESS;
}
