#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n) {
    // YOUR CODE HERE
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns 
    // 0 or 1)
    return (x >> n) & 01;
}

// Set the nth bits to v, others to 1
unsigned mask_nth(unsigned n,
                  unsigned v) {
    //11100 ^ 00111 = 11011; ~(~0 << (n + 1))
    //11000 ^ 00111 = 11111
    return ((~v << n) ^ ~(~0 << (n + 1)));
}

// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {
    // YOUR CODE HERE
    *x = ((*x) | ~mask_nth(n, 0)) & mask_nth(n, v); 
}

// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) {
    // YOUR CODE HERE
    unsigned nth = get_bit(*x, n);
    set_bit(x, n, nth ^ 01);
}

