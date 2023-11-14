/*
** EPITECH PROJECT, 2023
** bsq
** File description:
** main
*/

#include "bsq.h"
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    bsq_s *bsq = malloc(sizeof(bsq_s));

    if (ac == 2) {
        if (gestion_error_file(av[1], bsq) == FAILURE) {
            return FAILURE;
        }
    } else if (ac == 3) {
        if (gestion_error_generator(av[1], av[2], bsq) == FAILURE) {
            return FAILURE;
        }
    } else {
        puts("usage : \"./bsq file_path\" or \"./bsq number struct\"");
        return FAILURE;
    }

    return solve_bsq(bsq);
}
