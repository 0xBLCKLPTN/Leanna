/*
    Filename: Matrix.cc
    Description: All matrix methods.

    UPD: Andrei Ciobanu.
*/
#include "vectors.hh"
#include "random.hh"
#include <stdlib.h>
#include <stdio.h>

typedef struct Matix_s {
    unsigned int num_rows;
    unsigned int num_cols;
    double **data;
    int is_square;
} Matrix_t;

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

// Checks if two matrices have the same dimesions
int is_eqdim(Matrix_t *mat, Matrix_t *mat2) {
    return ((mat->num_cols == mat2->num_cols) &&
            (mat->num_rows == mat2->num_rows))
}

int is_mat_eq(Matrix_t *mat, Matrix_t *mat2 , double tolerance) {
    if (!is_eqdim(mat, mat2)) {
        return 0;
    }

    unsigned int i, j;
    for(i = 0; i < mat->num_rows; i++) {
    for(j = 0; j < mat->num_cols; j++) {
      if (fabs(mat->data[i][j] - mat2->data[i][j]) > tolerance) {
        return 0;
      }
    }
  }
  return 1;

}

void matrix_print(Matrix_t *matrix) {
    matrix_printf(matrix, "%lf\t\t");
}

void matrix_printf(Matrix_t *matirx, const char *d_fmt) {
    unsigned int i, j;
    fprintf(stdout, "\n");
    for(i = 0; i < matrix->num_rows; ++i) {
        for(j = 0; j < matrix->num_cols; ++j) {
            fprintf(stdout, d_fmt, matrix->data[i][j]);
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");
}