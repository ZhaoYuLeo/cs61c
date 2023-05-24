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
#include "imageloader.h"


int _state(Color **p, int bias) {
    return (*(p + bias))->B & 1;
}

int _adjacentState(Image *image, int raw_row, int raw_col) {
    Color **p = image->image;
    int cols = image->cols;
    int rows = image->rows;
    int row = (raw_row < 0) ? rows - 1 : ((raw_row > rows - 1) ? 0 : raw_row);
    int col = (raw_col < 0) ? cols - 1 : ((raw_col > cols - 1) ? 0 : raw_col);
    int state = _state(p, row * cols + col);
    return state; 
}

//Determines what color the cell at the given row/col should be. This function allocates space for a new Color.
//Note that you will need to read the eight neighbors of the cell in question. The grid "wraps", so we treat the top row as adjacent to the bottom row
//and the left column as adjacent to the right column.
Color *evaluateOneCell(Image *image, int row, int col, uint32_t rule)
{
	//YOUR CODE HERE
    //Assume the rule is a hexadecimal number between 0x00000 and 0x3FFFF.
    Color **p = image->image;
    int mine = row * image->cols + col;
    //State: alive(1) or dead(0)
    int my_state = _state(p, mine); 
    //The number of alive neighbors
    int alive_n = _adjacentState(image, row - 1, col) + _adjacentState(image, row + 1, col)
                  + _adjacentState(image, row, col - 1) + _adjacentState(image, row, col + 1)
                  + _adjacentState(image, row - 1, col - 1) + _adjacentState(image, row + 1, col + 1) 
                  + _adjacentState(image, row - 1, col + 1) + _adjacentState(image, row + 1, col - 1);
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
    return image;
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
    Image *image = readData(argv[1]);
    writeData(image);
    printf("\nThe next generation of the file is: \n");
    for (int i = 0; i < image->rows; i += 1) {
        for (int j = 0; j < image->cols - 1; j += 1) {
            Color *decoded = evaluateOneCell(image, i, j, 0x1808);
            printf("%3hhu %3hhu %3hhu   ", decoded->R, decoded->G, decoded->B);
            free(decoded);
        }
        Color *decoded = evaluateOneCell(image, i, image->cols - 1, 0x1808);
        printf("%3hhu %3hhu %3hhu\n", decoded->R, decoded->G, decoded->B);
        free(decoded);
    }
}
