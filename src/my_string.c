#include "my_string.h"

size_t my_strlen(const char *str) {
    const char *origin = str;
    while(*str++);
    return str - origin - 1;
}

// nyaaaa~ :3
char *my_strcat(char *dest, const char *src) {
    size_t i = my_strlen(dest);
    
    // intentional assignment
    while((*(dest + (i++)) = *src++));

    return dest;
}

char *my_strcpy(char *dest, const char *src) {
    size_t i = 0;
    while((*(dest + i++) = *src++));

    return dest;
}

int my_strcmp(const char *str1, const char *str2) {
    while(*str1 == *str2 && *str1) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

char *my_strchr(const char *str, int chr) {
    while(*str != chr) {
        if(*str == '\0') {
            return NULL;
        }

        str++;
    }
    return (char *)str; // cast away const
}

char *my_strstr(const char *str, const char *substr) {
    if(my_strcmp(str, substr) == 0) {
        return (char *)str;
    }

    if(*substr == '\0') {
        return (char *)str;
    }
    
    int is_matching = 0;
    size_t subindex = 0;
    while(*str) {
        if(*str == substr[0]) {
            is_matching = 1;
        }

        if(is_matching) {
            if(substr[subindex] == '\0') {
                return (char *)(str - subindex); // cast away const
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

char *my_strdup(const char *src) {
    char *newbuf = malloc(my_strlen(src) + 1);
    if(newbuf == NULL) return NULL;

    my_strcpy(newbuf, src);
    return newbuf;
}

size_t my_strspn(const char *str, const char *spn) {
    const char *origin = str;
    loop_start:
    while(*str) {
        for(size_t i = 0; i <= my_strlen(spn); i++) {
            if(*str == spn[i]) {
                str++;
                goto loop_start;
            }
        }

        break;
    }
    
    return str - origin; // cast away const
}

