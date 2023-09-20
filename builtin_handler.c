#include "shell.h"

/**
  * built_in_handler - It choose a correct function depending upon the input
  * @_args: an array with inputs
  * @env: an environmental variable
  *
  * Return: a result of calling the function of the struct
  */
int built_in_handler(char **_args, char **env)
{
	int x = 0;
	tpe_bui arr_bu[] = {
		{"cd", fun_cd		},
		{"pwd", fun_pwd		},
		{"exit", fun_exit	},
		{"env", fun_envi	}
	};
	for (; x < 4; x++)
		if (_strcmp(arr_bu[x].s, _args[0]) == 0)
		{
			if (_strcmp(arr_bu[x].s, "env") == 0)
				return (arr_bu[x].fun(env));
			else
				return (arr_bu[x].fun(_args));
		}
	return (1);

}

