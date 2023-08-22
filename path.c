#include "main.h"
/**
 * check_cmd - this fucntion checks if command exist in PATH.
 * @command: is the name of the program we need to know if it exist.
 * Return: NULL if doesn't exist the path if the program found.
 * mohamed37222721@gmail.com.
 */
char *check_cmd(char *command)
{
	char *path_token, *path, *file_path, *path_copy;
	struct stat buffer;

	if ((helper(command)) != NULL)
		return (_strdup(helper(command)));
	{
		path = _getenv("PATH");
		if (path)
		{
			path_copy = _strdup(path);
			if (path_copy == NULL)
				return (NULL);
			path_token = strtok(path_copy, ":");
			while (path_token != NULL)
			{
				file_path = malloc(_strlen(path_token) + _strlen(command) + 2);
				if (file_path == NULL)
				{
					free(path_copy);
					return (NULL);
				}
				combine(file_path, command, path_token);
				if (stat(file_path, &buffer) == 0 && S_ISREG(buffer.st_mode) &&
						(buffer.st_mode & S_IXUSR))
				{
					free(path_copy);
					return (file_path);
				}
				free(file_path);
				path_token = strtok(NULL, ":");
			}
			free(path_copy);
		}
		if (stat(command, &buffer) == 0)
		{
			return (_strdup(command));
		}
	}
	return (NULL);
}
/**
 * combine - this function combines a command with it's path.
 * @file_path: this is the full string path + command.
 * @command: this is the command.
 * @path_token: this is the path string.
 * Return: mohamed37222721@gmail.com.
 */
void combine(char *file_path, char *command, char *path_token)
{
		_strcpy(file_path, path_token);
		_strcat(file_path, "/");
		_strcat(file_path, command);
}
/**
 * helper - mohamed37222721@gmail.com.
 * @command: mohamed37222721@gmail.com.
 * Return: mohamed37222721@gmail.com.
 */
char *helper(char *command)
{
	struct stat buffer;

	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &buffer) == 0 && S_ISREG(buffer.st_mode) &&
				(buffer.st_mode & S_IXUSR))
		return (command);
	}
	return (NULL);
}
/**
 * _getenv - Gets The Value Of Enviroment Variable By Name
 * @name: Environment Variable Name
 * Return: The Value of the Environment Variable Else NULL.
 */
char *_getenv(char *name)
{
	size_t name_len = _strlen(name);
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(name, *env, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (*env + name_len + 1);
		}
	}
	return (NULL);
}

