#include "libs.h"
/**
 * main - Entry point of the program
 * Return: Always 0 (success)
 */
int main(void)
{
	char *input;
	char *args[MAX_ARGS];
	size_t bufsize = 0;
	ssize_t characters;

	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	while (1)
	{
		prompt();
		input = NULL;
		characters = getline(&input, &bufsize, stdin);
		if (characters == -1)
		{
			write(1, "\n", 1);
			exit(0);
		}
		if (!*(input + 1))
		{
			free(input);
			continue;
		}
		parse_input(_strdup(input), args);
		if (!args[0])
		{
			free(input);
			continue;
		}
		if (_strcmp(input, "exit\n") == 0)
		{
			free(input);
			exit(0);
		}
		run_cmd(input);
		free(input);
		input = NULL;
		bufsize = 0;
	}
	return (0);
}
