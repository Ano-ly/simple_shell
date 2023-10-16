#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "main.h"

/**
 * main - starting point of program.
 * @ac: count of string arguments
 * @av: array of string arguments
 * @envp: current environment
 * Definition - calls the getline function, and the function that
 * splits string input, and the command that checks if the command
 * is a built-in
 * Return: Always zero
*/

int main(int ac __attribute__((unused)), char **av __attribute__((unused))
, char **envp)
{
	char *buffer;
	int get_value;
	size_t size;
	char **arr;
	int ieie;
	int j;

	int i = 0;
	size = 0;
	buffer = NULL;

	while (1)
	{
		_putchar('$');
		_putchar(' ');
		get_value = getline(&buffer, &size, stdin);
		signal(SIGINT, &free_ctrlc);
		if (get_value == -1)
		{
			free(buffer);
			buffer = NULL;
			break;
		}
		if (buffer[0] == '\0' || buffer[0] == '\n')
		{
			free(buffer);
			buffer = NULL;
			continue;
		}
		buffer = strtok(buffer, "\n");
		arr = split_string(buffer);
		if (arr == NULL)
		{
			perror("Failed to allocate memory");
			continue;
		}
		ieie = is_exit_is_env(arr, envp);
		if (ieie == -1)
			perror("Error occured");
		else if (ieie == 1)
		{
			j = 0;
			while (arr[j] != NULL)
			{
				free(arr[j]);
				j++;
			}
			free(arr);
			break;
		}
		j = 0;
		while (arr[j] != NULL)
		{
			free(arr[j]);
			j++;
		}
		free(arr);
		buffer = NULL;
		arr = NULL;
		i++;
	}
	/*free(buffer);*/
	/*free(arr[0]);*/
	/*free(arr);*/
	return (0);
}

/**
 * not_builtin_for_path - handles non-built-in commands, for
 * commands whose paths are specified
 * @arr: array of arguments at command line
 * @envp: environment. Not used in the body of function, just
 * to be passed to next function.
 * Description - Handles commands like /bin/ls
 * Return: void
*/


void not_builtin_for_path(char **arr, char **envp)
{
	int comm_type;
	pid_t child_pid;
	int status;

	comm_type = is_path_is_exist(arr[0]);
	if (comm_type == -1)
	{
		perror("Cannot find file");
	}
	else if (comm_type == 1)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			execute(arr[0], arr);
			/*free(arr);*/
		}
		else
		{
			wait(&status);
			/*free(arr);*/
		}
	}
	else if (comm_type == 0)
		not_builtin_for_non_path(arr, envp);
}


/**
 * not_builtin_for_non_path - handles non-built-in commands, for
 * commands whose paths are not specified
 * @arr: array of arguments at command line
 * @envp: environment. Not used in the body of function, just
 * to be passed to next function.
 * Description - Handles commands like ls
 * Return: void
*/

void not_builtin_for_non_path(char **arr, char **envp __attribute__((unused)))
{
	find_info is_found;
	char *comm_path;
	char **new_array;
	pid_t child_pid2;
	int status2;

	is_found = find_command(arr[0]);

	if (is_found.find_status == 0)
		perror("Command not found");
	else
	{
		comm_path = create_command_path(arr[0], is_found.dir_loc);
		if (comm_path == NULL)
			perror("Problem occured");
		new_array = create_new_array(comm_path, arr);
		if (new_array == NULL)
			perror("Problem occurred");
		else if (comm_path != NULL && new_array != NULL)
		{
			child_pid2 = fork();
			if (child_pid2 == 0)
			{
				execute(new_array[0], new_array);
			}
			else
			{
				wait(&status2);
				free(is_found.dir_loc);
				free(comm_path);
				free(new_array);
				return;
			}
		}
		free(is_found.dir_loc);
		free(comm_path);
		free(new_array);
	}
}

/**
 * free_ctrlc - frees buffer when Ctrlc pressed
 * Description - runs when SIGINT signal is received by program
 * Return: void
*/

void free_ctrlc()
{
	int a;
	a = 4 + 4;
	a += 7;
}
