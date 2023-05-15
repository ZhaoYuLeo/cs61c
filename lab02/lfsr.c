#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    // the Exclusive Or of the bits originally in position 0,2,3 and 5.
    uint16_t bit = ((*reg >> 0) ^ (*reg >> 2) ^ (*reg >> 3) ^ (*reg >> 5)) & 1u;
    // shift 1 bit the the right and set the leftmost bit to the Exclusive Or
    *reg = (*reg >> 1) | (bit << 15);
}

