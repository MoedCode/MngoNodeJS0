#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;
void non_int(char **cmd, char **args);
void tokenize_interactive_mode(char **cmd, char ***args);
char *_getEnv(char *path);
void free_double_arr(char **args);
char **tokenize_string(char *path, char *del);
char ***tokenize_non_int(char **cmd, char **args);
void free_3d_arr(char ***args);
void print3d_arr(char ***threeD_arr);
#endif