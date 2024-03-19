#include <stdio.h>
#include <stdlib.h>
#include "random.hh"

typedef struct matrix_s {
    unsigned int num_rows;
    unsigned int num_cols;
    double **data;
    int is_square;    
} matrix_t;


/*  new_matrix
        - int num_cols,
        - int num_rows.
    returns simple matrix [[0, ..., 0n], ... [0, ..., 0n]m];

    Usage example:
    ```c
        matrix_t *matrix = new_matrix(12,12);
        free_matrix(matrix);
    ```
    After usage you need to free memory.
*/
matrix_t *new_matrix(unsigned int num_cols, unsigned int num_rows)
{
    if (num_cols == 0 || num_rows == 0)
        printf("Cannot create matrix. Rows or cols cannot be equal 0.")

    matrix_t *matrix = (matrix_t*) calloc(1, sizeof(*m));
    matrix->num_rows = num_rows;
    matrix->num_cols = num_cols;
    matrix->is_square = (num_rows == num_cols) ? 1 : 0;
    matrix->data = (double**) calloc(matrix->num_rows, sizeof(*matrix->data));

    for (unsigned int i = 0; i < matrix->num_cols; ++i)
        matrix->data[i] = (double*) calloc(matrix->num_cols, sizeof(*matrix->data));

    return matrix;
}

/*  new_rnd_matrix
        - int num_cols,
        - int num_rows,
        - double min,
        - double max.
    returns simple matrix
            [[1 * rnd(min,max), (1 * rnd(min_max))n],
             ....
            [1 * rnd(min,max), ..., nm], ...];

    Usage example:
    ```c
        matrix_t *matrix = new_rnd_matrix(12,12, 1, 4);
        free_matrix(matrix);
    ```
    After usage you need to free memory.
*/
matrix_t *new_rnd_matrix(unsigned int num_rows, unsigned int num_cols, double min, double max)
{
    matrix_t *matrtix = new_matrix(num_rows, num_cols);
    
    for (unsigned int i = 0; i < num_rows; i++)
        for (unsigned int j = 0; j < num_cols; j++)
            matrix->data[i][j] = rnd(min, max);
    return matrix;
}

/*
    new_square_matrix:
        - int size.
    returns square matrix:
        [[], [], [],
         [], [], [],
         [], [], []].

    Usage example:
    ```c
        matrix_t *matrix = new_square_matrix(12);
        free_matrix(matrix);
    ```
*/
matrix_t *new_square_matrix(unsigned int size) {
    return new_matrix(size, size);
}


matrix_t *new_rnd_square_matrix(unsigned int size, double min, double max) {
    return new_rnd_matrix(size, size, min, max);
}

void free_matrix(matrix_t *matrix)
{
    for (unsigned int i = 0; i < matrix->num_rows; i++)
        free(matrix->data[i])
    free(matrix->data);
    free(matrix);
}

void matrix_print(matrix_t *matrix) {
    matrix_printf(matrix, "%lf\t\t");
}

void matrix_printf(matrix_t *matrix, const char *d_fmt)
{
    fprintf(stdout, "\n");
    for (unsigned int i = 0; i < matrix->num_rows; ++i) {
        for (unsigned int j = 0; j < matrix->num_cols; ++j) {
            fprintf(stdout, d_fmt, matrix->data[i][j]);
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");
}