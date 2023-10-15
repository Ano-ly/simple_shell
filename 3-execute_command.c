#include <unistd.h>
#include "main.h"


/**
 * execute - does the actual execution of the command written in the
 * comment section of main
 * @comm_path: path to the command to be executed
 * @arr: array of arguments
 *
 * Definition - executes a command for child processes and exits 98 if
 * exec function failed.
 * Return: void
*/

void execute(char *comm_path, char **arr)
{
	int exec_value;

	exec_value = execve(comm_path, arr, environ);
	if (exec_value == -1)
		exit(98);
	exit(0);
}

/**
 * exec_chdir - changes the directory of the calling process to directory
 * housing the command, and then, executes the command.
 * @comm: single-word command to be executed
 * @arr: array of arguments to the command, including the command itself as the
 * first argument
 * @dir: directory to be changed to
 * Description - is used to execute commands that are not paths.
 * Return: void
*/

void exec_chdir(char *comm, char **arr, char *dir)
{
	int exec_value;
	int chdir_value;

	chdir_value = chdir(dir);
	if (chdir_value == 1)
		perror("Could not change directory");
	exec_value = execve(comm, arr, environ);
	if (exec_value == -1)
		perror("could not execute file");
}

/**
 * create_command_path - creates a string path for a command
 * @comm: command passed into function
 * @dir: directory where command is located
 *
 * Description - creates a string path that can be passed as the first argument
 * of the execve function. Works by joining string of path of directory
 * location and string of command, to form a path.
 * Return: created path, comm_path
*/

char *create_command_path(char *comm, char *dir)
{
	int len_comm;
	int len_dir;
	int len_path;
	char *comm_path;
	int i;
	int _i;

	len_comm = _strlen(comm);
	len_dir = _strlen(dir);
	len_path = len_comm + len_dir;

	comm_path = malloc(len_path + 2);
	if (comm_path == NULL)
		return (NULL);
	for (i = 0; i < len_dir; i++)
	{
		comm_path[i] = dir[i];
	}
	free(dir);
	_i = i;
	comm_path[_i] = '/';
	_i++;

	for (i = 0; i < len_comm; i++)
	{
		comm_path[_i] = comm[i];
		_i++;
	}
	comm_path[_i] = '\0';
	return (comm_path);
}

/**
 * create_new_array - creates a new argument array with command path created
 * by create_command_path function.
 * @comm_path: command path created by create_command_path function
 * @arr: old array with first argument as non-path command
 *
 * Description - creates a new argument array that would be passed to another
 * function for execution, by modifying old argument array
 * Return: new array containing command path
*/

char **create_new_array(char *comm_path, char **arr)
{
	int count;
	int i;
	char **new_arr;

	i = 0;
	count = 0;

	while (arr[i] != NULL)
	{
		count++;
		i++;
	}
	new_arr = malloc(count + 1);
	if (new_arr == NULL)
		return (NULL);
	new_arr[0] = comm_path;
	i = 1;

	while (arr[i] != NULL)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = NULL;
	/*free(arr);*/
	return (new_arr);
}

