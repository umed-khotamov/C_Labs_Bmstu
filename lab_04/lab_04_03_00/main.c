#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SYMBOLS " ,.-!?;:\n"

#define MAX_WORDS 128
#define NO_WORDS 2
#define COUNT_WORDS 3

#define STRING_LEN 256
#define WORD_LEN 16

#define EQUAL 0
#define NOT_EQUAL 1

#define STRING_INPUT_ERROR 4
#define WORD_SIZE_ERROR 5

int input_string(char *string)
{
    char *p = fgets(string, STRING_LEN + 1, stdin);

    if (p == NULL || string[0] == '\n' || strlen(string) >= STRING_LEN)
        return STRING_INPUT_ERROR;

    return EXIT_SUCCESS;
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

int split_to_words(char *const str, char words[][WORD_LEN])
{
    int word_counter = 0, char_counter = 0; 
    
    char *sep = strtok(str, SYMBOLS);

    while (sep != NULL)
    {
        for (size_t i = 0; i < strlen(sep) + 1; i++)
        {
            words[word_counter][char_counter] = sep[i];
            char_counter++;
        }   
        word_counter++;
        char_counter = 0;
        
        sep = strtok(NULL, SYMBOLS);
    }

    return word_counter;
}

int words_equal(char *word_1, char *word_2)
{
    if (strcmp(word_1, word_2) == 0)
        return EQUAL;

    return NOT_EQUAL;
}

void del_letter(char *string, size_t len, size_t index)
{
    size_t i = 0;

    for (i = index; i < len - 1; i++)
        string[i] = string[i + 1];
    string[i] = '\0';
}

void check_string(char *string)
{
    char first_l = *string;
    size_t len = strlen(string);

    for (size_t i = 1; i < len; i++)
        if (string[i] == first_l)   
        {    
            del_letter(string, len, i);
            i--;
            len--;
        }
}

void make_new_str(char words[][WORD_LEN], size_t words_count, char *new_string, int *counter)
{
    char *last_word = words[words_count - 1];
    
    for (int i = words_count - 1; i != -1; i--)
        if (words_equal(last_word, words[i]) != EQUAL)
        {
            check_string(words[i]);
            strcat(words[i], " "); 
            strcat(new_string, words[i]);
            *counter = *counter + 1;
        }
}

int main(void)
{
    char string[STRING_LEN + 1], new_string[STRING_LEN], words[MAX_WORDS][WORD_LEN];
    
    if (input_string(string) == STRING_INPUT_ERROR)
        return STRING_INPUT_ERROR;

    size_t words_count = split_to_words(string, words);

    if (word_check(words, words_count) == WORD_SIZE_ERROR)
        return WORD_SIZE_ERROR;

    if (word_check(words, words_count) == NO_WORDS)
        return NO_WORDS;
    
    strcpy(new_string, " ");
    
    int counter = 0;

    make_new_str(words, words_count, new_string, &counter);
    
    if (counter == 0)
        return NO_WORDS;
    
    printf("Result:%s\n", new_string);
    
    return EXIT_SUCCESS;
}
