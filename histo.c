#include "shell.h"

/**
 * get_history_file - gets history file
 * @info: parameter struct
 *
 * Return: allocated string containing history file
 */

char *get_history_file(info_i *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_history - create a file or append to an existing file
 * @info: parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_history(info_i *info)
{
	ssize_t ft;
	char *filename = get_history_file(info);
	list_i *node = NULL;

	if (!filename)
		return (-1);

	ft = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (ft == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, ft);
		_putfd('\n', ft);
	}
	_putfd(BUF_FLUSH, ft);
	close(ft);
	return (1);
}

/**
 * read_history - read history from file
 * @info: parameter struct
 *
 * Return: history count on success, 0 otherwise
 */
int read_history(info_i *info)
{
	int x, last = 0, line_count = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (x = 0; x < fsize; x++)
		if (buf[x] == '\n')
		{
			buf[x] = 0;
			build_history_list(info, buf + last, line_count++);
			last = x + 1;
		}
	if (last != x)
		build_history_list(info, buf + last, line_count++);
	free(buf);
	info->histcount = line_count;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - add entry to history linked list
 * @info: Structure having potential arguments used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history_list(info_i *info, char *buf, int linecount)
{
	list_i *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - renumber history linked list after changes
 * @info: Structure having potential arguments. Used to maintain
 *
 * Return: new histcount
 */
int renumber_history(info_i *info)
{
	list_i *node = info->history;
	int x = 0;

	while (node)
	{
		node->num = x++;
		node = node->next;
	}
	return (info->histcount = x);
}
