#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * noninteractive_main - deals with the non_interactive aspect
 * @buffer: buffer from main
 * @envp: environment
 * @argvo: first argument, i.e, argvo
 * @ii: program process count; won't increment here.
 * Definition - deals with the non-interactive aspect of the program
 * Return: 0
*/

int noninteractive_main(char *buffer, char **envp, char *argvo, int ii)
{

	if (ac != 1)
	{
		buffer = av[1];
		noninteractive_main(buffer, envp, av[0], i);
		return (0);
	}

	char **arr;
	int ieie;

	if (buffer[0] == '\0' || buffer[0] == '\n')
	{
		free(buffer);
		buffer = NULL;
		return (0);
	}
	/*if (buffer[get_value - 1] == '\n')*/
	/*	buffer[get_value - 1] = '\0';*/
	arr = split_string(buffer);
	if (arr == NULL)
		return (0);
	ieie = is_exit_is_env(arr, envp, argvo, ii);
	if (ieie >= 0)
	{
		free(arr);
		free(buffer);
		buffer = NULL;
		arr = NULL;
		exit(ieie);
	}
	if (arr[1] == NULL || buffer[0] != 32)
		free(arr[0]);
	free(arr);
	buffer = NULL;
	arr = NULL;

	return (0);
}
