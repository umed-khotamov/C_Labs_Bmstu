#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRING_LEN 256

#define MAX_NUM 3
#define NO_NUM 0

#define MAX_IP_VALUE 255
#define MIN_IP_VALUE 0

#define STRING_INPUT_ERROR 3
#define NO_IP 4

#define DELIM "."

int input_string(char *string)
{
    char *p = fgets(string, STRING_LEN + 1, stdin);
    
    if (p == NULL || strlen(string) >= STRING_LEN)
        return STRING_INPUT_ERROR;
   
    return EXIT_SUCCESS;
}

int check_split_string(char *split_string)
{
    int counter = 0;

    for (size_t i = 0; i < strlen(split_string); i++)
    {
        int flag = 1;

        if (isspace(split_string[i]))
            flag = 0;
        
        if (flag)
        {
            if (isalpha(split_string[i]))
                return NO_IP;

            if (!isdigit(split_string[i]))
                return NO_IP;
        
            counter++;
        }
    }
    if (counter > MAX_NUM || counter == NO_NUM)
        return NO_IP;

    return EXIT_SUCCESS;
}

int is_valid_ip(char *string)
{    
    char *split_string;
    int num = 0, num_counter = 0;

    split_string = strtok(string, DELIM);

    if (split_string == NULL)
        return NO_IP;

    while (split_string)
    {
        if (check_split_string(split_string) == NO_IP)
            return NO_IP;
        
        num = atoi(split_string);

        if (num < MIN_IP_VALUE || num > MAX_IP_VALUE)
            return NO_IP;
        
        split_string = strtok(NULL, DELIM);

        if (split_string != NULL)
            num_counter++;
    }
    if (num_counter != 3)
        return NO_IP;

    return EXIT_SUCCESS;
}

int main(void)
{
    char string[STRING_LEN + 1];

    if (input_string(string) == STRING_INPUT_ERROR)
        return STRING_INPUT_ERROR;

    if (is_valid_ip(string) == NO_IP)
    {
        printf("NO\n");

        return EXIT_SUCCESS;
    }

    printf("YES\n");

    return EXIT_SUCCESS;
}
