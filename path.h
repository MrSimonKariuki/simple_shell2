#ifndef PATH_H
#define PATH_H

#include <stdio.h>
#include <stdlib.h>

char *find_command_path(const char *command, char **env);

#endif /* PATH_H */
