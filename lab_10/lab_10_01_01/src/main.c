#include <stdio.h>
#include <stdlib.h>

#include "types_defs.h"
#include "list.h"
#include "functions.h"

int main(int argc, char *argv[])
{
    int command = 0;

    node_t *head = NULL;
    char data[SIZE];

    char *filename = argv[1];
    read_file(filename, &head);

    get_command(argc, argv, &command);
    
    print_list(head);
    switch (command)
    {
        case RM_DUPS:
            remove_duplicates(&head, comparator);
            print_list(head);
            break;
        case POP_LAST:
            pop_back(&head);
            print_list(head);
            break;
        case FIND:
            scanf("%s", data);
            find(head, data, comparator);
            break;
    }
    free_list(head);

    return EXIT_SUCCESS;
}




