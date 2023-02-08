#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types_defs.h"
#include "list.h"
#include "functions.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    node_t *temp = head;
    node_t *found = NULL;

    while (temp != NULL)
    {
        if ((*comparator)(temp->data, data) == EQUAL)
        {
            found = temp;
            break;
        }
        temp = temp->next;
    }

    return found;
}

void *pop_back(node_t **head)
{
    if (!head || !(*head))
    {
        return NULL;
    }

    node_t *tmp = *head, *end;

    if (tmp->next == NULL)
    {
        void *data = tmp->data;
        *head = NULL;
        free(tmp);

        return data;
    }

    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }

    void *data = tmp->next->data;
    
    end = tmp->next;
    tmp->next = NULL;

    free(end);
    
    return data;
}

void print_list(node_t *head)
{
    node_t *temp = head;

    while (temp != NULL)
    {
        printf("%s", (char *)temp->data);
        
        temp = temp->next;
    }
    printf("\n");
}

void free_list(node_t *head)
{
    node_t *next;

    for (; head; head = next)
    {
        next = head->next;
        free(head->data);
        free(head);
    }
}

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *))
{
    node_t *curr = *head;
    node_t *next = NULL;
    node_t *dup = NULL;

    while (curr != NULL && curr->next != NULL)
    {
        next = curr;

        while (next->next != NULL)
        {
            if ((*comparator)(curr->data, next->next->data) == EQUAL)
            {
                dup = next->next;
                next->next = next->next->next;
                free(dup);
            }
            else
                next = next->next;
        }
        curr = curr->next;
    }
}
