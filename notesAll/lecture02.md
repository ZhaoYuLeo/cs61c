## Number Representation: Intro, Bits can be anything



### Data input: Analog -> Digital

For example, for music, for CDs, that's 44,100 times a second we're asking it what its height is.

Fractional number<!--无理数 = 整数 + (0， 1)-->

And we need to then quantized that, which means divide it up in its amplitude. And you ask it, what is its amplitude on some yardstick? We divide it up into a 16-bit number. So that's 2 to the 16 possible tick marks on a yardstick, or 65,536 different tick marks. And we say, where are you? And some of these might not exactly align, so we snap to the closest tick mark to figure what that is. When we're all done, we have a set of samples, and then we can work with that.

POV-Ray is an animation software, a rendering software, really amazing, free, open source.

The big idea in this first lecture, this first snippet of the module, is that bits can represent anything.

26 letters -> 5 bits; 7 bits(in 8) ("ASCII"); a consortium came around called Unicode  with the idea. They have an 8-bit, a 16-bit, and a 32-bit version of Unicode.

Grumpy. Anything you can itemize, you can digitize. **N bits is 2 to the n things.** I've got some number of things, how many bits do I need? I take the log base 2 of that, and take the ceiling of that, and that's number of bits I need.

### Binary Decimal Hex

because they have four fingers -- see, the whole Simpsons thing.

Subscript. So this is like a coefficient times this term. 

I've got a lot of -- when you're in prison -- not that I would know about being in prison -- but if you're in prison, you might have lots of dash marks, how many days you've been there. Every day, you scratch something into the wall. Well, I might have that number of dash marks. And that's actually base 1. You've just got dash marks. It's called tally counting, I think.

|  8   |  4   |  2   |  1   |
| :--: | :--: | :--: | :--: |
|  1   |  1   |  0   |  1   |

And basically, that's-- it's the column heading times the value below it.

If I got boxes from Amazon and the box was labeled one egg in this one-- here's an empty box. I guess it's empty box. This is the 2 box. This's full of eggs. It's 4, and this is full of eggs. It's 8. How many total eggs do I have? So I think about that.  Sometimes the boxes come empty or full, but they're either only empty or full in here, in this particular case.

|  0xA   |  0xB   |  0xC   |  0xD   |  0xE   |  0xF   |
| :----: | :----: | :----: | :----: | :----: | :----: |
|   10   |   11   |   12   |   13   |   14   |   15   |
| 0b1010 | 0b1011 | 0b1100 | 0b1101 | 0b1110 | 0b1111 |

Leak into the letters.

I made 0xA5 in hexadecimal--written in hexadecimal--dollars today.

Alien says, "There are 10 rocks."

Astronaout says, "Oh, you must be using base 4. See, I use base 10."

and Alien says, "No. I use base 10. What is base 4?"

Because in every base, there's a 10. And in fact, every base, 10 is their base.

| 2^3 = 8 | 2^2 = 4 | 2^1 = 2 | 2^0 = 1 |
| :-----: | :-----: | :-----: | :-----: |
|    1    |    1    |    0    |    1    |

I've got these boxes to ship back to Amazon, all labeled in those bases. I've got a box labeled 1, a box labeled 2, a box labeled 4, a box labeled 8. ok. I want to reduce my postage. Amazon will only take a full box back. Remember, it's either full or empty. I want to take a full box back. The algorithm says this. Let's start with 16, just to go rogue for a second. I say is the column number less than or equal to the number I have left, the number of eggs I have left to -- boy, those chickens were productive. So I've got to ship 13 eggs back to Amazon. So can I fit 13 in a box of 16 and fill it up? Then I ask, how many of those boxes can I fill? Well, here, only one. In fact, in binary, it's only going to either be 1 or 0. But we'll see in hex, it's actually more. Cross it off. I could just short-circuit it and go right to the end.

| 16^3 = 4096 | 16^2 = 256 | 16^1 = 16 | 16^0 = 1 |
| :---------: | :--------: | :-------: | :------: |
|      0      |     0      |     A     |    5     |

How many 16 boxes can I fill with my 165 eggs sitting all on my floor? 10 of them. This is the same algorithm for every base.



