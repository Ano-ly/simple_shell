#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * split_string - splits a string
 * @str: string to be split
 * Description - splits a string using strtok. Made for the purpose of
 * splitting input into shell and returning an array of
 * string arguments that can be passed into an exec function.
 * Also, the first argument of the resulting array can
 * be searched for in PATH.
 * Return: array of words of split string
*/

char **split_string(char *str)
{
	char *word;
	char *str_dup;
	char **array;
	int i;
	int count;
	int len;

	if (str == NULL)
		return (NULL);

	count = 0;
	len = _strlen(str);

	str_dup = malloc(len + 1);
	if (str_dup == NULL)
		return (NULL);
	_memcpy(str_dup, str, len + 1);
	word = strtok(str_dup, " ");
	while (word != NULL)
	{
		count++;
		word = strtok(NULL, " ");
	}
	array = malloc((count * sizeof(char *)) + 1);
	if (array == NULL)
	{
		free(str_dup);
		return (NULL);
	}
	word = strtok(str, " ");
	for (i = 0; i < count; i++)
	{
		array[i] = word;
		word = strtok(NULL, " ");
	}
	array[count] = (char *)NULL;
	free(str_dup);
	return (array);
}

/**
 * _strlen - computes the length of a string
 * @str: string whose length is to be computed
 * Description - computes length of string
 * Return: integer, length of string
*/

int _strlen(char *str)
{
	int i;
	int lenn;

	if (str == NULL)
		return (0);

	i = 0;
	lenn = 0;

	while (str[i] != 0)
	{
		lenn++;
		i++;
	}
	return (lenn);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	if (write(2, &c, 1) == -1)
	{
		perror("write");
		return (1);
	}
	return (1);
}

/**
 * _memcpy - copies bytes from a memory area to another memory area.
 * @dest: destination for bytes to be copied to
 * @src: source that bytes are copied from
 * @n: number of bytes to be copied
 * Description - copies bytes from one memory area to another using
 * for loops and indices.
 * Return: pointer to destination string
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	int j;

	j = 0;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = src[j];
		j++;
	}
	return (dest);
}
