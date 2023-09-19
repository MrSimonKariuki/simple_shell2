#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* Function to handle the "setenv" command*/
void handle_setenv(char **args)
{
if (args[1] != NULL && args[2] != NULL)
{
/*Call setenv to set or modify the environment variable*/
if (setenv(args[1], args[2], 1) != 0)
{
char error_message[] = "setenv: Failed to set environment variable\n";
write(STDERR_FILENO, error_message, strlen(error_message));
}
}
else
{
char usage_message[] = "Usage: setenv VARIABLE VALUE\n";
write(STDERR_FILENO, usage_message, strlen(usage_message));
}
}
