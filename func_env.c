#include "shell.h"

/**
  * func_env - A function will search for a PATH
  * @_com: A command to search in a PATH
  * @env: an array of arrays contain a path
  * @no_path:  To counts a number of elements inside path variable
  *
  * Return: strings contains a path or NULL
  */
char *func_env(char *_com, char **env, int *no_path)
{
	int l = 0;
	char *_delim = "=:";
	char *_slash = "/";
	char *key = "PATH";
	char *concat_dir = NULL;
	char *concat_param = NULL;
	char *_temp = NULL;
	char *_token = NULL;

	while (env[l])
	{
		_temp = _strdup(env[l]);
		_token = strtok(_temp, _delim);
		if (_strcmp(_token, key) == 0)
		{
			while (_token)
			{
				*no_path = *no_path + 1;
				concat_dir = str_concat(_token, _slash);
				concat_param = str_concat(concat_dir, _com);
				if (access(concat_param, F_OK) == 0)
				{
					free(_temp);
					_temp = NULL;
					free(concat_dir);
					return (concat_param);
				}
				free(concat_dir);
				free(concat_param);
				_token = strtok(NULL, _delim);
				concat_param = NULL;
				concat_dir = NULL;
			}
		_token = NULL;
		}
		free(_temp);
		_temp = NULL;
		l++;
	}
	return (NULL);
}

/**
 *_strdup - To creates a copy of a given array
 *@str: an array to be copied
 *
 *Return: pointers to the array
 */
char *_strdup(char *str)
{
	int l;
	int k;
	char *t;

	l = 0;
	if (str == NULL)
		return (NULL);
	while (str[l])
	{
		l++;
	}
	l++;
	t = (char *) malloc(l * sizeof(char));
	if (t == NULL)
		return (NULL);
	for (k = 0; k < l; k++)
	{
		t[k] = str[k];
	}
	return (t);
}

/**
 *str_concat - To concatenate two strings
 *@s1: A first string
 *@s2: A second string
 *
 *Return: pointers to a concatenated array
 */
char *str_concat(char *s1, char *s2)
{
	int l = 0, j = 0, k = 0, l = 0;
	char *t;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[l])
	{
		l++;
	}
	while (s2[j])
	{
		j++;
	}
	j++;
	t = (char *) malloc((l + j) * sizeof(char));
	if (t == NULL)
		return (NULL);
	for (k = 0; k < l; k++)
	{
		t[k] = s1[k];
	}
	for (l = 0; l < j; l++)
	{
		t[l + l] = s2[l];
	}
	return (t);
}