How do I convert binary to hex? You have to left-pad it, which means add 0s-- you can always add 0s to the left-- you have to left-pad it so that the length of that binary digit always is a multiple of 4. If you do this, it'll work out trivially. 0b11110 -> 0x1E

| D    | H    | B    |
| ---- | ---- | ---- |
| 00   | 0    | 0000 |
| 01   | 1    | 0001 |
| 02   | 2    | 0010 |
| 03   | 3    | 0011 |
| 04   | 4    | 0100 |
| 05   | 5    | 0101 |
| 06   | 6    | 0110 |
| 07   | 7    | 0111 |
| 08   | 8    | 1000 |
| 09   | 9    | 1001 |
| 10   | A    | 1010 |
| 11   | B    | 1011 |
| 12   | C    | 1100 |
| 13   | D    | 1101 |
| 14   | E    | 1110 |
| 15   | F    | 1111 |

Memorize this table. Save you in time, and it will make you feek like, ooh, stand a little taller. 

Four binary digits is 16 things. Well, 16 things is this number of hexadecimal options, 0 throught F. One hexadecimal digit is 16 things.

Hex to binary-- piece of cake. Literally look them up, concatenate them all together, and then drop the leading 0s. 0x1E = 0b11110.

We made the triangle.

I'll start with the second bullet point here. 8 bits is called a byte. Just historically, it's called a byte.

4-bits called a nibble. a byte and then a nibble, see that? I've tried to advocate that 2 bits should be, like, a taste. But nobody's ever bought on to that. 2 Hex Digits = 256 things. Or n hex digits is 16 to the n is another way. 

computer displays. 8 digits, 8 bits -- to represent a single color, partly because the hunman eye can't see more than that. By the way, they now have high-end TVs that have more of those bits, which is interesting because they can do dynamic range. It's a long conversation there.

Early TVs used 8 bits for each of the red, green, and blue channels. They concatenated them together to make a 24-bit color. So 0-255 red, 0-255 green, 0-255 blue.

#D0367F = #red+gree+blue #FFFFFF = white

02322 = 1234; octal

### Number Representations

numbers are a theoretical concept. The value pi-- theoretical concept. The numerals are the representations of that. Digits are always digits of numerals. You don't have digits of numbers. If you ever say that's a digit of a number, that's wrong. It's a digit of a numeral. Numerals are the written representation of that theoretical concept of a number.

rightmost digits. mostly the ashes in the lower end up-- because it's an infinite, so it'd be lots of 0's leading. **(unsigned numbers)**

overflow

00000 00001 00010 ... 11110 11111

If I add one more to that, It's going to wrap around to 0. 00000 -1=111111. also overflow, sometime called negative overflow.

C's unsigned int # ambiguous how many bits is an unsigned int.

 C18's uintN_t # N is going to be a number-- 8, 16, 32-- which tells you actually the width of it. started in C99, which they've introduced in subsequent versions of C. Now up to C18. It's called inttypes.h. 

There was a rich king, kingdom, and he had three wise people-- three wise thinkers. And he said to the wise thinkers, I want you to teach me all there is to know about economics. And they went away-- scurried away and they came back a year later. Five tomes they had written. This is all we understand of economics. We've searched the world. This is the world's knowledge of economics is. The king says, no time, no time. Make it shorter. Go back and make it shorter. They came back. We created this single book. No time-- sends them away. Another year, he comes back. We have this Pulp Fiction novel to explain economics. No,no, no time. They came back next year. We created this comic book, graphic novel-- 10 pages. Nope, no time. We created a single sheet of paper, an executive summary. No time, no time. Comes back. So they get grayer and older and the beards and the hair. They come back. He says, sire, king, we have come up with the theory of economics in four words. I don't know how it became English... He says, yes, go ahead, I have time for that. Ain't no free lunch

What it means is you can't get something for nothing. 

If you want to be able to now represent negative numbers, you've got to give something. You've got to lose some numbers that you used to represent. Now you won't be able to represent them anymore.

The leftmost bit is going to be my sign. **(Sign and Magnitude)**

