/*
** EPITECH PROJECT, 2023
** solve_bsq
** File description:
** solve bsq file
*/

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

void free_all(bsq_s *bsq) {
    for (int i = 0; i < bsq->longueur; i++) {
        free(bsq->map[i]);
    }
    free(bsq->map);

    free(bsq->buffer);
    free(bsq);
}

int solve_bsq(bsq_s *bsq)
{
    solve(bsq);
    for (int i = 0; i < bsq->longueur; i++) {
        write(1, bsq->map[i], bsq->largeur);
        write(1, "\n", 1);
    }
    free_all(bsq);
    return SUCCESS;
}
