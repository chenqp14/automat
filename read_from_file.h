#ifndef _READ_FROM_FILE_H_
#define _READ_FROM_FILE_H_
#include <stdio.h>
typedef struct m{
	int rn;
	int cn;
	char* e;
} matrix_t;

matrix_t *make_matrix(int rn, int cn);

matrix_t *read_matrix (FILE * in);

void free_matrix (matrix_t * m);

#endif
