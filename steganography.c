/************************************************************************
**
** NAME:        steganography.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**				Justin Yokota - Starter Code
**				YOUR NAME HERE
**
** DATE:        2020-08-23
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "imageloader.h"

//Determines what color the cell at the given row/col should be. This should not affect Image, and should allocate space for a new Color.
Color *evaluateOnePixel(Image *image, int row, int col)
{
	//YOUR CODE HERE
    Color *origin = image->image[image->cols * row + col]; //assume start at 0
    Color *decoded = (Color *) malloc(sizeof(Color));
    decoded->R = decoded->G = decoded->B = 255 * (origin->B & 1);
    return decoded;
}

//Given an image, creates a new image extracting the LSB of the B channel.
Image *steganography(Image *image)
{
	//YOUR CODE HERE
    Image *extracted = (Image *) malloc(sizeof(Image));
    uint32_t rows = extracted->rows = image->rows;
    uint32_t cols = extracted->cols = image->cols;
    Color **p = extracted->image = (Color **) calloc(rows * cols, sizeof(Color *));
    for (int i = 0; i < rows; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            *p = evaluateOnePixel(image, i, j);
            p += 1;
        }
    }
    return extracted;
}

/*
Loads a file of ppm P3 format from a file, and prints to stdout (e.g. with printf) a new image, 
where each pixel is black if the LSB of the B channel is 0, 
and white if the LSB of the B channel is 1.

argc stores the number of arguments.
argv stores a list of arguments. Here is the expected input:
argv[0] will store the name of the program (this happens automatically).
argv[1] should contain a filename, containing a file of ppm P3 format (not necessarily with .ppm file extension).
If the input is not correct, a malloc fails, or any other error occurs, you should exit with code -1.
Otherwise, you should return from main with code 0.
Make sure to free all memory before returning!
*/
int main(int argc, char **argv)
{
	//YOUR CODE HERE
    /*
    //Test evaluateOnePixel() function with `steganography <ppm_file>`
    Image *image = readData(argv[1]);
    printf("Loading image from %s...\n", argv[1]);
    writeData(image);
    printf("\nDecoding the image...\n");
    for (int i = 0; i < image->rows; i += 1) {
        for (int j = 0; j < image->cols - 1; j += 1) {
            Color *decoded = evaluateOnePixel(image, i, j);
            printf("%3hhu %3hhu %3hhu   ", decoded->R, decoded->G, decoded->B);
            free(decoded);
        }
        Color *decoded = evaluateOnePixel(image, i, image->cols - 1);
        printf("%3hhu %3hhu %3hhu\n", decoded->R, decoded->G, decoded->B);
        free(decoded);
    }
    freeImage(image);
    */

    //Test steganography() function with `steganography <ppm_file>`
    Image *image = readData(argv[1]);
    printf("Loading image from %s...\n", argv[1]);
    writeData(image);
    printf("\nDecoding the image...\n");
    Image *decoded = steganography(image);
    writeData(decoded);
    freeImage(image);
    freeImage(decoded);
    return 0;
}
