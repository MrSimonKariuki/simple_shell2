#include "main.h"
#include "input.h"
ssize_t read_user_input(char **input_buffer, size_t *buffer_size)
{
/* Use getline to read user input*/
ssize_t bytes = getline(input_buffer, buffer_size, stdin);
if (bytes == -1)
{
perror("getline");
}
/* Replace the trailing newline character (if present) with a null terminator*/
if (*input_buffer && bytes > 0 && (*input_buffer)[bytes - 1] == '\n')
{
(*input_buffer)[bytes - 1] = '\0';
}
return (bytes);
}
