#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <allegro.h>
#include <getopt.h>
#include "read_from_file.h"
#include "principles_of_neighborhood.h"
#include "image.h"
#include "cellular_automaton.h"
#include "save_set.h"
//char *usage =
  //"Użycie: %s -p plik z danymi -n ilosc generacji do wytworzenia -c co ile generacji tworzyć obraz -j jaka niezmienna -f format zapisanych obrazów ( BMP, PCX, TGA)\n"
 // "            -k katalog obrazów -s jakie sasiedztwo (obwarzanek czy ograniczona)";


int main(int argc, char *argv[]){
	char *in=NULL;
	char *constans=NULL;

	char *format=NULL;
	char *folder=NULL;	
	char *type_neighbor_name=NULL;
	char *buff="barrel";	
	int type_neighbor=0;
	
	int opt;
	int nr_generations;
	int how_often_image=1;
	int temp=0;
	char *out=NULL;
	FILE *outp=NULL;
	FILE *inp=NULL;
	int i=0;
	char ima_name[30];	
	while ((opt = getopt (argc, argv, "p:n:c:j:f:k:s:o:")) != -1) {
	    switch (opt) {
	    case 'p':
	      in = optarg;
	      break;
	    case 'n':
	      nr_generations = atoi(optarg);
	      break;
	    case 'c':
	      how_often_image = atoi(optarg);
	      break;
	    case 'j':
	      constans = optarg;
	      break;
	    case 'f':
	      format = optarg;
	      break;
	    case 'k':
	      folder = optarg;
	      break;
		case 's':
				type_neighbor_name = optarg;
				break;				
		case 'o':
				out=optarg;
				break;
	}}
		
		if (in!=NULL) inp=fopen(in,"r");
		else {
			if(constans!=NULL) inp=fopen(constans,"r");
			else {
				fprintf (stderr, "%s: can not read file with data: %s\n\n", argv[0], constans);
      exit (EXIT_FAILURE);
    	}
		}
	matrix_t *old_matrix=NULL;
	old_matrix=read_matrix(inp);
	if( old_matrix==NULL) {
		fprintf (stderr, "%s: wrong file with data!: \n\n", argv[0]);
      exit (EXIT_FAILURE);
    }
	matrix_t *new_matrix=NULL;

	new_matrix=make_matrix (old_matrix->rn, old_matrix->cn);
	if(type_neighbor_name!=NULL && strcmp(buff,type_neighbor_name)==0) type_neighbor=1;
	
	BITMAP *pic1=initiate_im(old_matrix);
	if(pic1 ==NULL){
		fprintf (stderr, "%s: can not initiate bitmap\n\n", argv[0]);
      exit (EXIT_FAILURE);
    }
	for(i=0; i<nr_generations;i++){
		new_matrix=save_generation(old_matrix,new_matrix,type_neighbor);
		if((i+1)%how_often_image==0){ 
			temp++; painting(new_matrix,pic1,temp,ima_name,folder,format);
		}
		memcpy (old_matrix->e, new_matrix->e, sizeof(int)*old_matrix->rn*old_matrix->cn);
	}
	if(out==NULL)	outp=fopen("conf.txt","w");
	else 	outp=fopen(out,"w");
	if(outp==NULL){
		fprintf (stderr, "%s: can not open out file\n\n", argv[0]);
      		exit (EXIT_FAILURE);
			}
	
	set_to_file(outp,new_matrix);
	destroy_bitmap(pic1);
	allegro_exit();
	fclose(inp);
	fclose(outp);	
	return 0;
}
