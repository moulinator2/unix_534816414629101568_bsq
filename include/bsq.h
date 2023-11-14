/*
** EPITECH PROJECT, 2023
** bsq
** File description:
** header file
*/

#ifndef BSQ
    #define BSQ

    #define FAILURE 84
    #define SUCCESS 0

    typedef struct bsq_s {
        char **map;
        char *buffer;
        int largeur;
        int longueur;
        int first_line_size;
        int row_test;
        int col_test;
        int row_stock;
        int col_stock;
        int size;
    }bsq_s;
    

int gestion_error_file(const char *file_name, bsq_s *bsq);
int gestion_error_generator(char *number, char *str, bsq_s *bsq);
char *open_read(const char *filepath);

int solve_bsq(bsq_s *bsq);
void solve(bsq_s *bsq);

#endif /* !BSQ */
