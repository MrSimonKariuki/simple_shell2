#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*Function to handle the "unsetenv" command*/
void handle_unsetenv(char **args)
{
char *error_message = NULL;
if (args[1] != NULL)
{
/*Call unsetenv to remove the environment variable*/
if (unsetenv(args[1]) != 0)
{
/* Create the error message dynamically*/
error_message = strdup("unsetenv: Failed to unset environment variable\n");
if (error_message == NULL)
{
perror("strdup");
exit(EXIT_FAILURE); /* Handle allocation failure*/
}
/*Write the error message to STDERR using write*/
size_t error_length = strlen(error_message);
if (write(STDERR_FILENO, error_message, error_length) != (ssize_t)error_length)
{
perror("write");
}
/* Free the dynamically allocated error message*/
free(error_message);
}
}
else
{
/* Print a usage message if no variable name is provided*/
write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 25);
}
}

