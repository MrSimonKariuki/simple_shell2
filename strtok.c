#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

char **my_strtok(char *input)
{
char **tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
if (tokens == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
int token_count = 0;
char *token = strtok(input, " \t\n");
while (token != NULL && token_count < MAX_TOKENS)
{
tokens[token_count] = strdup(token);
if (tokens[token_count] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
token_count++;
token = strtok(NULL, " \t\n");
}
tokens[token_count] = NULL; /* Null-terminate the token array*/
return (tokens);
}
