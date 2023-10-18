#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "main.h"
#include "main2.h"
#include <signal.h>

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

int main(int ac __attribute__((unused)), char **av,
char **envp)
{
	int get_value;
	char **arr;
	int ieie;

	int i = 1;
	size_t size = 0;
	char *buffer = NULL;

	while (1)
	{
		print_prompt();
		signal(SIGINT, free_ctrlc);
		get_value = getline(&buffer, &size, stdin);
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
		if (buffer[get_value - 1] == '\n')
			buffer[get_value - 1] = '\0';
		arr = split_string(buffer);
		if (arr == NULL)
			continue;
		ieie = is_exit_is_env(arr, envp, av[0], i);
		if (ieie >= 0)
			exit_ieie(ieie, arr, buffer);
		free(buffer);
		free(arr);
		buffer = NULL;
		arr = NULL;
		i++;
	}
	return (0);
}

/**
 * not_builtin_for_path - handles non-built-in commands, for
 * commands whose paths are specified
 * @arr: array of arguments at command line
 * @envp: environment. Not used in the body of function, just
 * @argvo: argv[0] of main function;
 * @ii: int count of main while loop repetitions.
 * to be passed to next function.
 * Description - Manages instructions of the form /bin/ls
 * Return: void
*/


void not_builtin_for_path(char **arr, char **envp, char *argvo, int ii)
{
	int comm_type;
	pid_t child_pid;
	int status;

	comm_type = is_path_is_exist(arr[0], argvo, ii);

	if (comm_type == 1)
	{
		child_pid = fork();
		if (child_pid == -1)
			perror("Could not fork");
		else if (child_pid == 0)
		{
			execute(arr[0], arr);
		}
		else
		{
			wait(&status);
		}
	}
	else if (comm_type == 0)
		not_builtin_for_non_path(arr, envp, argvo, ii);
}


/**
 * not_builtin_for_non_path - handles non-built-in commands, for
 * commands whose paths are not specified
 * @arr: array of arguments at command line
 * @envp: environment. Not used in the body of function, just
 * @argvo: argv[0] of main function;
 * @ii: int count of main while loop repetitions.
 *
 * to be passed to next function.
 * Description - Handles commands like ls
 * Return: void
*/

void not_builtin_for_non_path(char **arr, char **envp __attribute__((unused)),
char *argvo, int ii)
{
	char *comm_path;
	char **new_array;
	pid_t child_pid2;
	int status2;
	find_info is_found = find_command(arr[0]);

	if (is_found.find_status != 0)
	{
		comm_path = create_command_path(arr[0], is_found.dir_loc);
		new_array = create_new_array(comm_path, arr);
		if (comm_path != NULL && new_array != NULL)
		{
			child_pid2 = fork();
			if (child_pid2 == 0)
			{
				execute(new_array[0], new_array);
			}
			else
			{
				wait(&status2);
				not_path_frees(comm_path, new_array,
				is_found.dir_loc);
				return;
			}
		}
		not_path_frees(comm_path, new_array, is_found.dir_loc);
	}
	else
	{
		perror_command_not_found(argvo, ii, arr[0], "not found");
	}
	free(is_found.dir_loc);
	is_found.dir_loc = NULL;
}

/**
 * free_ctrlc - frees buffer when Ctrlc pressed
 * Description - runs when SIGINT signal is received by program
 * Return: void
*/

void free_ctrlc(int signal __attribute__((unused)))
{
	if (buffer != NULL)
		free(buffer);
	buffer = NULL;
	exit(0);
}

/**
 * print_prompt - prints the needed prompt
 * Description - prints prompt
 * Return: void
*/

void print_prompt(void)
{
	_putchar('$');
	_putchar(' ');
}
