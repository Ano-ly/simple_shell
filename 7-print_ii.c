#include "main.h"
/*#include <stdio.h>*/
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _malloc_ii - allocates suitable memory space for intii
 * @num: number to be printed.
 *
 * Definition - Calculates the memory allocation size and
 * allocates the corresponding number of bytes.
 * Return: count of printed characters
*/

int _malloc_ii(int num)
{
	int n;
	char *buffer;
	long int pow;
	int i;
	int count;
	long int num_long;

	n = 0;
	count = 0;
	num_long = num;

	while (1)
	{
		pow = 1;
		for (i = 0; i < n; i++)
			pow *= 10;
		if (pow <= num_long)
			n++;
		else
			break;
	}
	buffer = malloc(sizeof(char) * n);
	if (buffer == NULL)
		return (-1);
	count += fill_buffer(buffer, num_long, n, 10);
	return (count);
}

/**
 * fill_buffer - fills up previously allocated memory space with decimal digits
 * @buffer: memory space to be filled up
 * @num: number
 * @n: size of memory space
 * @base: conversion base
 *
 * Definition - fills buffer
 * Return: count of printed characters
*/

int fill_buffer(char *buffer, long int num, int n, int base)
{
	int quotient;
	int rem;
	int i;
	int count;

	i = 0;
	quotient = 1;

	while (quotient != 0)
	{
		quotient = num / base;
		rem = num % base;
		buffer[i] = rem + '0';
		num = quotient;
		i++;
	}
	count = print_rev_buffer(buffer, n);
	return (count);
}

/**
 * print_rev_buffer - prints a reversed string
 * @buffer: previously allocated memory space
 * @n: buffer size
 *
 * Definition - prints reversed string; needed to print binary
 * digits in the right order
 * Return: number of characters printed
*/

int print_rev_buffer(char *buffer, int n)
{
	int i;
	int sub2_count;

	sub2_count = 0;

	i = n - 1;
	while (i >= 0)
	{
		_putchar_err(buffer[i]);
		i--;
		sub2_count++;
	}
	free(buffer);
	/*printf("/sub2_count: %d\n/", sub2_count);*/
	return (sub2_count);
}

/**
 * _putchar_err - writes the character c to stderr
 * @c: The character to print
 * Description: defines a function for writing a character
 * to standard error stream and provide error handling if encountered
 * any issues
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar_err(char c)
{
	if (write(STDERR_FILENO, &c, 1) == -1)
	{
		perror("write");
		return (1);
	}
	return (1);
}
