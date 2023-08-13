#ifndef MAIN_H
#define MAIN_H

/**/
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

/**/
void shell_loop(void);
int _strcmp(char *s1, char *s2);
int _excute(char *cmd, char **args);
char *_strcat(char *dest, char *src);

#endif
