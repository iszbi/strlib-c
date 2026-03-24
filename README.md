# strlib-c
A from-scratch portable implementation of C's string.h header.

## Installation
This implementation only uses C Standard Library (libc). No other external libraries are needed. All you need is a C99 compatible compiler (and if your compiler doesn't support C99, please get a new compiler).

## Usage 
**⚠️ Please do not use this in production code!**
This is just a small learning passion project of mine; please use your compiler's implementation as that has been rigourously tested and optimised. While I've tried my best to eliminate bugs and edge cases, I cannot guarantee full stability.

Every function works the same as the corresponding libc function (or at least intends to), so arguments and return type are all the same. Each function is under the `my_*` namespace prefix, so for example `strcat` becomes `my_strcat`. 



### Building the test harness
I've also included a sample test harness I used to test my implementation. I've only tested it with gcc (MinGW and MSYS2 on Windows), but there shouldn't be any other issues with other compilers.

To build the test harness:
`gcc harness.c my_string.c -o test`
Rename `test` as needed.

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
Pull requests are welcome! However, please remember that this is a passion project that isn't meant to be designed to be used in production code, so please make sure all code is portable. Otherwise, feel free to correct any edge cases or errors in my code.

## Background
### Why did I make this?
**Because yes, compiler implementations will be miles ahead of mine.** This is a bit of a small passion project of mine, and it's given me the opportunity to learn more about memory by working with lots of pointers and raw bytes. It also gives me better insight on how libc works under the hood, and overall I think it's really helped with my low level skills. I've made a GitHub repo for this because I'd like to share how I've gone about implementing the different functions.

`string.h` especially is nice starting point to learning how C works under the hood because it's not too difficult and you're still working directly with memory yourself. I recommend anyone who wants to learn more about C or memory to try write an implementation of `string.h` as well!

### Why shouldn't I use this in production code?
See [Usage](#usage).
