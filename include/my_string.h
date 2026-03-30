// "build your own allocator!!!1!!!"
//                      no.
// 
#ifndef MY_STRING_H
#define MY_STRING_H
#include <malloc.h> 

// use the my_* namespace to make sure it doesn't just call the libc ones
size_t my_strlen(const char *str);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, const char *src);
int my_strcmp(const char *str1, const char *str2);
char *my_strstr(const char *str, const char *substr);
char *my_strchr(const char *str, int chr);
char *my_strdup(const char *str);
size_t my_strspn(const char *str, const char *spn);

#endif // MY_STRING_H