​                            00000 00001 ... 01111

11111 ... 10001 10000

binary odometer, spot, with your finger, four.

I'm going positive, positive, positive and then negative. So think about that as one of the problems with sign magnitude. as this went a weird direction.

The second is to build circuitry around this is actually hard because you've got to deal with the fact that it's positive or negative. and what if one's positive and one's negative?

You get two zeros. That's annoying. Does that mean for programming is it equal to one of those? Do you have to check for two patterns of a 0 now?

So actually, we don't usually use sign magnitude except for in rare cases, often in signal processing. 

Let's try it again.

How about if we just flip the bits? Let's just try-- it's another attempt. These are all people sitting with a whiteboard, thinking, let's try flipping all the bits when it's negative. 7 is 00111 and negative 7 is 11000. **(One‘s Complement)**

​                            00000 00001 ... 01111

10000 ... 11110 11111

But it's not sign magnitude.  And then, if you notice, all 1's is at the far side on the left. So actually, as the odometer goes up, after 0001111,  and it wraps to the next number-- It's kind of back in the day if you have a 0 and all 9s, it wraps to 1 and 0's in decimal-- the odometer is now fixed, but there's still overlap. Could we do mostly this but just take this bottom--10000...11110 11111 and just shift it left? Then you wouldn't have the overlap.

### Two's Complement & Bias Encoding

two's complement:

The problem is the negative numbers overlap with the positive numbers. We want to shift the bottom over 1. We don't want 11111 to be 0. We want 11111 to be negative 1. And in fact, I want you to lock that in. All 1's is always -1 in this two complement number.

$d_{31} \times -(2^{31}) + d_{30} \times 2^{30} + ... + d_2 \times 2^2 + d_1 \times 2^1 + d_0 \times 2^0$

1101, -3,  flip  the bits and add 1

Example: -3 to +3 to -3 (again, in a nibble):

x    :  1101

x'   :  0010

+1 :   0011

( )' :   1100

+1 :  1101

<!--optical illusion, a vase, a face, flops between a vase and a face. a pro tip-->

I think about negative numbers and how to do them fast is I actually see, when I say, okay, this leading 1 now, I immediately see this and I flip. I treat every 1 as a 0 and a 0 as 1, which means I basically do $x'$ in my head.  And then I just quickly add 1, and I say, it must have been negative 3.



So I'm able to, really fast, think about how to do that fast for yourself.

![](/Users/a/Desktop/截屏2023-05-13 20.52.20.png)



$d_{31} \times -(2^{31}) $ , this cool top-level term. It's because you grab that negative guy, that smallest negative number, and pulled it over by exactly 1. In one's complement, it was really minus 15, and now it's minus 16, which is why it works. 

biased encoding:

<!--wiggling like this, -->

All 0's being the smallest value. Here's an analogy for you. I'm recording some electrical signal. And it's wavering from 0 volts, which, let's say it's a DC voltage, to 31 volts. And I'm going between that. And I want to have 31 representations in there. Well, let's say it's wiggling like this. Graph, some bias, to add an offset, what we call a DC bias. This bias brings things down so it's kind of balanced across 0. 

![截屏2023-05-13 21.09.15](/Users/a/Desktop/截屏2023-05-13 21.09.15.png)

And what distinguishes it from that, I could either add -16 to it so they're almost exactly the same as the two's complement. That's not what we typically do.

Bias for N bits is $-(2^{N-1}-1)$, unsigned value. grab it and shift it back by -15.

0 is actually equivalent to bias.

Summary:

We use unsigned, two's complement, and bias. 

Unsigned (C18's uintN_t)

Two's complement (C99's intN_t)

Bias: you have no way to do this. Store the bias, I'll ship you an unsigned. And then I'll encode it. (-15 to 16, ps: bias is -15, 0 to 31).  You apply the bias and decode this.

Design decisions to make hardware simple. And one of the reasons we threw out sign magnitude and one's complement.

<!--foreshadowing probably 10 weeks ahead.-->

It's the same hardware to do mathematics on unsigned and two's complement numbers. (different things overflow. A little different for the overflow calculation.)



