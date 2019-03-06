/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:02:32 by julee             #+#    #+#             */
/*   Updated: 2018/10/23 15:25:41 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	freer2(t_vec **filedata, int i)
{
	if ((*filedata)[i].filename != NULL)
	{
		free((*filedata)[i].filename);
		(*filedata)[i].filename = NULL;
	}
	if ((*filedata)[i].linkname != NULL)
	{
		free((*filedata)[i].linkname);
		(*filedata)[i].linkname = NULL;
	}
	if ((*filedata)[i].usrname != NULL)
	{
		free((*filedata)[i].usrname);
		(*filedata)[i].usrname = NULL;
	}
	if ((*filedata)[i].grpname != NULL)
	{
		free((*filedata)[i].grpname);
		(*filedata)[i].grpname = NULL;
	}
	if ((*filedata)[i].path != NULL)
	{
		free((*filedata)[i].path);
		(*filedata)[i].path = NULL;
	}
}

void	freer(t_vec **filedata)
{
	int	i;

	i = -1;
	if ((*filedata) != NULL)
	{
		while (++i < (*filedata)->size)
			freer2(filedata, i);
		free(*filedata);
		*filedata = NULL;
	}
}

void	sort_n_print(t_vec **filedata, char *path)
{
	if (*filedata != NULL)
	{
		heap_sort(*filedata);
		print_data(*filedata);
		if (g_flag[1] == 'R')
			recursive_ls(*filedata, path);
	}
	if (*filedata != NULL)
		freer(filedata);
}

void	ft_ls(char *path)
{
	t_vec			*filedata;
	t_dir			dir;
	int				i;

	if ((filedata = malloc_list(sizeof_dir(path))) == NULL)
	{
		ft_printf("ft_ls: %s: %s\n", path, strerror(errno));
		return ;
	}
	if ((dir.dirp = opendir(path)) == NULL)
		return ;
	i = 0;
	while ((dir.dp = readdir(dir.dirp)) != NULL)
	{
		filedata[i].filename = ft_strdup(dir.dp->d_name);
		dir.path_name = join_path(path, dir.dp->d_name);
		filedata[i].path = ft_strdup(path);
		if ((lstat(dir.path_name, &(dir.buf)) != -1))
			put_filedata(&filedata[i], dir.buf);
		i++;
		free(dir.path_name);
	}
	closedir(dir.dirp);
	if (filedata != NULL)
		sort_n_print(&filedata, path);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		ft_ls(".");
	else if (argv[i][0] == '-')
	{
		if (recog_flag(argv[i++]))
		{
			if (argc == 2)
				ft_ls(".");
			else
				while (i < argc)
					ft_ls(argv[i++]);
		}
	}
	else
		while (i < argc)
			ft_ls(argv[i++]);
	return (0);
}
