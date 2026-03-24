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
    while(*(dest + (i++)) = *src++);

    return dest;
}

char *my_strcpy(char *dest, const char *src) {
    size_t i = 0;
    while(*(dest + (i++)) = *src++);

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
        if(*str == '\0') return NULL;
        str++;
    }
    return (char *)str; // cast away const
}

char *my_strstr(const char *str, const char *substr) {
    int is_matching = 0;
    size_t subindex = 0;
    while(*str != '\0') {
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
