#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av, char **envp __attribute__((unused)))
{
	if (isatty(STDIN_FILENO))
		printf("ac is one");
	else
		printf("The argument: %s, %d", av[0], ac);
	return (0);
}
