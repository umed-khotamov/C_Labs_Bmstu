#ifndef TYPES_DEFS_H

#define TYPES_DEFS_H

#define EQUAL 0

#define COMMAND_OUT "out"
#define COMMAND_CAT "cat"
#define COMMAND_SPS "sps"
#define COMMAND_POS "pos"

#define OUT 1
#define CAT 2
#define SPS 3
#define POS 4

#define PART_LEN 4
#define BUFF_SIZE 1024

#define POS_NOT_FOUND 99

enum errors
{
    ERCOM_INPUT = 100,
    ERFGETS,
    ERMALLOC,
    ERSTRLEN
};

typedef struct node node_t;

struct node
{
    char *data;
    node_t *next;
};

#endif
