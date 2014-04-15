#include <stdio.h>
#include <stdlib.h>
#include "read_from_file.h"
#include "principles_of_neighborhood.h"

int chge_cell(int nr_live_neighbors, int cell_pos, matrix_t *old_matrix){
	char cell_condition='0';
	if(old_matrix->e[cell_pos]=='1') cell_condition='1';
	if(cell_condition=='0'&&nr_live_neighbors==3) cell_condition='1';
	else {
			if(cell_condition=='1' && (nr_live_neighbors==2 ||nr_live_neighbors==3)) cell_condition='1';
			if(cell_condition=='1' && (nr_live_neighbors>3 || nr_live_neighbors<2)) cell_condition='0';
	}
	return cell_condition;
}
matrix_t *save_generation( matrix_t *old_matrix, matrix_t *new_matrix, int type_neighbor){
	int temp=0;
	//int nr_live_neighbors=0;
	for(temp=0;temp<old_matrix->rn*old_matrix->cn; temp++){
		//nr_live_neighbors=srch_neighbor(temp, old_matrix, type_neighbor);
			
		new_matrix->e[temp]=chge_cell( srch_neighbor(temp, old_matrix, type_neighbor), temp , old_matrix);
	}
	return new_matrix;
}
