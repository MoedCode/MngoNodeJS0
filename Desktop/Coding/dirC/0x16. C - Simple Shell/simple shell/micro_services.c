#include "main.h"
char *_getEnv(char *path)
{
	char **s = environ;

	while (*s != NULL)
	{
		if (strstr(*s, path))
			return *s;

		s++;
	}

	return NULL;
}
