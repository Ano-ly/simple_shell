#include "main.h"
#include <unistd.h>

/**
 * perror_command_not_found - handles and prints out
 * errors for commands that haven't been found
 * @argvo: argv[0] of the program
 * @ii: progress integer
 * @comm: command in question
 * @msg: additional message to be printed
 * Definition: prints error of the form:
 * 'argv[0]: ii: command: not found\n' when command
 * not found
 * Return: 0, if error printed successfully, -1 if not
*/

int perror_command_not_found(char *argvo, int ii, char *comm, char *msg)
{
	int arglen;
	int commlen;
	int msglen;
	int ret_value;
	char *semicolon;

	arglen = _strlen(argvo);
	commlen = _strlen(comm);
	msglen = _strlen(msg);
	semicolon = ": ";

	ret_value = write(STDERR_FILENO, argvo, arglen);
	if (ret_value == -1)
		return (-1);
	ret_value = write(STDERR_FILENO, semicolon, 2);
	ret_value = _malloc_ii(ii);
	if (ret_value == -1)
		return (-1);
	ret_value = write(STDERR_FILENO, semicolon, 2);
	ret_value = write(STDERR_FILENO, comm, commlen);
	if (ret_value == -1)
		return (-1);
	ret_value = write(STDERR_FILENO, semicolon, 2);
	ret_value = write(STDERR_FILENO, msg, msglen);
	if (ret_value == -1)
		return (-1);
	ret_value = write(STDERR_FILENO, "\n", 1);
	return (0);

}
