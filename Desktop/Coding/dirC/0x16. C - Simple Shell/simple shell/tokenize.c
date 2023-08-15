#include "main.h"
#include <stddef.h>
#include <stdio.h>

char **tokenize_string(char *str, char *del)
{
	char **tokenList ,*token;
	size_t i;

	for (i = 0; str[i]!= '\0'; i++)
		;
	tokenList = malloc(sizeof(char *) *i);
	if (!tokenList)
	{
		perror("\033[1;31mFaild to Allocate.\033[0m\n \
		\033[0;34m\"tokenList\" --tokenize.c line 12\033[0m");
		return (NULL);
	}

	i = 0;

	token = strtok(str, del);
	while (token != NULL)
	{
		tokenList[i] = strdup(token);
		token = strtok(NULL, del);
		i++;
	}

	tokenList[i] = NULL;

	return tokenList;
}
