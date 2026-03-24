#include "my_string.h"
#include <stdio.h>

static inline int print_line() {
    return puts("======================================");
}

int main() {
    // strlen test
    char strlen_test[] = "1234567890";
    printf("strlen test\n length of \"%s\": %zu\n\n", strlen_test, my_strlen("1234567890"));
    print_line();

    // strcat test
    char strcat_dest[] = "Bab's Uvula ";
    char strcat_src[] = "Who?";
    printf("strcat test\n starting string: \"%s\"\n string to append: \"%s\"\n", strcat_dest, strcat_src);
    printf(" result: \"%s\"\n\n", my_strcat(strcat_dest, strcat_src));
    print_line();

    // strcpy test
    char strcpy_dest[] = "i will be overwritten! :3";
    char strcpy_src[] = "hehe i was overwritten :3";
    printf("strcpy test\n starting string: \"%s\"\n string to copy: \"%s\"\n", strcpy_dest, strcpy_src);
    printf(" result: \"%s\"\n\n", my_strcpy(strcpy_dest, strcpy_src));
    print_line();

    // strcmp test
    char strcmp1[] = "Everyone knows real programmers only use Emacs";
    char strcmp2[] = "Everyone knows real programmers only use vim";
    printf("strcmp test\n string1: \"%s\"\n string2: \"%s\"\n result: %d\n", strcmp1, strcmp2, my_strcmp(strcmp1, strcmp2));
    print_line();

    // strchr test
    char strchr_test[] = "nyaaaaaaaaaaaaAaaaaa";
    char chr = 'A';
    char *a = my_strchr(strchr_test, chr);
    printf("strchr test\n string: \"%s\"\n char: \'%c\'\n result: \'%c\'\n", strchr_test, chr, *a);
    print_line(); 

    // strstr test
    char strstr_str[] = "You want them to notice the ragged ends of your summer dress";
    char strstr_sub[] = "them";
    printf("strstr test\n string: \"%s\"\n substring: \"%s\"\n result: \"%s\"\n", strstr_str, strstr_sub, my_strstr(strstr_str, strstr_sub));
    print_line();

    return 0;
}
