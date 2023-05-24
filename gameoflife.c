/************************************************************************
**
** NAME:        gameoflife.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-23
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>
#include "imageloader.h"

//Return the state of the cell at the given row/col.
//This is one part of the implement of the fun evaluateOneCell. Shouldn't be viewed outside this file.
int _state(Image *image, int raw_row, int raw_col) {
    Color **p = image->image;
    int cols = image->cols;
    int rows = image->rows;
    //The top of the top is the bottom, the bottom of the bottom is the top.
    int row = (raw_row + rows) % rows;
    //The left of the left is the right, the right of the right is the left.
    int col = (raw_col + cols) % cols;
    int bias = row * cols + col;
    return (*(p + bias))->B & 1;
}

//Determines what color the cell at the given row/col should be. This function allocates space for a new Color.
//Note that you will need to read the eight neighbors of the cell in question. The grid "wraps", so we treat the top row as adjacent to the bottom row
//and the left column as adjacent to the right column.
Color *evaluateOneCell(Image *image, int row, int col, uint32_t rule)
{
	//YOUR CODE HERE
    //Assume the rule is a hexadecimal number between 0x00000 and 0x3FFFF.
    //State: alive(1) or dead(0)
    int my_state = _state(image, row, col); 
    //The number of alive neighbors
    int alive_n = _state(image, row - 1, col) + _state(image, row + 1, col)
                  + _state(image, row, col - 1) + _state(image, row, col + 1)
                  + _state(image, row - 1, col - 1) + _state(image, row + 1, col + 1) 
                  + _state(image, row - 1, col + 1) + _state(image, row + 1, col - 1);
    //Determines color by rule
    Color *decoded;
    if ((decoded = (Color *) malloc(sizeof(Color))) == NULL) {
        exit(-1);
    }
    decoded->R = decoded->G = decoded->B = 255 * (rule >> (9 * my_state + alive_n) & 1);
    return decoded;
}

//The main body of Life; given an image and a rule, computes one iteration of the Game of Life.
//You should be able to copy most of this from steganography.c
Image *life(Image *image, uint32_t rule)
{
	//YOUR CODE HERE
    //Assume the rule is a hexadecimal number between 0x00000 and 0x3FFFF.
    //If I can pass function as argument, maybe I can merge them into one.
    Image *extracted;
    if ((extracted = (Image *) malloc(sizeof(Image)))== NULL) {
        exit(-1);
    }
    uint32_t rows = extracted->rows = image->rows;
    uint32_t cols = extracted->cols = image->cols;
    if ((extracted->image = (Color **) calloc(rows * cols, sizeof(Color *))) == NULL) {
       exit(-1);
    }
    Color **p = extracted->image;
    for (int i = 0; i < rows; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            *p = evaluateOneCell(image, i, j, rule);
            p += 1;
        }
    }
    return extracted;
}

/*
Loads a .ppm from a file, computes the next iteration of the game of life, then prints to stdout the new image.

argc stores the number of arguments.
argv stores a list of arguments. Here is the expected input:
argv[0] will store the name of the program (this happens automatically).
argv[1] should contain a filename, containing a .ppm.
argv[2] should contain a hexadecimal number (such as 0x1808). Note that this will be a string.
You may find the function strtol useful for this conversion.
If the input is not correct, a malloc fails, or any other error occurs, you should exit with code -1.
Otherwise, you should return from main with code 0.
Make sure to free all memory before returning!

You may find it useful to copy the code from steganography.c, to start.
*/
int main(int argc, char **argv)
{
	//YOUR CODE HERE
    char *error_msg = "\tusage: ./gameOfLife filename rule\n\tfilename is an ASCII PPM file (type P3) with maximum value 255.\n\trule is a hex number beginning with 0x; Life is 0x1808.\n";
    //Wrong number of arguments
    if (argc != 3) {
        printf("%s", error_msg);
        exit(-1);
    }
    int base = 16;
    char *endptr, *str = argv[2];
    errno = 0; /* To distinguish success/failure after call */
    uint32_t rule = strtol(str, &endptr, base);
    //Error occurred(overflow) or nothing converted. 
    if (errno != 0 || endptr == str) { 
        printf("%s", error_msg);
        exit(-1);
    }
    Image *image = readData(argv[1]);
    Image *next = life(image, rule);
    writeData(next);
    free(image);
    free(next);
    return 0;
}
