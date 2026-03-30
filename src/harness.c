#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "my_string.h"

int pass = 0, fail = 0;

#define TEST(name, expr) do { \
    if(expr) { \
        printf("PASS: %s\n", name); \
        pass++; \
    } else { \
        printf("FAIL: %s\n", name); \
        fail++; \
    } \
} while(0)

int main() {
    // strlen
    TEST("strlen normal", my_strlen("I was a teenage anarchist") == strlen("I was a teenage anarchist"));
    TEST("strlen empty", my_strlen("") == 0);
    TEST("strlen single character", my_strlen("3") == 1);

    // strcpy
    char strcpy_dest[64];
    TEST("strcpy normal", my_strcpy(strcpy_dest, "When I'm lying in bed at night, I don't wanna grow up"));

    char strcpy_empty_dest[1]; 
    TEST("strcpy empty src", strcmp(my_strcpy(strcpy_empty_dest, ""), "") == 0);

    char strcpy_overlap1[] = "1234567890";
    char *strcpy_overlap2 = strcpy_overlap1 + 3;
    printf("strcpy overlapping (ub observation: does not affect test results): %s\n", strcpy(strcpy_overlap1, strcpy_overlap2));

    // strcat
    char strcat_dest[32];
    strcpy(strcat_dest, "I wanna be ");
    TEST("strcat normal", strcmp(my_strcat(strcat_dest, "the minority"), "I wanna be the minority") == 0);
    
    strcpy(strcat_dest, "I wanna be the minority");
    TEST("strcat empty src", strcmp(my_strcat(strcat_dest, ""), "I wanna be the minority") == 0);
    
    strcpy(strcat_dest, "");
    TEST("strcat empty dest", strcmp(my_strcat(strcat_dest, "I wanna be the minority"), "I wanna be the minority") == 0);

    // strcmp
    TEST("strcmp normal - str1 greater", my_strcmp("foo", "fOo") > 0);
    TEST("strcmp normal - str2 greater", my_strcmp("fOo", "foo") < 0);
    TEST("strcmp normal - equal", my_strcmp("bar", "bar") == 0);
    TEST("strcmp same prefix different length", my_strcmp("sapphic", "sapphical") < 0);
    TEST("strcmp first char differs", my_strcmp("puppy", "ouppy") > 0);
    TEST("strcmp empty", my_strcmp("", "") == 0);

    // strchr
    TEST("strchr normal", strcmp(my_strchr("foo :3 bar foo", '3'), "3 bar foo") == 0);
    TEST("strchr chr not in string", my_strchr("foo bar baz", '3') == NULL);
    TEST("strchr search for null", strcmp(my_strchr(":3", '\0'), "") == 0);
    TEST("strchr first character", strcmp(my_strchr(":3", ':'), ":3") == 0);
    TEST("strchr last character", strcmp(my_strchr(":3", '3'), "3") == 0);
    TEST("strchr multiple occurrences", strcmp(my_strchr(":3 :3 :3 :3", '3'), "3 :3 :3 :3") == 0);
    
    // strspn
    TEST("strspn normal", my_strspn("hehe :3 aaaaaaaaa", "she :3") == strspn("hehe :3 aaaaaaaaa", "she :3"));
    TEST("strspn no chars match", my_strspn("hehe :3 aaaaaaa", "OwO") == strspn("hehe :3 aaaaaaa", "OwO"));
    TEST("strspn all chars match", my_strspn("hehe :3 aaaaaaaaa", "ahe :3") == strspn("hehe :3 aaaaaaaaa", "ahe :3"));

    // debug
    printf("%zu %zu\n", my_strspn("hehe :3 aaaaaaaaa", "ahe :3"), strspn("hehe :3 aaaaaaaaa", "ahe :3"));

    TEST("strspn empty string", my_strspn("", "she :3") == strspn("", "she :3"));
    TEST("strspn empty span", my_strspn("hehe :3", "") == 0);

    // strstr
    TEST("strstr normal", strcmp(my_strstr("aaaaaaaaa awa :3 aaaaaaaaaa", "awa :3"), "awa :3 aaaaaaaaaa") == 0);
    TEST("strstr substring not found", my_strstr("aaaaaaaaa awa :3 aaaaaaaaaa", "nya :3") == NULL);
    TEST("strstr needle longer", my_strstr("nyanyanyanyanyanya", "AAAAAAAAAAAAAA") == NULL);
    TEST("strstr multiple occurences", strcmp(my_strstr("yay nyanyanyanyanya :3", "nya"), "nyanyanyanyanya :3") == 0);
    TEST("strstr empty needle", strcmp(my_strstr(":3", ""), ":3") == 0);

    printf("%d pass, %d fail\n", pass, fail);

    return fail;
}