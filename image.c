#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "read_from_file.h"

void im_name(int nr_im, char img_name[], char *folder, char *format){
	strcpy(img_name,folder);
	char temp[10];
	sprintf(temp,"%d",nr_im);
	strcat(img_name,temp);
	strcat(img_name,format);
}

BITMAP *initiate_im(matrix_t *matrix){
	allegro_init();
	set_color_depth( 8 );
	BITMAP * pic1 = NULL;
	pic1 = create_bitmap( 50*matrix->cn, 50*matrix->rn);
	if( !pic1 )
	{
	    set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
	    allegro_message( "nie mogę załadować obrazka 1 !" );
	    allegro_exit();
	    return NULL;
	}
	return pic1;
}

void painting (matrix_t *matrix,BITMAP *pic1, int nr_im, char img_name[], char *folder , char *format){	
	int p=0;
	clear_to_color( pic1, 255);
	for(p=0;p<(matrix->cn*matrix->rn);p++)
		if(matrix->e[p]==1) rectfill(pic1,50*(p%matrix->cn),50*(p/matrix->cn),50*(p%matrix->cn)+50,50*(p/matrix->cn)+50,0);		
	im_name(nr_im,img_name,folder, format);
	save_bitmap(img_name, pic1 , default_palette );
}
