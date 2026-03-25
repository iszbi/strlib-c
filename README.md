# strlib-c
A from-scratch portable implementation of C's string.h header.

## Installation
This implementation only uses C Standard Library (libc). No other external libraries are needed. All you need is a C99 compatible compiler (and if your compiler doesn't support C99, please get a new compiler).

## Usage 
**⚠️ Please do not use this in production code!**
This is just a small learning passion project of mine; please use your compiler's implementation as that has been rigourously tested and optimised. While I've tried my best to eliminate bugs and edge cases, I cannot guarantee full stability.

Every function works the same as the corresponding libc function (or at least intends to), so arguments and return type are all the same. Each function is under the `my_*` namespace prefix, so for example `strcat` becomes `my_strcat`. 

To use the functions, include it in your source file:
`#include "my_string.h"`

When compiling, pass the `include` directory as an include directory and `src/my_string.c` as a source file. Check your compiler documentation on how to do this. For example, using GCC that would be `gcc -o my_program -Iinclude my_source.c src/my_string.c`. Adjust `include` and `src/my_string.c` as needed. 

### Building the test harness
I've also included a sample test harness I used to test my implementation.

#### Linux users
Navigate to the root of the repo (where `Makefile` is) and run `make`, and optionally run `make clean` to clean up intermediate files. The executable will be put in the `bin` directory. By default, the makefile will use GCC. You can change `$(CC)` to your chosen compiler and adjust the flags.

#### macOS users
You will need to install GNU Make. **The Xcode `make` will not work as it is BSD Make.**
Install [Homebrew](https://brew.sh/) if you don't have it, and install GNU Make like so:
`brew install make`

Then follow the [Linux users](#linux-users) instructions, substituting `gmake` for `make`.
Optionally, if you would like to link `make` to GNU Make, make sure Homebrew's bin directory takes priority in your PATH.

#### Windows users
If you have MSYS2, you can follow the steps listed for [Linux systems](#linux-users).

Otherwise, you will have to compile manually with your chosen compiler. For example, with MSVC would be:
`cl /Fe:bin\harness /Wall /Iinclude src\harness.c src\my_string.c`


## Functions implemented
### String manipulation
| Function   | Implemented? |
| ---------- | ------------ |
| strcpy     | Yes ✅      |
| strncpy    | No ❌       |
| strcat     | Yes ✅      |
| strncat    | No ❌       |
| strxfrm    | No ❌       |
| strdup     | No ❌       |
| strndup    | No ❌       |

### String examination
| Function   | Implemented? |
| ---------- | ------------ |
| strlen     | Yes ✅      |
| strcmp     | Yes ✅      |
| strncmp    | No ❌       |
| strcoll    | No ❌       |
| strchr     | Yes ✅      |
| strrchr    | No ❌       |
| strspn     | No ❌       |
| strcspn    | No ❌       |
| strpbrk    | No ❌       |
| strstr     | Yes ✅      |
| strtok     | No ❌       |

### Character array manipulation
| Function   | Implemented? |
| ---------- | ------------ |
| memchr     | No ❌        |
| memcmp     | No ❌        |
| memset     | No ❌        |
| memcpy     | No ❌        |
| memmove    | No ❌        |
| memccpy    | No ❌        |

## Contributing
Pull requests are welcome! However, please remember that this is a learning project that isn't meant to be the most optimised or fastest implementation possible, so please make sure all code is portable. Otherwise, feel free to correct any edge cases or errors in my code.

## Background
### Why did I make this?
**Because yes, compiler implementations will be miles ahead of mine.** This is a bit of a small passion project of mine, and it's given me the opportunity to learn more about memory by working with lots of pointers and raw bytes. It also gives me better insight on how libc works under the hood, and overall I think it's really helped with my low level skills. I've made a GitHub repo for this because I'd like to share how I've gone about implementing the different functions.

`string.h` especially is nice starting point to learning how C works under the hood because it's not too difficult and you're still working directly with memory yourself. I recommend anyone who wants to learn more about C or memory to try write an implementation of `string.h` as well!

### Why shouldn't I use this in production code?
See [Usage](#usage).
