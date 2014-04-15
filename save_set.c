#include "read_from_file.h"
#include <stdio.h>
#include <stdlib.h>

void set_to_file ( FILE *out, matrix_t *new_matrix){
  int i, j;
  if (new_matrix == NULL) {
    fprintf (out, "Matrix is NULL\n");
    return;
  }

  fprintf (out, "%d %d\n", new_matrix->rn, new_matrix->cn);
  for (i = 0; i < new_matrix->rn; i++) {
    for (j = 0; j < new_matrix->cn - 1; j++)
      fprintf (out, "%d ", new_matrix->e[i * new_matrix->cn + j]-48);
    fprintf (out, "%d\n", new_matrix->e[i * new_matrix->cn + j]-48);
  }
}
