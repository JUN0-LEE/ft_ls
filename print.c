/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 22:20:26 by julee             #+#    #+#             */
/*   Updated: 2018/10/23 15:24:33 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_mode(unsigned short int filemode)
{
	if (S_ISREG(filemode))
		ft_printf("-");
	else if (S_ISLNK(filemode))
		ft_printf("l");
	else if (S_ISDIR(filemode))
		ft_printf("d");
	else if (S_ISCHR(filemode))
		ft_printf("c");
	else if (S_ISBLK(filemode))
		ft_printf("b");
	else if (S_ISFIFO(filemode))
		ft_printf("p");
	else if (S_ISSOCK(filemode))
		ft_printf("s");
	ft_printf((filemode & S_IRUSR) ? "r" : "-");
	ft_printf((filemode & S_IWUSR) ? "w" : "-");
	ft_printf((filemode & S_IXUSR) ? "x" : "-");
	ft_printf((filemode & S_IRGRP) ? "r" : "-");
	ft_printf((filemode & S_IWGRP) ? "w" : "-");
	ft_printf((filemode & S_IXGRP) ? "x" : "-");
	ft_printf((filemode & S_IROTH) ? "r" : "-");
	ft_printf((filemode & S_IWOTH) ? "w" : "-");
	ft_printf((filemode & S_IXOTH) ? "x" : "-");
	ft_printf(" ");
}

void	print_time(long int time)
{
	char	*str;
	char	s[30];
	int		i;
	int		j;

	i = 4;
	j = 0;
	str = ctime(&time);
	while (str[i + 9] != '\0')
		s[j++] = str[i++];
	s[j] = '\0';
	ft_printf("%s ", s);
}

void	print_long_2(t_vec *filedata, int i)
{
	print_mode(filedata[i].filemode);
	ft_printf("%d ", filedata[i].nlink);
	if (filedata[i].usrname != NULL)
		ft_printf("%s ", filedata[i].usrname);
	if (filedata[i].grpname != NULL)
		ft_printf(" %s ", filedata[i].grpname);
	if (S_ISCHR(filedata[i].filemode)
			|| S_ISBLK(filedata[i].filemode))
	{
		ft_printf("%i, ", filedata[i].major_devnum);
		ft_printf("%i ", filedata[i].minor_devnum);
	}
	else
		ft_printf("%lli ", filedata[i].filesize);
	print_time(filedata[i].mtime);
	ft_printf("%s", filedata[i].filename);
}

void	print_long(t_vec *filedata, int i, int size)
{
	char			*path_name;
	long			len;

	while (++i < size)
	{
		if (g_flag[2] == 'a' || filedata[i].filename[0] != '.')
		{
			print_long_2(filedata, i);
			if (S_ISLNK(filedata[i].filemode))
			{
				path_name = join_path(filedata[i].path, filedata[i].filename);
				if ((len = readlink(path_name,
								filedata[i].linkname, 256)) != -1)
				{
					filedata[i].linkname[len] = '\0';
					ft_printf(" -> %s", filedata[i].linkname);
				}
				free(path_name);
			}
			ft_printf("\n");
		}
		else if (g_flag[2] != 'a' && filedata[i].filename[0] == '.')
			continue;
	}
}

void	print_data(t_vec *filedata)
{
	int i;
	int	size;

	i = -1;
	size = filedata->size;
	if (g_flag[0] == 'l')
	{
		ft_printf("total %lld\n", g_total);
		g_total = 0;
		print_long(filedata, i, size);
	}
	else if (g_flag[0] != 'l')
	{
		if (g_flag[2] != 'a')
		{
			while (++i < size)
			{
				if (filedata[i].filename[0] != '.')
					ft_printf("%s\n", filedata[i].filename);
			}
		}
		else if (g_flag[2] == 'a')
			while (++i < size)
				ft_printf("%s\n", filedata[i].filename);
	}
}
