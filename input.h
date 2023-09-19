#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>

ssize_t read_user_input(char **input_buffer, size_t *buffer_size);
void display_prompt();

#endif /* INPUT_H */
