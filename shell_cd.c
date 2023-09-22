#include "main.h"

/**
 * cd_shell - change current directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int cd_shell(data_shell *datash)
{
	char *dire;
	int ishome, ishome2, isddash;

	dire = datash->args[1];

	if (dire != NULL)
	{
		ishome = _strcmp("$HOME", dire);
		ishome2 = _strcmp("~", dire);
		isddash = _strcmp("--", dir);
	}

	if (dire == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_strcmp("-", dire) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_strcmp(".", dire) == 0 || _strcmp("..", dire) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
