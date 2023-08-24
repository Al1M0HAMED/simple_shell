#ifndef SHELL_H
#define SHELL_H


/*# needed libraries #*/
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>


#define BUFSIZE 1024
extern char **environ;

/*## functions prototype ##*/
char *_getenv(char *);
char *helper(char *command);
void combine(char *file_path, char *command, char *path_token);
int built(char *command, char *buffer, int *e, int *c);
void prompt(int status);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *str, int len);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
void sigint_handler(int v);
void signal_to_handel(int _signal);
char *check_cmd(char *cmd);
int _excutev(char *arguments[], char *buffer, char *, int);
int _errout(char *argv, int argc, char *command);

#endif
