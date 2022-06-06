#include "header.h"

/**
 * approve_open_dir - confirms whether we want to open a dir (for -R)
 * @dir: file node of dir
 * @flags: flags
 * Return: 1 if opening approved | 0 if reject
 **/
bool approve_open_dir(file_node_t *dir, ls_config_t *flags)
{
	char *d;

	if (S_ISDIR(dir->info->st_mode) == false)
		return (false);

	if (dir->name[0] == '.')
	{
		if (IS_PARENT_DIR(dir->name) || IS_CWD(dir->name))
			return (false);
		if (flags->dot == false && flags->dot_alt == false)
			return (false);
	}
	d = dir->name + len(dir->name) - 1;
	if (d - 2 >= dir->name && (IS_CWD(d) || IS_PARENT_DIR((d - 1))))
		return (false);

	return (true);
}
