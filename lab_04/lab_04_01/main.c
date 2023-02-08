#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strpbrk(char *string1, char *string2)
{
    for (char *word1 = string1; *word1 != '\0'; word1++)
        for (char *word2 = string2; *word2 != '\0'; word2++)
            if (*word1 == *word2)
                return word1;

    return NULL;
}

size_t my_strspn(const char *string1, const char *string2)
{
    size_t i;

    for (i = 0; string1[i] != '\0'; i++)
        for (size_t j = 0; string2[j] != string1[i]; j++)
            if (string2[j] == '\0')
                return i;
    
    return i;
}

size_t my_strcspn(const char *string1, const char *string2)
{   
    size_t i;

    for (i = 0; string1[i] != '\0'; i++)
        for (size_t j = 0; string2[j] != '\0'; j++)
            if (string1[i] == string2[j])
                return i;

    return i;
}

const char *my_strchr(const char *string, const char c)
{
    while (*string != c && *string != '\0')
        string++;

    if (*string == c)
        return string;

    return NULL;
}

char *my_strrchr(const char *string, char c)
{
    char *value = NULL;
    
    if (string != NULL)
    {
        do
        {
            if (*string == c)
                value = (char *)string;
        }
        while (*string++);
    }

    return value;
}

int main(void)
{
    int neg_tests = 0;
    
    if (my_strpbrk("Car", "er") != strpbrk("Car", "er"))
        neg_tests++;
    if (my_strpbrk("Hello", "gggo") != strpbrk("Hello", "gggo"))
        neg_tests++;
    if (my_strpbrk("Lololo", "oaa") != strpbrk("Lololo", "oaa"))
        neg_tests++;
    
    if (my_strspn("Hello", "He") != strspn("Hello", "He"))
        neg_tests++;
    if (my_strspn("12hhh", "12345678") != strspn("12hhh", "12345678"))
        neg_tests++;
    if (my_strspn("abcdefg", "abcd") != strspn("abcdefg", "abcd"))
        neg_tests++;
    
    if (my_strcspn("hello1world", "23415") != strcspn("hello1world", "23415"))
        neg_tests++;
    if (my_strcspn("python", "oh") != strcspn("python", "oh"))
        neg_tests++;
    if (my_strcspn("car", "r") != strcspn("car", "r"))
        neg_tests++;
    
    if (my_strchr("Hello", 'o') != strchr("Hello", 'o'))
        neg_tests++;
    if (my_strchr("value", 'u') != strchr("value", 'u'))
        neg_tests++;
    if (my_strchr("123456", '6') != strchr("123456", '6'))
        neg_tests++;

    if (my_strrchr("Hello", 'k') != strrchr("Hello", 'k'))
        neg_tests++;
    if (my_strrchr("Lololo", 'o') != strrchr("Lololo", 'o'))
        neg_tests++;
    if (my_strrchr("car", 'a') != strrchr("car", 'a'))
        neg_tests++;
    
    printf("Negative tests: %d\n", neg_tests);

    return EXIT_SUCCESS;
}
