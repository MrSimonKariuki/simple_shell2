#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "getline.h"

#define BUFFER_SIZE 1024

char *custom_getline(void)
{
char *line = NULL;
int line_length = 0;
int buffer_size = BUFFER_SIZE;
int c;
/*Allocate an initial buffer*/
char *buffer = (char *)malloc(buffer_size);
if (buffer == NULL)
{
perror("malloc");
return (NULL);
}
while (1)
{
c = getchar();
if (c == '\n' || c == EOF)
{
if (line_length > 0)
{
if (line_length >= buffer_size)
{
/*Reallocate the buffer if needed*/
buffer_size *= 2;
char *temp = (char *)realloc(buffer, buffer_size);
if (temp == NULL)
{
perror("realloc");
free(buffer);
free(line);
return (NULL);
}
buffer = temp;
}
buffer[line_length++] = '\0'; /*Null-terminate the string*/
line = buffer;
}
else
{
/* Empty line, continue reading*/
continue;
}
return (line);
}
else
{
if (line_length >= buffer_size)
{
/*Reallocate the buffer if needed*/
buffer_size *= 2;
char *temp = (char *)realloc(buffer, buffer_size);
if (temp == NULL)
{
perror("realloc");
free(buffer);
free(line);
return (NULL);
}
buffer = temp;
}
buffer[line_length++] = c;
}
}
}
