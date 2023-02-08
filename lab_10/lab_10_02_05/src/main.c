#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/types_defs.h"
#include "../inc/functions.h"
#include "../inc/list_string.h"

int main(void)
{
    node_t *head = NULL;
    node_t *new_head = NULL;

    char command_input[BUFF_SIZE];
    
    int return_code = 0;
    int command = 0;

    int pos = 0;
    
    if ((return_code = input_string(command_input)) != EXIT_SUCCESS)
        return return_code;
    
    if ((return_code = identify_command(command_input, &command)) != EXIT_SUCCESS)
        return return_code;
    
    char string[BUFF_SIZE];
    char append_string[BUFF_SIZE];
    char substring[BUFF_SIZE];

    if ((return_code = input_string(string)) != EXIT_SUCCESS)
        return return_code;

    if ((return_code = divide_string_to_list(string, &head)) != EXIT_SUCCESS)
    {
        free_list(head);
        return return_code;
    }
    switch (command)
    {
        case OUT:
            print_list(head);
            break;
        case CAT:
            if ((return_code = cat_command(append_string, &head, &new_head)) != EXIT_SUCCESS)
            {
                free_list(head);
                free_list(new_head);

                return return_code;
            }
            print_list(head);
            free_list(new_head);
            break;
        case POS:
            if ((return_code = input_string(substring)) != EXIT_SUCCESS)
            {
                free_list(head);
                return return_code;
            }
            pos = substring_pos(substring, head);
            printf("%d\n", pos);
            break;
        case SPS:
            remove_double_spaces(head);
            print_list(head);
            break;
    }
    free_list(head);

    return EXIT_SUCCESS;
}
