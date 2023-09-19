#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>

/*Function to compare two strings*/
int string_compare(const char *str1, const char *str2)
{
return (strncmp(str1, str2, strlen(str2)) == 0);
}
/*Function to execute a command*/
void execute_command(char **args)
{
pid_t pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
if (pid == 0)
{
/*Child process*/
if (execvp(args[0], args) == -1)
{
perror("execvp");
exit(EXIT_FAILURE);
}
}
else
{
/*Parent process*/
int status;
if (waitpid(pid, &status, 0) == -1)
{
perror("waitpid");
exit(EXIT_FAILURE);
}
}
}
