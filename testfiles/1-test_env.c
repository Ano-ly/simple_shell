#include <stdio.h>
#include "../main.h"

int main(void)
{
	char *env[] = {"meeee", "nninin", NULL};

	built_env(env);
	return (0);
}

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

