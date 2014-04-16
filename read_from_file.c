#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "read_from_file.h"

matrix_t * make_matrix (int rn, int cn)
{
	size_t size;
  matrix_t *new_mat = malloc (sizeof *new_mat);
  if (new_mat == NULL)
    return NULL;
  if ((new_mat->e = malloc ((size_t) rn * (size_t) cn * sizeof *new_mat->e*1000)) == NULL) {
		
    free (new_mat);
    return NULL;
  }
  new_mat->rn = rn;
  new_mat->cn = cn;
  memset (new_mat->e, 0, (size_t) (rn * (size_t) cn * sizeof *new_mat->e*1000));
  return new_mat;
}

void free_matrix (matrix_t * m)
{
  free (m->e);
  free (m);
}


void printToScreen(matrix_t *mat) {
	int i,j;
	printf("[ \n");
	for (i = 0; i<mat->rn; i++) {
		printf("  ");
		for (j = 0; j < mat->cn; j++) {
			printf("%c ", mat->e[i*mat->cn+j]);
		}
		printf("; \n");
	}
	printf("]\n");
}


matrix_t * read_matrix (FILE * in)
{
  int rn, cn;
  int i, j;
	int index=0;
	char x;
  matrix_t *new_mat;
	int ilex=0;

  if (fscanf (in, "%d %d", &rn, &cn) != 2)
    return NULL;
  if ((new_mat = make_matrix (rn, cn)) == NULL)
    return NULL;
	printf("przed while\n");
	while ((x=fgetc(in))!=EOF)
		if(x=='1' || x=='0') {
				new_mat->e[index]=x;
				index++;
			}
  return new_mat;
}




