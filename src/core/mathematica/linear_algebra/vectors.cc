#include <stdio.h>
#include <stdlib.h>
#include <math.h>


static void __memory_callback(int *ptr, int operation) {
  switch (operation) {
    case 0:
      printf("[VMC]->Memory successfully deallocated. Addr: %d\n", ptr);
      break;
    case 1:
      printf("[VMC]->Memory successfully allocated. Addr: %d\n", ptr);
      break;
    default:
      break;
  }
}

typedef struct vector_s {
  int* ptr;
  int is_normalized;
  int elements_count;
} Vector_t;

int* __allocate_memory(int ec) {
  int* ptr = (int*) malloc (ec * sizeof(float));
  if (ptr == NULL) {
    printf("Memory not allocated.\n");
    exit(0);
  }
  __memory_callback(ptr, 1);
  return ptr;
}

void Vector_free(Vector_t *vec) {
  __memory_callback(vec->ptr, 0);
  free(vec->ptr);
  free(vec);
}

Vector_t Vector3(float x, float y, float z) {
  int* ptr = __allocate_memory(3);
  ptr[0] = x;
  ptr[1] = y;
  ptr[2] = z;
  
  Vector_t vec = { ptr , 0, 3};
  return vec;
}

Vector_t Vector2(float x, float y) {
  int* ptr = __allocate_memory(2);
  ptr[0] = x;
  ptr[1] = y;
  Vector_t vec = { ptr, 0, 2};
  return vec;
}

void add(Vector_t *to_vector, Vector_t *from_vector) {
  for (unsigned int i = 0; i < to_vector->elements_count; i++) {
    to_vector->ptr[i] += from_vector->ptr[i];
  }
}


void sub(Vector_t *to_vector, Vector_t *from_vector) {
  for (unsigned int i = 0; i < to_vector->elements_count; i++) {
    to_vector->ptr[i] -= from_vector->ptr[i];
  }
}

void dot(Vector_t *vec, float sv) {
  for (unsigned int i = 0; i < vec->elements_count; i++)
    vec->ptr[i] *= sv;
}

void scale(Vector_t *to_vec, Vector_t *from_vec) {
  for (unsigned int i = 0; i < to_vec->elements_count; i++)
    to_vec->ptr[i] *= from_vec->ptr[i];
}

float length(Vector_t *vec) {
  float len;
  
  for (unsigned int i = 0; i < vec->elements_count; i++)
    len += vec->ptr[i] * vec->ptr[i];

  return sqrt(len);
}

void normalize(Vector_t *vec) {
  float len = length(vec);
  for (unsigned int i = 0; i < vec->elements_count; i++)
    vec->ptr[i] *= len;
}

/*
int main(int argc, char* argv[]) {
  Vector_t vec = Vector3(2.0,2.0,2.0);
  __deallocate_memory(&vec);
  
  return 0;
}
*/
