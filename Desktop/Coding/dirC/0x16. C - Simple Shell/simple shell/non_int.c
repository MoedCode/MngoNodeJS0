#include "main.h"

char ***tokenize_non_int(char **cmd, char **args)
{
	int i = 0;
	int malloc_count = 1;
	char ***token_arr = malloc(sizeof(char **) * malloc_count);
	char **token = NULL;
	non_int(cmd, args);
	while (args[i] != NULL)
	{
		char ***tmp;

		token = tokenize_string(args[i], " \n");
		token_arr[i] = token;
		malloc_count++;
		i++;
		/**r*/

		tmp = realloc(token_arr, sizeof(char **) * malloc_count);

		if (tmp == NULL)
		{
			free_3d_arr(token_arr);
			free(cmd);
			free_double_arr(args);
			return NULL;
		}

		token_arr = tmp;
	}
	token_arr[i] = NULL;

	return token_arr;
}

void non_int(char **cmd, char **args)
{
	size_t read;
	size_t size;
	int i = 0;

	while ((read = getline(cmd, &size, stdin)) != -1)
	{

		args[i] = malloc(sizeof(char) * (read + 1));

		strncpy(args[i], *cmd, read);

		args[i][read - 1] = '\0';

		i++;
	}

	args[i] = NULL;
}
