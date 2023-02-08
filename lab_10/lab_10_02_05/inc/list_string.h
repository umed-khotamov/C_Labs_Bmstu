#include <stdlib.h>

#ifndef LIST_STRING_H

#define LIST_STRING_H

#include "types_defs.h"

void string_part_create(char *string, node_t **part);
int divide_string_to_list(char *str, node_t **head);
void print_list(node_t *head);
void remove_double_spaces(node_t *head);
void list_union(node_t **head, node_t **new_head);
size_t substring_pos(char *substring, node_t *head);
void free_list(node_t *head);

#endif 
