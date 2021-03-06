#include <stdlib.h>
#include <stdio.h>
#include "read_from_file.h"
void upper_left_corner(int *nr_live_neighbors, int cell_pos, matrix_t  *old_matrix,int type_neighbor){
		if(old_matrix->e[cell_pos+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+1+old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(type_neighbor==1){
			if(old_matrix->e[old_matrix->cn-1]=='1') 	*nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[old_matrix->cn*old_matrix->rn-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[old_matrix->cn*(old_matrix->rn-1)]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[cell_pos+old_matrix->cn-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[old_matrix->cn*(old_matrix->rn-1)+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		}	
}
void upper_right_corner(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor){
		if(old_matrix->e[cell_pos-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-1+old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(type_neighbor==1){
			if(old_matrix->e[old_matrix->cn*old_matrix->rn-2]=='1') 	*nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[old_matrix->cn*old_matrix->rn-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[old_matrix->cn*(old_matrix->rn-1)]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[0]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[cell_pos+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		}
}
void upper_edge(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor){
		
		if(old_matrix->e[cell_pos-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-1+old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+1+old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(type_neighbor==1){
			if(old_matrix->e[cell_pos+old_matrix->cn*(old_matrix->rn-1)-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[cell_pos+old_matrix->cn*(old_matrix->rn-1)]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[cell_pos+old_matrix->cn*(old_matrix->rn-1)+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		}
}
void lower_left_corner(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor){
		if(old_matrix->e[cell_pos+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-old_matrix->cn+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(type_neighbor==1){
			if(old_matrix->e[cell_pos-old_matrix->cn*(old_matrix->rn-2)-1]=='1') 	*nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[old_matrix->cn*old_matrix->rn-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[old_matrix->cn*(old_matrix->rn-1)-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[0]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		}

}
void lower_right_corner(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor){	
		if(old_matrix->e[cell_pos-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-old_matrix->cn-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(type_neighbor==1){
			if(old_matrix->e[old_matrix->cn*(old_matrix->rn-2)]=='1') 	*nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[old_matrix->cn*(old_matrix->rn-1)]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[cell_pos-old_matrix->cn*(old_matrix->rn-1)-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[0]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[old_matrix->cn-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		}	

}
void lower_edge(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor){
		
		if(old_matrix->e[cell_pos-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-old_matrix->cn-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-old_matrix->cn+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;					
		if(old_matrix->e[cell_pos+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(type_neighbor==1){
			if(old_matrix->e[cell_pos-old_matrix->cn*(old_matrix->rn-1)-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[cell_pos-old_matrix->cn*(old_matrix->rn-1)]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[cell_pos-old_matrix->cn*(old_matrix->rn-1)+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		}	

}
void left_edge(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor){
		if(old_matrix->e[cell_pos-old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-old_matrix->cn+1]=='1')*nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+1+old_matrix->cn]=='1')*nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(type_neighbor==1){
			if(old_matrix->e[cell_pos-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[cell_pos-1+old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[cell_pos-1+2*old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		}
	
}
void right_edge(int  *nr_live_neighbors,int cell_pos, matrix_t  *old_matrix, int type_neighbor){	
		if(old_matrix->e[cell_pos-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-old_matrix->cn-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-1+old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(type_neighbor==1){
			if(old_matrix->e[cell_pos+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[cell_pos+1-old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
			if(old_matrix->e[cell_pos+1-2*old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		}	

	
}
void centre(int  *nr_live_neighbors,int cell_pos, matrix_t *old_matrix, int type_neighbor){
		if(old_matrix->e[cell_pos-old_matrix->cn-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-old_matrix->cn+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+old_matrix->cn-1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+old_matrix->cn]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
		if(old_matrix->e[cell_pos+old_matrix->cn+1]=='1') *nr_live_neighbors=*nr_live_neighbors+1;
}
int srch_neighbor(int cell_pos, matrix_t *old_matrix, int type_neighbor){
	int nr_live_neighbors=0;
	if(cell_pos==0)upper_left_corner( &nr_live_neighbors, cell_pos, old_matrix, type_neighbor);
	else{
		if(cell_pos==old_matrix->cn-1)
			upper_right_corner( &nr_live_neighbors, cell_pos, old_matrix, type_neighbor); 
			else {
				if(cell_pos<old_matrix->cn)
 					upper_edge(&nr_live_neighbors, cell_pos, old_matrix, type_neighbor);
				else{
					 if(cell_pos==old_matrix->cn*(old_matrix->rn-1)) 
							lower_left_corner( &nr_live_neighbors, cell_pos, old_matrix, type_neighbor);
						else{
							if(cell_pos==old_matrix->rn*old_matrix->cn-1)
								lower_right_corner( &nr_live_neighbors, cell_pos , old_matrix, type_neighbor);
							else{
								if(cell_pos>=old_matrix->cn*(old_matrix->rn-1))
									lower_edge( &nr_live_neighbors, cell_pos , old_matrix, type_neighbor);
								else{									
									if(cell_pos%old_matrix->cn==0&&cell_pos!=0) 
										left_edge( &nr_live_neighbors, cell_pos , old_matrix, type_neighbor);
									else{	
										if(cell_pos%old_matrix->cn==(old_matrix->cn -1))
											right_edge( &nr_live_neighbors, cell_pos, old_matrix, type_neighbor);
										else{	
											centre( &nr_live_neighbors, cell_pos, old_matrix, type_neighbor);}
					}	}}}}		}
	}
	return nr_live_neighbors;
}
