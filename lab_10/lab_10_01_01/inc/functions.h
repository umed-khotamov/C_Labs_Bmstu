#ifndef FUNCTIONS_H

#define FUNCTIONS_H

int read_file(char *filename, node_t **head);
int comparator(const void *value_1, const void *value_2);
int get_command(int argc, char *argv[], int *command);

#endif
