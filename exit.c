#include "exit.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*Function to handle the "exit" command*/
void handle_exit(char **args, char *input)
{
/*Check if there are no arguments (other than "exit")*/
if (args[1] == NULL)
{
/*Free dynamically allocated memory*/
free(input);
/*Exit the shell with status 0 (success)*/
exit(EXIT_SUCCESS);
}
else if (args[2] == NULL)
{
/*Try to convert the argument to an integer*/
int status = atoi(args[1]);
if (status != 0)
{
/*Free dynamically allocated memory*/
free(input);
/* Exit the shell with the specified status*/
exit(status);
}
else
{
/*Print an error message using write*/
char error_message[] = "Usage: exit [status]\n";
write(STDERR_FILENO, error_message, strlen(error_message));
}
}
else
{
/*Print an error message using write*/
char error_message[] = "Usage: exit [status]\n";
write(STDERR_FILENO, error_message, strlen(error_message));
}
}
