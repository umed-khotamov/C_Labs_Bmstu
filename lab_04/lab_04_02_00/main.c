#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define COUNT_WORDS 128
#define MAX_WORDS 128
#define NO_WORDS 3

#define STRING_LEN 256
#define WORD_LEN 16

#define EQUAL 2 
#define NOT_EQUAL 4

#define STRING_INPUT_ERROR 5
#define WORD_SIZE_ERROR 6

int input_string(char *string)
{
    char *p = fgets(string, STRING_LEN + 1, stdin);

    if (p == NULL || string[0] == '\n' || strlen(string) >= STRING_LEN)
        return STRING_INPUT_ERROR;

    return EXIT_SUCCESS;
}

int split_to_words(const char *const str, char words[][WORD_LEN])
{
    int word_counter = 0, char_counter = 0;

    for (size_t i = 0; i < strlen(str); i++)
    {
        if (!isspace(str[i]) && !ispunct(str[i]))
        {
            words[word_counter][char_counter] = str[i];
            char_counter++;
        }
        else
        {
            words[word_counter][char_counter] = '\0';
            word_counter++;
            char_counter = 0;
        }        
    }

    return word_counter;
}

int word_check(char words[][WORD_LEN], size_t words_len)
{
    size_t counter = 0;

    for (size_t i = 0; i < words_len; i++)
        if (strlen(words[i]) > WORD_LEN)            
            return WORD_SIZE_ERROR;

    for (size_t i = 0; i < words_len; i++)
        if (*words[i] == '\0')
            counter++;

    if (counter == words_len)
        return NO_WORDS;

    return EXIT_SUCCESS;
}

int words_equal(char *word1, char *word2)
{    
    if (*word1 == '\0')
        return NOT_EQUAL;
    
    if (strcmp(word1, word2) == 0)
        return EQUAL;
    
    return NOT_EQUAL;
}

void copy_to_arr(char *array1, char *array2, size_t size)
{
    for (size_t i = 0; i < size; i++)
        array1[i] = array2[i];
}

void init_array(char words[][WORD_LEN], size_t words_len, char array[][WORD_LEN], size_t *array_len)
{
    int counter = 0;

    size_t size = WORD_LEN;

    for (size_t i = 0; i < words_len; i++)
    {
        int flag = 0;
        
        for (size_t j = 0; j < i; j++)
            if (words_equal(words[i], words[j]) == EQUAL)
            {
                flag = 1;
                j = i;
            }
        
        if (flag)
            counter++;
        else
        {
            copy_to_arr(array[*array_len], words[i], size);
            *array_len = *array_len + 1;
        }
    }
}

void find_words_entry(char words[][WORD_LEN], size_t words_len, char array[][WORD_LEN], size_t array_len, int *words_count)
{
    for (size_t i = 0; i < array_len; i++)
    {
        size_t counter = 0;

        for (size_t j = 0; j < words_len; j++)
            if (words_equal(array[i], words[j]) == EQUAL)
                counter++;
        
        words_count[i] = counter;
    }
}

void print_result(char array[][WORD_LEN], size_t array_len, int *words_count)
{   
    printf("Result:\n");
    
    for (size_t i = 0; i < array_len; i++)
    {
        int flag = 1;
        
        if (words_count[i] == 0)
            flag = 0;
        
        if (flag)
            printf("%s %d\n", array[i], words_count[i]);
    }
}

int main(void)
{
    char string[STRING_LEN + 1], words[MAX_WORDS][WORD_LEN];
    
    if (input_string(string) == STRING_INPUT_ERROR)
        return STRING_INPUT_ERROR;

    size_t words_len = split_to_words(string, words);

    if (word_check(words, words_len) == WORD_SIZE_ERROR)
        return WORD_SIZE_ERROR;
    
    if (word_check(words, words_len) == NO_WORDS)
        return NO_WORDS;

    char array[MAX_WORDS][WORD_LEN];
    size_t array_len = 0;
    int words_count[COUNT_WORDS];
    
    init_array(words, words_len, array, &array_len);

    find_words_entry(words, words_len, array, array_len, words_count);

    print_result(array, array_len, words_count);

    return EXIT_SUCCESS;
}
