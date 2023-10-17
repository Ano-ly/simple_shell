#include <stdio.h>
#include "main.h"

/**
 * exit_ieie - replaces code in 6-main.c
 * @ieie: status with which to be exited
 * @arr: array, to be freed
 * @buffer: the buffer for the main function
 * Definition - replaces code to shorten main function
 * in order to pass betty checks
 * Return: void
*/

void exit_ieie(int ieie, char **arr, char *buffer)
{
	free(arr);
	free(buffer);
	buffer = NULL;
	arr = NULL;
	exit(ieie);
}

/**
 * not_path_frees - frees certain memory allocated due to processing
 * commands that are paths.
 * @comm_path: command path
 * @new_array: new array with command path
 * @dir_loc: (is_found.dir_loc)
 * Description - replaces some code in not_builtin_for_non_path
 * function.
 * Return: void
*/

void not_path_frees(char *comm_path, char **new_array, char *dir_loc)
{
	free(dir_loc);
	free(comm_path);
	free(new_array);
	dir_loc = NULL;
	comm_path = NULL;
	new_array = NULL;
}
