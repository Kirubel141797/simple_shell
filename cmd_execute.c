#include "main.h"

/**
 * is_cdir - check ":" if is in current directory.
 * @path: type character pointer char.
 * @i: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */
int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * _which - locate  command
 *
 * @cmd: command name
 * @_environ: environment variable
 * Return: location of the command.
 */
char *_which(char *cmd, char **_environ)
{
	char *path, *ptr_path, *token_path, *dire;
	int len_dir, len_cmd, x;
	struct stat st;

	path = _getenv("PATH", _environ);
	if (path)
	{
		ptr_path = _strdup(path);
		len_cmd = _strlen(cmd);
		token_path = _strtok(ptr_path, ":");
		x = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &x))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(token_path);
			dire = malloc(len_dir + len_cmd + 2);
			_strcpy(dire, token_path);
			_strcat(dire, "/");
			_strcat(dire, cmd);
			_strcat(dire, "\0");
			if (stat(dire, &st) == 0)
			{
				free(ptr_path);
				return (dire);
			}
			free(dire);
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_executable - determine if it is an executable
 *
 * @datash: data structure
 * Return: 0 if is not an executable, other number if it does
 */
int is_executable(data_shell *datash)
{
	struct stat st;
	int x;
	char *input;

	input = datash->args[0];
	for (x = 0; input[x]; x++)
	{
		if (input[x] == '.')
		{
			if (input[x + 1] == '.')
				return (0);
			if (input[x + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && x != 0)
		{
			if (input[x + 1] == '.')
				continue;
			x++;
			break;
		}
		else
			break;
	}
	if (x == 0)
		return (0);

	if (stat(input + x, &st) == 0)
	{
		return (x);
	}
	get_error(datash, 127);
	return (-1);
}

/**
 * check_error_cmd - verify if user has permissions to access
 *
 * @dir: destination to directory
 * @datash: data structure
 * Return: 1 if there is an error, 0 if not
 */
int check_error_cmd(char *dir, data_shell *datash)
{
	if (dir == NULL)
	{
		get_error(datash, 127);
		return (1);
	}

	if (_strcmp(datash->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_error(datash, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			get_error(datash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_exec - execute command lines
 *
 * @datash: data relevant (args and input)
 * Return: 1 on success.
 */
int cmd_exec(data_shell *datash)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int execu;
	char *dire;
	(void) wpd;

	execu = is_executable(datash);
	if (execu == -1)
		return (1);
	if (execu == 0)
	{
		dire = _which(datash->args[0], datash->_environ);
		if (check_error_cmd(dire, datash) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (execu == 0)
			dire = _which(datash->args[0], datash->_environ);
		else
			dire = datash->args[0];
		execve(dir + exec, datash->args, datash->_environ);
	}
	else if (pd < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	datash->status = state / 256;
	return (1);
}
