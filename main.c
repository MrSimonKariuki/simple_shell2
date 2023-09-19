#include "main.h"
#include "strtok.h"
#include "path.h"
#include "exit.h"
#include "env.h"
#include "execute.h"
#include "getline.h"
#include "setenv.h"
#include "unsetenv.h"

int main(int argc, char *argv[], char **env)
{
char *typeme = NULL;
ssize_t bytes;
char prompt[] = "$ ";
while (1)
{
write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
/* Use custom_getline instead of getline*/
typeme = custom_getline();
if (typeme == NULL)
{
perror("Error(custom_getline)");
return (EXIT_FAILURE);
}
/* Calculate the length of the input line*/
ssize_t line_length = strlen(typeme);
/* Replace the blank line with a null terminator*/
if (line_length > 0 && typeme[line_length - 1] == '\n')
{
typeme[line_length - 1] = '\0';
}
/*Tokenize the typeme into arguments using my strtok*/
char **args = my_strtok(typeme);
if (args == NULL)
{
free(typeme);
continue; /* Skip the rest of the loop and prompt again*/
}
/*Check if the command is "exit" and exit the shell*/
if (strcmp(args[0], "exit") == 0)
{
handle_exit(args, typeme);
/*Free dynamically allocated memory for args*/
free(args);
free(typeme);
break; /*Exit the shell*/
}
/*Check if the command is "env" and print environment variables*/
if (strcmp(args[0], "env") == 0)
{
handle_env(env);
/*Free dynamically allocated memory for args*/
free(args);
free(typeme);
continue; /*Skip the rest of the loop and prompt again*/
}
/*Check if the command includes a full path*/
if (strchr(args[0], '/') == NULL)
{
/* Find the full path of the command using PATH*/
char *command_path = find_command_path(args[0], env);
if (command_path != NULL)
{
args[0] = command_path;
}
else
{
/*Command not found in any PATH directory*/
write(STDERR_FILENO, "Command not found: ", 19);
write(STDERR_FILENO, args[0], strlen(args[0]));
write(STDERR_FILENO, "\n", 1);
/*Free dynamically allocated memory for args*/
free(args);
free(typeme);
continue;
}
}
/*Execute the command*/
execute_command(args);
/* Free dynamically allocated memory for args*/
free(args);
free(typeme);
}
return (0);
}
