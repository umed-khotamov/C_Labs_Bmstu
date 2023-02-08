#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types_defs.h"
#include "functions.h"

int get_command(int argc, char *argv[], int *command)
{
    if (argc == MAX_ARGS && (strcmp(argv[MAX_ARGS - 1], "rd") == 0))
        *command = RM_DUPS;
    else if (argc == MAX_ARGS && (strcmp(argv[MAX_ARGS - 1], "pl") == 0))
        *command = POP_LAST;
    else if (argc == MIN_ARGS)
        *command = FIND;
	
    return *command ? EXIT_SUCCESS : ERR_ARGS;
}

void push_back(node_t **current, node_t **head, char *string)
{
    node_t *node = malloc(sizeof(node_t));

    node->data = strdup(string);
    node->next = NULL;

    if (*head == NULL)
        *current = *head = node;
    else
        *current = (*current)->next = node;
}

int read_file(char *filename, node_t **head)
{
    FILE *file = fopen(filename, "r");

    node_t *current = NULL;
    int return_code = 0;
    char *temp = NULL;
    size_t len = 0;
 
    while ((return_code = getline(&temp, &len, file)) != -1)
        push_back(&current, head, temp);
    
    free(temp);

    return EXIT_SUCCESS;
}

int comparator(const void *value_1, const void *value_2)
{
    const char *temp_1 = value_1;
    const char *temp_2 = value_2;

    return strncmp(temp_1, temp_2, strlen(temp_2));
}
