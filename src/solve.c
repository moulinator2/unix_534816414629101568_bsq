/*
** EPITECH PROJECT, 2023
** solve
** File description:
** solve
*/

#include "bsq.h"
#include <stdbool.h>

static bool is_a_square(bsq_s *bsq, int row, int col, int size) {
    if (col + size >= bsq->longueur) {
        return false;
    }
    for (int i = col; i <= col + size; i++) {
        for (int j = row; j <= row + size; j++) {
            if (bsq->map[i][j] != '.') {
                bsq->row_test = j;
                return false;
            }
        }
    }
    return true;
}

static bool test_for_size_plus_un(bsq_s *bsq, int row, int col, int size) {
    if (col + size >= bsq->longueur) {
        return false;
    }
    for (int i = col; i <= col + size; i++) {
        if (bsq->map[i][row + size] != '.') {
            return false;
        }
    }
    for (int i = row; i <= row + size; i++) {
        if (bsq->map[col + size][i] != '.') {
            return false;
        }
    }
    return true;
}

static void replace(bsq_s *bsq, int size) {
    for (int i = bsq->col_stock; i < bsq->col_stock + size; i++) {
        for (int j = bsq->row_stock; j < bsq->row_stock + size; j++) {
            bsq->map[i][j] = 'x';
        }
    }
}

static bool is_point_in_map(bsq_s *bsq) {
    for (int i = 0; i < bsq->longueur; i++) {
        for (int j = 0; j < bsq->largeur; j++) {
            if (bsq->map[i][j] == '.') {
                return true;
            }
        }
    }
    return false;
}


void solve(bsq_s *bsq)
{
    bool square_exist = is_point_in_map(bsq);
    int size = 1;
    bsq->col_test = 0;
    bsq->row_test = 0;


    while (bsq->col_test <= bsq->longueur - size) {
        bsq->row_test = 0;
        while (bsq->row_test <= bsq->largeur - size) {
            if (is_a_square(bsq, bsq->row_test, bsq->col_test, size)) {
                size++;
                bsq->row_stock = bsq->row_test;
                bsq->col_stock = bsq->col_test;
                while (test_for_size_plus_un(bsq, bsq->row_test, bsq->col_test, size)) {
                    size++;
                }
            }
            bsq->row_test++;
        }
        bsq->col_test++;
    }
    if (size != 1) {
        replace(bsq, size);
    } else if (square_exist) {
        for (int i = 0; i < bsq->longueur; i++) {
            for (int j = 0; j < bsq->largeur; j++) {
                if (bsq->map[i][j] == '.') {
                    bsq->map[i][j] = 'x';
                    return;
                }
            }
        }
    }
}
