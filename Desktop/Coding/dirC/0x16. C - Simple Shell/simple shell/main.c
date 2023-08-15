#include "main.h"
int main(void)
{
	int flag = isatty(STDIN_FILENO);

	while (1)
	{
		printf("\033[0;36m simpleShill$\033[0m ");


		char *cmd = NULL, **args = malloc(sizeof(char *) * 50);
		char ***threeD_arr = NULL;

		size_t size;

		int i = 0, read;

		char *token = NULL;

		if (!flag)
			// non_int(&cmd, args);
			threeD_arr = tokenize_non_int(&cmd, args);

		else
			tokenize_interactive_mode(&cmd, &args);

		for (size_t j = 0; args[j] != NULL; j++)
		{
			printf("argv :: %s\n", args[j]);
		}
		printf("\n------------\n");

		if (!flag)
		{
			print3d_arr(threeD_arr);
		}

		printf("\n------------\n");

		printf("%s\n", getenv("PATH"));

		char *path = getenv("PATH");
		char *pathCpy = strdup(path);

		char **ListOFpaths = tokenize_string(pathCpy, ":=");
		i = 0;

		while (ListOFpaths[i] != NULL)
		{
			printf("token: {%s}\n", ListOFpaths[i]);
			i++;
		}
		/*free mem*/

		free(cmd);
		free_double_arr(args);
		free_double_arr(ListOFpaths);
		free(pathCpy);

		if (!flag)
			free_3d_arr(threeD_arr);
	}
}

void print3d_arr(char ***threeD_arr)
{
	for (size_t i = 0; threeD_arr[i] != NULL; i++)
	{
		char **token = threeD_arr[i];

		for (size_t j = 0; token[j] != NULL; j++)
		{
			printf(" %s", token[j]);

			if (token[j + 1] != NULL)

				putchar(',');
		}
		putchar('\n');
	}
}