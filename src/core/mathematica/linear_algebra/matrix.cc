/*
    Filename: Matrix.cc
    Description: All matrix methods.

    UPD: Andrei Ciobanu.
*/
#include "vectors.hh"
#include <stdlib.h>
#include <stdio.h>

typedef struct Matix_s {
    unsigned int num_rows;
    unsigned int num_cols;
    double **data;
    int is_square;
} Matrix_t;

#define	RAND_MAX	0x7fffffff
double rnd(double min, double max) {
  double d;
  d = (double) rand() / ((double) RAND_MAX + 1);
  return (min + d * (max - min));
}

Matrix_t* Matrix(unsigned int num_rows, unsigned int num_cols) {
    if (num_rows == 0 || num_cols == 0) {
        printf("Cannot create matrix. Num rows or num cols is null.\n");
    }

    Matrix_t* m = (Matrix_t*) calloc(1, sizeof(*m));
    // check memory f(m).
    m->num_rows = num_rows;
    m->num_cols = num_cols;
    m->is_square = (num_rows == num_cols) ? 1 : 0;
    m->data = (double**) calloc(m->num_rows, sizeof(*m->data));
    // check mem f(m->data).

    for (unsigned int i = 0; i < m->num_cols; ++i) {
        m->data[i] = (double*) calloc(m->num_cols, sizeof(*m->data));
        // check mem f(m->data[i])
    }
    return m;
}

void Matrix_free(Matrix_t *mat) {
    unsigned int i;
    for (i = 0; i < mat->num_rows; ++i) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

Matrix_t *Matrix_rnd(unsigned int num_rows, unsigned int num_cols, double min, double max) {
    Matrix_t *mat = Matrix(num_rows, num_cols);
    unsigned int i, j;

    for(i = 0; i < num_rows; i++) {
        for(j = 0; j < num_cols; j++) {
        mat->data[i][j] = rnd(min, max);
        }
    }
    return mat;
}

Matrix_t *Matrix_square(unsigned int size) {
    return Matrix(size, size);
}

Matrix_t *Matrix_square_rnd(unsigned int size, double min, double max) {
    return Matrix_rnd(size, size, min, max);
}

Matrix_t *Matrix_eye(unsigned int size) {
    Matrix_t *mat = Matrix(size, size);

    for(unsigned int i = 0; i < mat->num_rows; i++) {
        mat->data[i][i] = 1.0;
    }
  return mat;
}