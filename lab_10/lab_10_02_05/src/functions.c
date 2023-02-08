#include "types_defs.h"
#include "functions.h"
#include "list_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int identify_command(char *line, int *command)
{
    if (strcmp(line, COMMAND_OUT) == EQUAL)
        *command = OUT;
    else if (strcmp(line, COMMAND_CAT) == EQUAL)
        *command = CAT;
    else if (strcmp(line, COMMAND_SPS) == EQUAL)
        *command = SPS;
    else if (strcmp(line, COMMAND_POS) == EQUAL)
        *command = POS;

    return *command ? EXIT_SUCCESS : ERCOM_INPUT;
}

int input_string(char *dest)
{
    if (fgets(dest, BUFF_SIZE, stdin) == NULL)
        return ERFGETS;

    if (dest[strlen(dest) - 1] != '\n')
        return ERSTRLEN;

    dest[strlen(dest) - 1] = '\0';

    return EXIT_SUCCESS;
}

int cat_command(char *append_string, node_t **head, node_t **new_head)
{
    int return_code = 0;

    if ((return_code = input_string(append_string)) != EXIT_SUCCESS)
        return return_code;

    if ((return_code = divide_string_to_list(append_string, new_head)) != EXIT_SUCCESS)
        return return_code;

    list_union(head, new_head);

    return EXIT_SUCCESS;
}
