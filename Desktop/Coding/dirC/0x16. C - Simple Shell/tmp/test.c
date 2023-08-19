#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

size_t free_argv(char **argv)
{
	size_t i, j;

	for (j = 0; argv[j]; j++)
			;
	for (i = 0; i < j; i++)
		free(argv[i]);

	free(argv);
	return (i);
}
char  **tokenize(char *cmd, char*  delim)
{
	size_t TksNum = 0;
	char *token = NULL, **Tokens = NULL;

	token = strtok(cmd, delim);
	while (token)
	{
		Tokens = realloc(Tokens, sizeof(char *) * (TksNum + 1));

		if (!Tokens)
		{
			free_argv(Tokens);
			perror("tokenaize.c:21 realloc");
			return (NULL);
		}
	/* tokinize && Asign */
		Tokens[TksNum] = strdup(token);
		// printf("tenize.c:25 %s\n",Tokens[TksNum]);
		token = strtok(NULL, delim);
		TksNum++;
	}

		Tokens = realloc(Tokens, sizeof(char *) * (TksNum + 1));
		if (!Tokens)
		{
			free_argv(Tokens);
			perror("tokenaize.c:21 realloc");
			return (NULL);
		}

		Tokens[TksNum] = NULL;

			return (Tokens);
}

 char *SearchIntEnv(char *startWith)
{
	char **s = environ;

	for (; *s; s++ )
	/* && s[i][5] != '\0' && s[i][5] != ' ' */
		if (!strncmp(startWith, *s, 5 ) )
			return (*s);

return (NULL);
}
int main()
{


	size_t i;
	char **s = environ, *envPath = strdup(SearchIntEnv("PATH=")), **TokEnvPath;
	envPath += 4;
	TokEnvPath = tokenize(envPath, ":=");
	for (i = 0; TokEnvPath[i]; i++)
		{
		printf("[%zu] =>  %s\n",i, TokEnvPath[i]);
		printf("[%zu] =>  %i\n",i, access(TokEnvPath[i], X_OK));
		}

	free_argv(TokEnvPath);

			// printf("\n	 \033[1;36m--path[%zu]--\033[0m	\n\n",i);


	return (0);
}
