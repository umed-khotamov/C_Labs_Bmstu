#ifndef TYPES_DEFS_H

#define TYPES_DEFS_H

#define SIZE 20
#define EQUAL 0

#define ERMALLOC -1
#define ERR_ARGS -2

#define RM_DUPS 1
#define POP_LAST 2
#define FIND 3
#define PRINT 4

#define MAX_ARGS 3
#define MIN_ARGS 2

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

#endif
