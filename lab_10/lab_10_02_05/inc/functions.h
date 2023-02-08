#ifndef FUNCTIONS_H

#define FUNCTIONS_H

int input_string(char *string);
int identify_command(char *line, int *command);
int cat_command(char *append_string, node_t **head, node_t **new_head);

#endif
