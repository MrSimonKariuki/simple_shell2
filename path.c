#include "path.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/*Function to find the full path of a command in PATH*/
char *find_command_path(const char *command, char **env)
{
char *path = NULL;
/*terate through the environment variables*/
for (int i = 0; env[i] != NULL; i++)
{
if (strncmp(env[i], "PATH=", 5) == 0)
{
path = env[i] + 5; /* Extract the PATH value*/
break;
}
}
if (path == NULL)
{
/*Handle the case when PATH is not set*/
char error_message[] = "PATH environment variable not set\n";
write(STDERR_FILENO, error_message, strlen(error_message));
return (NULL);
}
char *path_copy = strdup(path);
char *path_token = strtok(path_copy, ":");
while (path_token != NULL)
{
size_t path_length = strlen(path_token) + strlen(command) + 2; /*+2 for '/' and null terminator*/
char *command_path = (char *)malloc(path_length);
if (command_path == NULL)
{
perror("malloc");
free(path_copy);
return (NULL);
}
snprintf(command_path, path_length, "%s/%s", path_token, command);
struct stat buffer;
if (stat(command_path, &buffer) == 0)
{
/*Found the command in one of the directories in PATH*/
free(path_copy);
return (command_path);
}
free(command_path);
path_token = strtok(NULL, ":");
}
free(path_copy);
return (NULL);
}
