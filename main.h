#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

/* Function prototypes for functions in main.c */
ssize_t read_user_input(char **input_buffer, size_t *buffer_size);
void display_prompt(void);

/*Function prototypes for functions in tokenizer.c*/
char **tokenize_input(const char *input);

/*Function prototypes for functions in path.c*/
char *find_command_path(const char *command, char **env);

/*Function prototypes for functions in exit.c*/
void handle_exit(char **args, char *typeme);

/*Function prototypes for functions in env.c*/
void handle_env(char **env);
/*Function prototypes for functions in getline.c*/
char *custom_getline();
/*my own strtok function*/
char **my_strtok(char *input);
/*Function to compare two strings*/
int string_compare(const char *str1, const char *str2);
/*Function to execute a command*/
void execute_command(char **args);
/* Function to handle built-in commands*/
int execute_builtin(char **args);

#endif /* MAIN_H */

