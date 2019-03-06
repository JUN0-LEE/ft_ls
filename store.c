/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:53:20 by julee             #+#    #+#             */
/*   Updated: 2018/10/23 15:26:28 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sizeof_dir(char *path)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				size;

	if (!(dirp = opendir(path)))
		return (0);
	size = 0;
	while ((dp = readdir(dirp)) != NULL)
		size++;
	closedir(dirp);
	return (size);
}

t_vec	*malloc_list(int size)
{
	t_vec	*filedata;

	filedata = NULL;
	if (size != 0)
	{
		if (!(filedata = (t_vec *)malloc(sizeof(t_vec) * size)))
			return (NULL);
	}
	else if (size == 0)
		return (NULL);
	filedata->size = size;
	return (filedata);
}

void	put_filedata(t_vec *filedata, struct stat buf)
{
	struct passwd	*my_passwd;
	struct group	*my_group;

	my_passwd = getpwuid(buf.st_uid);
	if (my_passwd != NULL)
		filedata->usrname = ft_strdup(my_passwd->pw_name);
	my_group = getgrgid(buf.st_gid);
	if (my_group != NULL)
		filedata->grpname = ft_strdup(my_group->gr_name);
	filedata->linkname = (char *)malloc(sizeof(char) * 256);
	filedata->linkname[255] = '\0';
	filedata->filemode = buf.st_mode;
	filedata->nlink = buf.st_nlink;
	filedata->filesize = buf.st_size;
	filedata->mtime = buf.st_mtime;
	filedata->nanosec = buf.st_mtimespec.tv_nsec;
	filedata->major_devnum = major(buf.st_rdev);
	filedata->minor_devnum = minor(buf.st_rdev);
	if (g_flag[2] == 'a')
		g_total += buf.st_blocks;
	else if (g_flag[2] != 'a')
		g_total += (filedata->filename[0] == '.') ? 0 : buf.st_blocks;
}

char	*join_path(char *path, char *filename)
{
	char	*pathslash;
	char	*res;

	if (path != NULL && filename != NULL)
	{
		pathslash = ft_strjoin(path, "/");
		res = ft_strjoin(pathslash, filename);
		free(pathslash);
	}
	else
		res = NULL;
	return (res);
}
