#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s1 = "string1", *s2 = "string1";

    printf("strcomp s1 s2 : %d\n", strcmp(s1, s2));
    if (!strcmp(s1, s2))
        puts("Equal\n");
}