#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <stdlib.h>
#include <string.h>
#include "read_from_file.h"
#include <allegro.h>

void im_name(int nr_im, char ima_name[], char *folder, char *format);
BITMAP *initiate_im(matrix_t *matrix);
void painting (matrix_t *matrix,BITMAP *pic1, int nr_im, char im_name[], char *folder , char *format);

#endif


