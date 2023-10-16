#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

extern char **environ;

/**
 * struct find_info - contains information about whether or not
 * a command was found in PATH, and the directory it was found,
 * if found.
 * @find_status: 0 if file not found, 1 if found, -1 if error occured
 * @dir_loc: directory file was found in PATH, NULL if file not found
 * Description - used mainly by function find_command
*/

typedef struct find_info
{
	int find_status;
	char *dir_loc;
} find_info;

int is_path_is_exist(char *comm);
struct find_info find_command(char *command);
int find_file_in_dir(char *dir, char *file_name);
int _strcmp(char *s1, char *s2);

char **split_string(char *str);
int _strlen(char *str);
int _putchar(char c);
char *_memcpy(char *dest, char *src, unsigned int n);

void execute(char *comm_path, char **arr);
void exec_chdir(char *comm, char **arr, char *dir);
char *create_command_path(char *comm, char *dir);
char **create_new_array(char *comm_path, char **arr);

int is_exit_is_env(char **arr, char **envp);
void built_env(char **env_t);
int exit_shell(char **arr);

int _atoi(char *s);
int get_int(char c);
int get_start(char *str);
int get_end(char *str, int start);
int get_sign(char *str, int start);

void not_builtin_for_path(char **arr, char **envp __attribute__((unused)));
void not_builtin_for_non_path(char **arr, char **envp __attribute__((unused)));
void free_ctrlc();
#endif /*MAIN_H*/
