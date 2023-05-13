# Number Representation

### 1 Pre-Check

1.1 Depending on the context, the same sets of bits may represent different things.

True. Same sets of bits may represent different things. FFFFFF can represent unsign number, sign number or color depending on the interpretation.

1.2 It is possible to get an overflow error in Two’s Complement when adding numbers of opposite signs.

False. Overflow occurs when the result is out the range of [-(2^(n-1)), 2^(n-1) - 1]. Adding numbers of opposite signs may not cause this.

1.3 If you interpret a N bit Two’s complement number as an unsigned number, negative numbers would be smaller than positive numbers.

False. Negative numbers is larger.

1.4 If you interpret an N bit Bias notation number as an unsigned number (assume there are negative numbers for the given bias), negative numbers would be smaller than positive numbers.

True. Negative numbers would be smaller since the bias

### 2 Unsigned Integers

2.1 Let’s try this by hand. Recall that our preferred tool for writing large numbers is
the IEC prefixing system:
Ki(Kibi) = 2^10  Gi(Gibi) = 2^30  Pi(Pebi) = 2^50  Zi(Zebi) = 2^70
Mi(Mebi) = 2^20  Ti(Tebi) = 2^40  Ei(Exbi) = 2^60  Yi(Yobi) = 2^80

(a) Convert the following numbers from their initial radix into the other two
common radices: (binary, decimal, and hex)
  1. 0b10010011 = 147  = 0x93
  2. 63 = 0b0011 1111 = 0x3F
  3. 0b00100100 = 36 = 0x24
  4. 0 = 0b0 = 0x0
  5. 39 = 0b0010 0111 = 0x27
  6. 437 = 0b0001 1011 0101 = 0x1B5
  7. 0x0123 = 0b0000 0001 0010 0011 = 291

(b) Convert the following numbers from hex to binary:
  1. 0xD3AD = 0b1101 0011 1010 1101 = 54189
  2. 0xB33F = 0b1011 0011 0011 1111 = 45887
  3. 0x7EC4 = 0b0111 1110 1100 0100 = 32452

(c) Write the following numbers using IEC prefixes:
  2^16 = 64 Ki 
  2^27 = 128 Mi
  2^43 = 8 Ti
  2^36 = 64 Gi
  2^34 = 16 Gi
  2^61 = 2 Ei
  2^47 = 128 Ti
  2^59 = 512 Pi


(d) Write the following numbers as powers of 2:
  2 Ki = 2^11
  512 Ki = 2^19
  16 Mi = 2^24
  256 Pi = 2^58
  64 Gi = 2^36
  128 Ei = 2^67

### 3 Signed Integers

3.1 For questions (a) through (c), assume an <u>8-bit</u> integer and answer each one for the case of an unsigned number, biased number with a bias of -127, and two’s complement number. Indicate if it cannot be answered with a specific representation.

(a) What is the largest integer? What is the result of adding one to that number?

1. Unsigned? 255, 0
2. Biased? 128, -127
3. Two's Complement? 127, -128

(b) How would you represent the numbers 0, 1, and -1?

1. Unsigned? 0b0000 0000, 0b0000 0001, can't represent -1
2. Biased? 0b0111 1111, 0b1000 0000, 0b 0111 1110
3. Two's Complement? 0b0000 0000, 0b0000 0001, 0b1111 1111

(c) How would you represent 17 and -17?

1. Unsigned? 0b0001 0001, can't represent -17
2. Biased? 0b1001 0000, 0b0110 1110
3. Two's Complement? 0b0001 0001, 0b1110 1111

(d) What is the largest integer that can be represented by any encoding scheme that only uses 8 bits?

(e) Prove that the two’s complement inversion trick is valid (i.e. that x and x + 1 sum to 0).

(f) Explain where each of the three radices shines and why it is preferred over other bases in a given context.

### 4 Arithmetic and Counting
