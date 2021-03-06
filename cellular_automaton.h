#ifndef _CELLULAR_AUTOMATON_H_
#define _CELLULAR_AUTOMATON_H_

#include <stdlib.h>
#include "read_from_file.h"
#include "principles_of_neighborhood.h"

int chge_cell(int nr_live_neighbors, int cell_pos, matrix_t *old_matrix);
matrix_t *save_generation( matrix_t *old_matrix, matrix_t *new_matrix, int type_neighbor);


#endif
