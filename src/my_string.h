// "build your own allocator!!!1!!!"
//                      no.
// 
#ifndef MY_STRING_H
#define MY_STRING_H
#include <malloc.h> 

// use the my_* namespace to make sure it doesn't just call the libc ones
size_t my_strlen(const char*);
char *my_strcat(char*, const char*);
char *my_strcpy(char*, const char*);
int my_strcmp(const char*, const char*);
char *my_strstr(const char*, const char*);
char *my_strchr(const char *, int)

#endif // MY_STRING_H
