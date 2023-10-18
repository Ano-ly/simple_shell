#include <stdio.h>

int main(int ac, char **av, char **envp __attribute__((unused)))
{
	if (ac == 1)
		printf("ac is one");
	else
		printf("The argument: %s", av[1]);
	return (0);
}
