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

//The following three funs started with '_' are parts of the implement of the fun evaluateOneCell and shouldn't be viewed outside this file.
//Return the color of the cell at the given row/col.
Color *_color(Image *image, int raw_row, int raw_col) {
    Color **p = image->image;
    int cols = image->cols;
    int rows = image->rows;
    //The top of the top is the bottom, the bottom of the bottom is the top.
    int row = (raw_row + rows) % rows;
    //The left of the left is the right, the right of the right is the left.
    int col = (raw_col + cols) % cols;
    int bias = row * cols + col;
    return *(p + bias);
}

//Each number represents the alive number of the digit of given n.
//Actually return the binary of n as if it is decimal
int _alive_ns(uint8_t n) {
    if (n == 0) {
        return 0;
    }
    return (n & 1) + 10 * _alive_ns(n >> 1);
}

//Each digit of n is a state. Each number of alive is the number of alive neighbors.
//Each digit of the return value is the next state of the given state decoded by the rule.
uint8_t _convert(uint8_t n, int alive, uint32_t rule) {
    if (n == 0 && alive == 0) {
        return 0;
    }
    int digit = (rule >> (9 * (n & 1) + (alive % 10))) & 1;
    return digit + 2 * _convert(n >> 1, alive / 10, rule); 
}

//Determines what color the cell at the given row/col should be. This function allocates space for a new Color.
//Note that you will need to read the eight neighbors of the cell in question. The grid "wraps", so we treat the top row as adjacent to the bottom row
//and the left column as adjacent to the right column.
Color *evaluateOneCell(Image *image, int row, int col, uint32_t rule)
{
	//YOUR CODE HERE
    //Assume the rule is a hexadecimal number between 0x00000 and 0x3FFFF.
    Color *my_color = _color(image, row, col); 
    //State: alive(1) or dead(0)
    //The number of alive neighbors
    int neighbors[8][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    int alive[] = {0, 0, 0}; 
    for (int i = 0; i < 8; i += 1) {
        Color *n_c = _color(image, row + neighbors[i][0], col + neighbors[i][1]);
        //We won't add with carry.
        alive[0] += _alive_ns(n_c->R); 
        alive[1] += _alive_ns(n_c->G); 
        alive[2] += _alive_ns(n_c->B);
    }
    //Determines color by rule
    Color *decoded;
    if ((decoded = (Color *) malloc(sizeof(Color))) == NULL) {
        exit(-1);
    }
    //Almost same with the table clarified
    decoded->R = _convert(my_color->R, alive[0], rule);
    decoded->G = _convert(my_color->G, alive[1], rule);
    decoded->B = _convert(my_color->B, alive[2], rule); 
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
    //To distinguish success/failure after call
    errno = 0;
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
