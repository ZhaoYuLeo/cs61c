/************************************************************************
**
** NAME:        imageloader.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**              Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-15
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "imageloader.h"


//Opens a .ppm P3 image file, and constructs an Image object. 
//You may find the function fscanf useful.
//Make sure that you close the file with fclose before returning.
Image *readData(char *filename) 
{
    //Open the file with the given name.
    FILE *image_file = fopen(filename, "r");
    if (image_file == NULL) {
        printf("Error occurred while opening file %s.\n", filename);
        exit(1);
    }

    //Read basic info and do simple verification.
    char format[3]; //two characters with one terminating null.
    uint32_t cols_num, rows_num;
    int scale;
    fscanf(image_file, "%s" "%" SCNu32 "%" SCNu32 "%d", format, &cols_num, &rows_num, &scale);
    if (strcmp(format, "P3") != 0 || scale != 255) {
        printf("Not support this format %s with scale of %d currently.\n", format, scale);
        exit(1);
    }
    
    //New an Image object.
    Image *img = (Image *) malloc(sizeof(Image));
    img->rows = rows_num;
    img->cols = cols_num;
    int size = cols_num * rows_num;
    img->image = (Color **) calloc(size, sizeof(Color *));
    
    //Read and write pixels into the image object.
    for (int i = 0; i < size; i += 1) {
        Color *pixel = (Color *) malloc(sizeof(Color));
        //If any error occurred in this step, would the img be free?
        fscanf(image_file, "%" SCNu8 "%" SCNu8 "%" SCNu8, &(pixel->R), &(pixel->G), &(pixel->B));
        (img->image)[i] = pixel;
    }
    
    //Close the file and return the image object.
    fclose(image_file);
    return img;
}

//Given an image, prints to stdout (e.g. with printf) a .ppm P3 file with the image's data.
void writeData(Image *image)
{
    printf("P3\n%d %d\n255\n", image->cols, image->rows);
    uint32_t cols = image->cols;
    for (int i = 0; i < (image->rows); i += 1) {
        for (int j = 0; j < cols - 1; j += 1) {
            Color *pixel = (image->image)[cols * i + j];
            printf("%3d %3d %3d   ", pixel->R, pixel->G, pixel->B);
        }
        Color *pixel = (image->image)[cols * (i + 1) - 1];
        printf("%3d %3d %3d\n", pixel->R, pixel->G, pixel->B); 
    } 
}

//Frees an image
void freeImage(Image *image)
{
	//YOUR CODE HERE
    int size = image->cols * image->rows;
    for (int i = 0; i < size; i += 1) {
        free(*(image->image + i));
    }
    free(image->image);
    free(image);
}
