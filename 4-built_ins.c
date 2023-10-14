#include "main.h"

/**
 * built_env - an implemented version of the env command.
 * @env_t: environment, pointer to an array of strings
 * Description - a built-in implementation of env
 * Return: void
*/

void built_env(char **env_t)
{
	int i;
	int j;
	char *var;

	i = 0;
	j = 0;

	while (env_t[i] != NULL)
	{
		var = env_t[i];
		while (var[j] != '\0')
		{
			_putchar(var[j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}

/**
 * exit_shell - exits the shell
 * @arr: array of arguments
 * Definition - exits shell and includes code for exit status.
 * Return: void
*/

void exit_shell(char **arr)
{
	int i;
	int count;
	char *status;
	int stat;

	i = 0;
	count = 0;

	while (arr[i] != NULL)
	{
		count++;
		i++;
	}
	if (count >= 2)
	{
		i = 0;
		status = arr[1];
		while (status[i] != '\0')
		{
			if (!(status[i] >=48 && status[i] <=57))
				perror("Invalid argument");
			i++;
		}
		stat = _atoi(status);
		exit (stat);
	}
	else if (count == 1)
		exit(0);

}
