#include "tokenizer.h"
#include <stdlib.h>
#include <string.h>

char **tokenize_input(const char *input)
{
/*Check for NULL input*/
if (input == NULL)
{
return (NULL);
}

/*Count the number of tokens (words) in the input*/
int token_count = 0;
const char *str = input;
while (*str != '\0')
{
/*skip leading whitespace*/
while (*str == ' ' || *str == '\t' || *str == '\n')
{
str++;
}
if (*str != '\0')
{
token_count++;
}
/*Find the end of the token*/
while (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\0')
{
str++;
}
}
/* Allocate memory for the array of tokens*/
char **tokens = (char **)malloc((token_count + 1) * sizeof(char *));
if (tokens == NULL)
{
return (NULL);  /* Memory allocation failed*/
}
/* Tokenize the input and store tokens in the array*/
int token_index = 0;
str = input;
while (*str != '\0')
{
/* Skip leading whitespace*/
while (*str == ' ' || *str == '\t' || *str == '\n')
{
str++;
}
if (*str != '\0')
{
const char *token_start = str;
/* Find the end of the token*/
while (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\0')
{
str++;
}
int token_length = str - token_start;
/*Allocate memory for the token and copy it*/
tokens[token_index] = (char *)malloc(token_length + 1);
if (tokens[token_index] == NULL)
{
/*Memory allocation failed, clean up and return NULL*/
for (int i = 0; i < token_index; i++)
{
free(tokens[i]);
}
free(tokens);
return (NULL);
}
strncpy(tokens[token_index], token_start, token_length);
tokens[token_index][token_length] = '\0';
token_index++;
}
}
/*Add a NULL pointer at the end to mark the end of the token array*/
tokens[token_count] = NULL;
return (tokens);
}

