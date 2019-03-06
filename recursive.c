/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 18:28:30 by julee             #+#    #+#             */
/*   Updated: 2018/10/23 15:25:50 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursive_ls(t_vec *filedata, char *path)
{
	int		size;
	int		i;
	char	*path_name;

	i = -1;
	size = filedata->size;
	while (++i < size)
	{
		if (ft_strcmp(filedata[i].filename, ".")
				&& ft_strcmp(filedata[i].filename, ".."))
		{
			if (g_flag[2] == 'a' || filedata[i].filename[0] != '.')
			{
				path_name = join_path(path, filedata[i].filename);
				if (S_ISDIR(filedata[i].filemode))
				{
					ft_printf("\n%s:\n", path_name);
					ft_ls(path_name);
				}
				free(path_name);
			}
			else if (g_flag[2] != 'a' && filedata[i].filename[0] == '.')
				continue;
		}
	}
}
