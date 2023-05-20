# C Intro

### Intro and Background

##### computer organization

The ENIAC at U Penn, 1946. World War Two is over. And this is now hitting all the news headlines. <u>First electronic general-purpose computer-</u> multiplies in 2.8 milliseconds. Patch cords. Read the schematic, write the patch cords and then maybe you turn some switches and knobs. Vacuum tubes are breaking all the time. It was remarkable that they were able to do what they did.

Ballistic trajectories figuring out how to angle for this kind of wind, elevation changes... 《Hidden Figures》Who were part of the U Penn group.

EDSAC in Cambridge in 1949, <u>First general stored-purpose computer.</u>  Why couldn't a program itself be data?  And now, that meant that bits can be bits and bits can be a program too. 

<!--absence, restrictions, dig, tout, supposedly, assembly, portable-->

If you're writing in the actual language of the machine, you can't really move it. But if you can write it a level above that-- again, the level of abstraction-- again, abstraction, the most important idea in this class.

It's almost like a car, where you've stripped away all the plastic in this, and all you have is wires. And you're kind of rewiring wires to make your car work and jumpstarting it that way. That's kind of C is.

legacy code, retrain, cut their teeth in C

So Rust is a C-but-safe language. Pointers, memory leakages and shaky code. So it's the same thing that a compiler would do in Java in terms of checking type. C doesn't do that because C is not strongly typed.  So u can really be messing with types, and take a pointer to this, and move it around, and then change the bits -- I mean, it's powerful and crazy what you could do in C. That's why the compiler can't check all of those things. 

concurrently, on a ton of cores on a machine, Go. remarkable performance, lightweight way.

firing at all cylinders. Final disclaimer. apprentice model. Some low level different. not work again.

### Compile v. Interpret

Compile, link and execute.

<!--C compiled into architecture-specific machine code; java converted into machine independent bytecode that may then be compiled by a just-in-time compiler(JIT); Python does runtime bytecode conversion. You'd think of it as being interpreted.-->

<!--in C, gcc does both compile and link which is hidden from you.--> 

We've worked with makefiles, so you only need to actually recompile the things you've changed. That's a big deal. Segment your code into different files. 

<!--What information should be contained in makefiles to make that work. When you have change one little line, you just need to compile this little file and link all together. much faster. why segment code into different files. would link be fast?-->

Runtime performance is unparalleled. We run on raw silicon.

A lot of <u>libraries have been optimized</u> for some hardware. GPU<!--general purpose graphics processing units--><!--take polygons and render them into pixels, in the olden day. now can speed up lots of computation from Python by calling libraries that know how to harness GPU.-->. waiting to be tapped as a resource for you. Also, <u>Spark</u> is a way, very easily, in Python, as a director, as a marionette controller, control lots of other machines. Millions of machines can wake up and do your bidding, driven from Python which is really fun and easy to program in, I'll admit. <u>Write C code and expose it to Python</u>.  Cython.org. 

<!--How people still do a lot of data in python.-->

You can't really have a snippet (just pipe it there) that you want to see what it does, just to see. It's not really a C interpreter. Because you don't have an interpreter to play with things. it's not so good. 

compile files, as the first bullet says, are machine-specific. CPU, libraries, all have to work in the same ecosystem cleanly. Porting your code (recompiling and moving it to another architecture)  . Painful. <!--what is the size of int. type "configure", particular system.-->

You'd only have to compile the particular file changed.  A parallel compiler. `make -j` And then linking together, that's the <u>bottleneck</u>. Amdahl's heartbreaking Law, where you all have to wait.

C Pre-Processor (CPP)

some directive, only commands for the cpp. `foo.c` -> cpp -> `foo.i` -> compiler -> `foo.o` -> Linker -> `a.out`.

`#...`: cpp command. 

`#include "file.h"`: grabs the `file.h` file and puts it in the `foo.i` file.

`#include <stdio.h>`: grabs from the standart place in the library.

`#define PI (3.14159) ` `()` is safe. you never know where it going to be in an expression. <!--sicp写macro的时候会遇到相同的窘境吗-->

`#if/#ifdef/#endif`: conditionally include text

`-save-temps` : tell gcc to store result of preprocessing.

https://gcc.gnu.org/onlinedocs/cpp/

Macro: text replaces everything it sees below

`#define min(X, Y) ((X)<(Y)?(X):(Y))`

`next = min(w, foo(z)); `  # one hello world

`next = ((w)<(foo(z))?(w):(foo(x))); ` # two hello world

<!--innocuous, substitution. When macro does the text replacement? Why only one hello world printed out?-->

### C v. Java and C Syntax

it's just screaming to you. 

`gcc -o hello hello.c` creates machine language code

`javac Hello.java` creates Java virtual machine language bytecode (machine independent code)

