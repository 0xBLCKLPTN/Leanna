#ifndef VECTORS_HH
#define VECTORS_HH

typedef struct vector_s * Vector_t;

Vector_t Vector3(float x, float y, float z);
Vector_t Vector2(float x, float y);

void add(Vector_t *to_vector, Vector_t *from_vector);
void sub(Vector_t *to_vector, Vector_t *from_vector);
void dot(Vector_t *vec, float sv);
void scale(Vector_t *to_vec, Vector_t *from_vec);
void length(Vector_t *vec);
void normalize(Vector_t *vec);
void Vector_free(Vector_t *vec);
#endif