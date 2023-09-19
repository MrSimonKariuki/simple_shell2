#include "env.h"
#include <string.h>
#include <unistd.h>

/* Function to print the current environment variables*/
void handle_env(char **env)
{
/*terate through the environment variables and print them*/
for (int i = 0; env[i] != NULL; i++)
{
size_t len = strlen(env[i]);
write(STDOUT_FILENO, env[i], len);
write(STDOUT_FILENO, "\n", 1);
}
}