`a.out` loads and executes program (machine dependent code). a.out loadss it into memory and then runs the program. Lots of more details on what the loader does. We'll talk about that.

`java Hello` interprets bytecodes

So all the safety belts, all the rubber padded rooms are gone.

So my point is sometimes the C, the kind of old school C is to convert the word into a really tight word like MV, like the Unix commands. Back in the '70s and '80s, that's what they were thinking.

But bitwise, it says work on the actual bits themselves, which is nice. It kind of works in parallel, very powerful.

"ANSI C" -> "C99" or "C9x"

In 1999, a consortium got together and says, we got to upgrade C. ANSI was about 1986. 

They didn't think about the Y2K problem and already tried to have four digits for their. Remember, this is still the very abridged way to naming things. 

To be safe: `gcc -std=c99` to compile

`printf("%ld\n", _STDC_VERSION_);` 

199901, actual date of that release of that version. Actually, the compiler you're working with.

- en.wikipedia.org/wiki/C99

**Highlights**: 

1. declaration, 
2. java-like `//` comments, 
3. variable length array, <!--that third bullet down-->, 
4.  `<inttypes.h>`: explicit integer types, 
5. `<stdbool.h>` for boolean logic def's.

"C11" (C18 fixes bugs...)

`printf("%ld\n", _STDC_VERSION_);`  201112L

`printf("%ld\n", _STDC_VERSION_);`  201710L

- en.wikipedia.org/wiki/C11_(C_standard_revision)

**Highlights**: 

1. Multi-threading support!
2. unicode
3. `gets()` , a huge security hole for so many years, get out
4. Type-generic Macros (dispatch based on types)
5. complex values
6. Static assertions, Exclusive create-and-open,...

`int main(int argc, char *argv[])`

`unix% sort myFile`

`argc`: how many arguments do I have? 2

`argv`: argv[0]: sort ; argv[1]: myFile

QA: **Why you want the name of the program in the program itself?**



Scratch and Snap, which is one indexed.

### C Syntax

What evaluates to FALSE in C?

- 0 (integer) <!--how about unsigned 0 and 0.0-->

- NULL (pointer: more on this later)
- Boolean types provided by C99's studbook.h

Turns out null is actually defined as 0. 

What evaluates to TRUE in C?

- ...everything else...
- Same idea as in Scheme (Only `#f` is false, everything else is true!)

Python has what false is for every type: '', 0, [].... and anything that's not, that is true. <!--python 如何实现这一点的。scheme设计这点和它的语言类型有关吗-->

This  is actually a matter of debate.You want to get a Scheme riled up? Ask them whether the empty list is true or false.

You'd call it "final" and then you give it to them, and then make a change, they call it "final final." it's like long long.

32-bit machine, which means the data kind of is, the whole datapath's meant for 32 bits. Everything is floating around in that way, that's the width of the data path, then probably ints are going to be 32. It's what's called the word size, which is <u>the width of the majority of the data</u> you're flowing with.

C: `int` should be integer type that target processor works with most efficiently.

Only guarantee:

- `sizeof(long long)` >= `sizeof(long)` >=  `sizeof(int)` >=`sizeof(short)` 

- short >= 16 bits, long >= 32 bits

<!--that why we saw with different processors, int in C can be 16, 32 or 64-->

`sizeof([1, 2, 3, 4, 5])`: how many <u>bytes wide</u> this thing is. 20. If it's 32 bits, the sizeof will say 4. 

This is why we encourage you to use `intN_t` and `uintN_t` ! <!--migrate reason. why migrate becomes so difficult and annoy? I guess C codes do depend on the word size. may cause some memory issues when changing.--> 

`const double the_law = 2.99792458e8` <!--compiler help me!-->

Enums: a group of related integer constants. E.g.,

`enum cardsuit {CLUBS,DIAMONDS}`

I recommend you not peek under the hood to find out what those bits are of each one of those. Your code should work without knowing that. You can rearrange the numbers, and code still work. <!--easy change, easy maintain-->

Variables and function MUST be declared before they are used. <!--不会帮你提升-->

```c
typedef uint8_t BYTE;
BYTE b1, b2;

typedef struct {
  int length_in_seconds;
  int year_recorded;
} SONG;

SONG song1; // dot notation in struct, -> in pointer? TODO: I forget.
song1.length_in_seconds = 213;
```

<!--in scheme, how do you define these compound types and make abstract data types? where will you put functions and hide them from client?-->

`break;` statement in `switch`. So that's actually important. People have done this before where they'll just roll through.

`goto` is reserved for kind of expert C programmers who know what they're doing. 

```c
#include <math.h>
int main(void) {
  double pi = 4.0*atan(1.0);
}
```

All those in the same shared namespace.  Welcome to one namespace.

<!--rogue, float point iterations be off by 1. thumbs up on that one.-->

