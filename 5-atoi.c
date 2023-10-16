#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * get_int - converts argument from char to int
 * @c: character to be converted to int
 * Definition - uses if and else if to convert char to int
 * Return: converted character
*/

int get_int(char c)
{
	if (c == 48)
		return (0);
	else if (c == 49)
		return (1);
	else if (c == 50)
		return (2);
	else if (c == 51)
		return (3);
	else if (c == 52)
		return (4);
	else if (c == 53)
		return (5);
	else if (c == 54)
		return (6);
	else if (c == 55)
		return (7);
	else if (c == 56)
		return (8);
	else if (c == 57)
		return (9);
	else
		return (-1);
}

/**
 * get_start - Gets the index of the first instance of a number
 * @str: str whose first instance of a number is to be gotten
 * Definition- uses for loops and ascii values to get index required
 * Return: integer, index of first instance of number
*/

int get_start(char *str)
{
	int start;
	int i;
	int l;

	l = _strlen(str);
	start = 0;

	for (i = 0; i < l; i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			return (start);
		}
		start++;
	}
	return (-1);
}

/**
 * get_sign - gets the sign of integer in string
 * @str: string in which an integer is found
 * @start: the index of the first digit in the string
 * Description - Leverages for loops and conditional
 * if-else statements to calculate the sign.
 * Return: 0 if positive, 1 if negative
*/

int get_sign(char *str, int start)
{
	int i;
	int minus;
	int plus;

	minus = 0;
	plus = 0;

	for (i = 0; i < start; i++)
	{
		if (str[i] == 45)
			minus++;
		if (str[i] == 43)
			plus++;
	}
return (minus % 2);
}

/**
 * get_end - Gets the index of the last digit of the first integer instance
 * @str: string to be iterated through
 * @start: index of the first digit of first integer instance in string
 * Description - uses while loop to get required index
 * Return: integer, index of last digit of first integer instance
*/

int get_end(char *str, int start)
{
	int i;

	i = start + 1;

	while (str[i] >= 48 && str[i] <= 57)
	{
		i++;
	}
	return (i);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 * Description - converts string to integer using powers of ten and for loops
 * Return: converted integer, 0, if no integer found in string
*/

int _atoi(char *s)
{
	if (get_start(s) != -1)
	{
		int _int;
		int i;

		int start = get_start(s);
		int end = get_end(s, start);
		int sign = get_sign(s, start);
		int number = 0;
		int exp = end - start - 1;

		for (i = start; i < end; i++)
		{
			_int = get_int(s[i]);

			if (_int == 0)
			{
				exp--;
				continue;
			}
			else
			{
				int j;
				int mult;

				mult = 1;

				for (j = 0; j < exp; j++)
					mult *= 10;
				number += _int * mult;
				exp--;
			}
		}
		if (sign == 1)
			return (-number);
		else
			return (number);
	}
	else
		return (0);
}
