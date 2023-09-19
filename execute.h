#ifndef EXECUTE_H
#define EXECUTE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>

/*Function to compare two strings*/
int string_compare(const char *str1, const char *str2);

/*Function to execute a command*/
void execute_command(char **args);

#endif /* EXECUTE_H */
