/*
** EPITECH PROJECT, 2023
** gestion_error_generator
** File description:
** gestoin error generator
*/

#include "bsq.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static void create_double_tab(bsq_s *bsq) {
    bsq->map = malloc(sizeof(char *) * (bsq->longueur + 1));
    for (int i = 0; i < bsq->longueur; i++) {
        bsq->map[i] = malloc(sizeof(char) * (bsq->largeur + 1));
    }

    int x = 0;
    int j = 0;
    int i = 0;

    for (i = 0;  i < bsq->longueur; i++) {
        for (j = 0; j < bsq->largeur; j++) {
            if (bsq->buffer[x] == '\0') {
                x = 0;
            }
            bsq->map[i][j] = bsq->buffer[x];
            x++;
        }
        bsq->map[i][j] = '\0';
    }
    bsq->map[i] = NULL;
}


int gestion_error_generator(char *number, char *str, bsq_s *bsq)
{
    bsq->largeur = atoi(number);
    bsq->longueur = atoi(number);
    bsq->buffer = strdup(str);
    create_double_tab(bsq);

    return SUCCESS;
}
