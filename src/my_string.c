#include "my_string.h"

size_t my_strlen(const char *str) {
    size_t i = 0;
    while(*(str + (++i)));
    return i;
}

// nyaaaa~ :3
char *my_strcat(char *dest, const char *src) {
    size_t i = my_strlen(dest);
    
    // intentional assignment
    while(*(dest + (i++)) = *src++);

    return dest;
}

char *my_strcpy(char *dest, const char *src) {
    size_t i = 0;
    while(*(dest + (i++)) = *src++);

    return dest;
}

int my_strcmp(const char *str1, const char *str2) {
    while(*str1++ == *str2++ && str1 != '\0' && str2 != '\0');
    return (*str1) - (*str2);
}

char *my_strchr(const char *str, int chr) {
    while(*str++ != chr) {
        if(*str == '\0') return NULL;
    }
    return str - 1;
}

char *my_strstr(const char *str, const char *substr) {
    /*
     walk through bytes
     if str at current byte == substr first character
        start matching
     */

    int is_matching = 0;
    size_t subindex = 0;
    while(*str != '\0') {
        if(*str == substr[0]) {
            is_matching = 1;
        }

        if(is_matching) {
            if(substr[subindex] == '\0') {
                return str - subindex;
            }

            if(*str != substr[subindex++]) {
                is_matching = 0;
                subindex = 0;
            }
        }

        str++;
    }

    return NULL;
}
