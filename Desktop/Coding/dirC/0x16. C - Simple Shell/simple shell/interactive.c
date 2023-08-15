#include "main.h"
#include <stddef.h>
#include <string.h>

void tokenize_interactive_mode(char **cmd, char ***args)
{
	size_t size;

	int read = getline(cmd, &size, stdin);

	size_t ln = strlen(*cmd);
	printf("cmd len %lld interactive.c \n", ln);

	if (!strcmp(*cmd, "exit\n"))/*if cmd == exit strcmp => 0  >>  ! 0 >> exit */
	{
		free(*cmd);
		free(*args);
		exit(0);
	}

	/*free the old args value before reassigning it*/
	free(*args);

	*args = tokenize_string(*cmd, " \n");
}
