#include "types_defs.h"
#include "list_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_part_create(char *string, node_t **part)
{
    for (size_t i = 0; i < PART_LEN; i++)
        if (string[i] == '\0')
        {
            for (size_t j = i; j < PART_LEN; j++)
                (*part)->data[j] = '\0';
            break;
        }
        else
            (*part)->data[i] = string[i];
}

int push_back(node_t **current, node_t **head)
{
    node_t *node = malloc(sizeof(node_t));
    
    if (node == NULL)
        return ERMALLOC;

    node->data = malloc(PART_LEN);

    if (node->data == NULL)
        return ERMALLOC;
    
    node->next = NULL;

    if (*head == NULL)
        *current = *head = node;
    else
        *current = (*current)->next = node;

    return EXIT_SUCCESS;
}

int divide_string_to_list(char *str, node_t **head)
{
    node_t *current = NULL;
    size_t lng = strlen(str) + 1;

    for (size_t i = 0; i < lng; i += PART_LEN)
    {
        push_back(&current, head);
        string_part_create(str + i, &current);
    }

    return EXIT_SUCCESS;
}

void print_list(node_t *head)
{
    while (head != NULL)
    {
        for (int i = 0; i < PART_LEN; i++)
        {
            if (head->data[i] != '\0')
            {
                printf("%c", head->data[i]);
            }
        }

        head = head->next;
    }

    putchar('\n');
}

void remove_double_spaces(node_t *head)
{
    node_t *temp = head;

    for (; temp; temp = temp->next)
    {
        for (size_t i = 0; i < PART_LEN - 1; i++)
            if (temp->data[i] == ' ' && temp->data[i + 1] == ' ')
                temp->data[i] = '\0';

        if (temp->next)
            if (temp->data[PART_LEN - 1] == ' ' && temp->next->data[0] == ' ')
                temp->data[PART_LEN - 1] = '\0';
    }
}

void list_union(node_t **head, node_t **new_head)
{
    node_t *temp = *head;
    
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = *new_head;
    *new_head = NULL;
}

size_t substring_pos(char *substring, node_t *head)
{
    int pos = 0;

    node_t *temp = head;

    int last_index = 0;
    int counter = 0;
    int flag = 0;
    int last_pos = 0;
    char *p = substring;
    
    while (temp != NULL)
    {
        for (int i = 0; i < PART_LEN; i++)
        {
            last_index++;
            
            if (*p == temp->data[i])
            {
                p++;
                counter++;
                last_pos = last_index;
            }
            else
            {
                p = substring;
                counter = 0;
                last_pos = 0;
            }
            if (counter == strlen(substring))
            {
                if (last_pos < strlen(substring))
                    pos = last_pos;
                else
                    pos = last_pos - strlen(substring);
                flag = 1;
                break;
            }
        }
        temp = temp->next;
        if (flag)
            break;
    }
    if (!flag)
        pos = -1;
   
    return pos;
}

void free_list(node_t *head)
{
    node_t *temp;
    for (; head; head = temp)
    {
        temp = head->next;
        free(head->data);
        free(head);
    }
}
