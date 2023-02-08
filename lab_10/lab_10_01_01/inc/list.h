#ifndef LIST_H

#define LIST_H

#include "types_defs.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));
void *pop_back(node_t **head);
void print_list(node_t *head);
void free_list(node_t *head);
void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *));

#endif
