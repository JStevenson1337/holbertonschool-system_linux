#include "header.h"

/**
 * get_user - gets user id in string format
 * @buffer: buffer where user name is stored
 * @user_id: user id
 **/
void get_user(char *buffer, uid_t user_id)
{
	struct passwd *user_info = getpwuid(user_id);

	if (user_info && user_info->pw_name && user_info->pw_name[0])
		copy_string(buffer, user_info->pw_name);
	else
		sprintf(buffer, "%u", user_id);
}

/**
 * get_time - gets time string for ls -l
 * @buffer: buffer where time string is stored
 * @time_val: time value
 **/
void get_time(char *buffer, time_t time_val)
{
	char *time_string;
	int i, j, colon_count = 0;

	time_string = ctime(&time_val);

	for (i = 0, j = 4; colon_count < 2; i++, j++)
	{
		buffer[i] = time_string[j];
		if (buffer[i] == ':')
			colon_count++;
	}
	buffer[i - 1] = '\0';
}

/**
 * get_group - gets group name
 * @buffer: buffer where group name is stored
 * @group_id: group id
 **/
void get_group(char *buffer, gid_t group_id)
{
	struct group *group_info = getgrgid(group_id);

	if (group_info && group_info->gr_name && group_info->gr_name[0])
		copy_string(buffer, group_info->gr_name);
	else
		sprintf(buffer, "%u", group_id);
}
/**
 * get_permissions - creates a string detailing file permissions (for ls -l)
 * @buffer: buffer where string is placed
 * @mode: the file's mode, used to extract permissions
 **/
void get_permissions(char *buffer, mode_t mode)
{
	buffer[0] = get_type(mode);
	buffer[1] = mode & S_IRUSR ? 'r' : '-';
	buffer[2] = mode & S_IWUSR ? 'w' : '-';
	buffer[3] = mode & S_IXUSR ? 'x' : '-';
	buffer[4] = mode & S_IRGRP ? 'r' : '-';
	buffer[5] = mode & S_IWGRP ? 'w' : '-';
	buffer[6] = mode & S_IXGRP ? 'x' : '-';
	buffer[7] = mode & S_IROTH ? 'r' : '-';
	buffer[8] = mode & S_IWOTH ? 'w' : '-';
	buffer[9] = mode & S_IXOTH ? 'x' : '-';
	buffer[10] = '\0';
}

/**
 * get_type - get file type
 * @mode: mode
 * Return: letter representing file type
 **/
char get_type(mode_t mode)
{
	if (S_ISREG(mode))
		return ('-');
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISFIFO(mode))
		return ('p');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISSOCK(mode))
		return ('s');
	return ('-');
}
