#ifndef _PRINCIPLES_OF_NEIGHBORHOOD_H_
#define _PRINCIPLES_OF_NEIGHBORHOOD_H_

#include "read_from_file.h"
#include <stdlib.h>
#include <stdio.h>

void upper_left_corner(int *nr_live_neighbors, int cell_pos, matrix_t  *old_matrix, int type_neighbor);
void upper_right_corner(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor);
void upper_edge(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor);
void lower_left_corner(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor);
void lower_right_corner(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor);
void lower_edge(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor);
void left_edge(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor);
void right_edge(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor);
void centre(int  *nr_live_neighbors,int cell_pos, matrix_t *old_matrix, int type_neighbor);
int srch_neighbor(int cell_pos, matrix_t *old_matrix, int type_neighbor);
#endif
