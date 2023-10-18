#include <stdio.h>
#include "main.h"

/**
 * _getenv - gets the value of an environment variable
 * @var_name: name of variable being checked for
 * Definition: implementations of getenv
 * Description: The code that provides functionality similar to getenv
 * Return: pointer to variable value, NULL if variable not found
*/

char *_getenv(char *var_name)
{
	int i;
	int var_is;
	char *loc;
	int index;
	char *var;

	i = 0;

	while (environ[i] != NULL)
	{
		var = environ[i];
		var_is = _strcmp_env(var, var_name);
		if (var_is == 0)
		{
			index = find_envar_start(var);
			loc = &var[index];
			return (loc);
		}
		i++;
	}
	return (NULL);

}

/**
 * _strcmp_env - compares two strings; one, and environment variable,
 * two, the variable name being searched for
 * @s1: environment variable string
 * @s2: second string to be compared
 *
 * Description - compares two strings using ascii values
 * Return: 0 is similar, 1 if not
 * negative integer if otherwise
*/

int _strcmp_env(char *s1, char *s2)
{
	int i;
	int s1l;
	int schoose;
	int s2l;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	s1l = _strlen_env(s1);
	s2l = _strlen(s2);

	if (s1l > s2l)
	{
		schoose = s2l;
	}
	else
	{
		schoose = s1l;
	}

	for (i = 0; i < schoose; i++)
	{
		if (s1[i] - s2[i])
			return (1);
	}
	return (0);
}


/**
 * _strlen_env - computes the length of a string
 * @str: string whose length is to be computed;
 * environmental variable
 * Description - Calculates the character count of the
 * environmental variable's name
 * Return: integer, length of string
*/

int _strlen_env(char *str)
{
	int i;
	int lenn;


	if (str == NULL)
		return (0);

	i = 0;
	lenn = 0;

	while (str[i] != '=')
	{
		lenn++;
		i++;
	}
	return (lenn);
}

/**
 * find_envar_start - finds the start of the value of an environment variable
 * @var: environment variable
 * Description: Identifies the  location at which the _getenv function will
 * return pointer to
 * Return: index location
*/

int find_envar_start(char *var)
{
	int index;
	int i;

	index = 1;
	i = 0;

	while (var[i] != '=')
	{
		index++;
		i++;
	}
	return (index);
}
