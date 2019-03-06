/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:28:38 by julee             #+#    #+#             */
/*   Updated: 2018/10/23 15:22:28 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		cmp_alpha(t_vec *filedata, int n, int i, int largest)
{
	int		l;
	int		r;

	l = 2 * i + 1;
	r = 2 * i + 2;
	if (g_flag[3] != 'r')
	{
		if (l < n &&
			ft_strcmp(filedata[l].filename, filedata[largest].filename) > 0)
			largest = l;
		if (r < n &&
			ft_strcmp(filedata[r].filename, filedata[largest].filename) > 0)
			largest = r;
	}
	else if (g_flag[3] == 'r')
	{
		if (l < n &&
			ft_strcmp(filedata[l].filename, filedata[largest].filename) < 0)
			largest = l;
		if (r < n &&
			ft_strcmp(filedata[r].filename, filedata[largest].filename) < 0)
			largest = r;
	}
	return (largest);
}

int		cmp_time_3(t_vec *filedata, int n, int i, int largest)
{
	int		l;
	int		r;

	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l < n && (filedata[l].mtime - filedata[largest].mtime) == 0)
	{
		if (filedata[l].nanosec - filedata[largest].nanosec > 0)
			largest = l;
		else if (filedata[l].nanosec - filedata[largest].nanosec == 0 &&
		ft_strcmp(filedata[l].filename, filedata[largest].filename) < 0)
			largest = l;
	}
	if (r < n && (filedata[r].mtime - filedata[largest].mtime) == 0)
	{
		if (filedata[r].nanosec - filedata[largest].nanosec > 0)
			largest = r;
		else if (filedata[r].nanosec - filedata[largest].nanosec == 0 &&
		ft_strcmp(filedata[r].filename, filedata[largest].filename) < 0)
			largest = r;
	}
	return (largest);
}

int		cmp_time_2(t_vec *filedata, int n, int i, int largest)
{
	int		l;
	int		r;

	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l < n && (filedata[l].mtime - filedata[largest].mtime) == 0)
	{
		if (filedata[l].nanosec - filedata[largest].nanosec < 0)
			largest = l;
		else if (filedata[l].nanosec - filedata[largest].nanosec == 0 &&
		ft_strcmp(filedata[l].filename, filedata[largest].filename) > 0)
			largest = l;
	}
	if (r < n && (filedata[r].mtime - filedata[largest].mtime) == 0)
	{
		if (filedata[r].nanosec - filedata[largest].nanosec < 0)
			largest = r;
		else if (filedata[r].nanosec - filedata[largest].nanosec == 0 &&
		ft_strcmp(filedata[r].filename, filedata[largest].filename) > 0)
			largest = r;
	}
	return (largest);
}

int		cmp_time(t_vec *filedata, int n, int i, int largest)
{
	int	l;
	int	r;

	l = 2 * i + 1;
	r = 2 * i + 2;
	if (g_flag[3] != 'r')
	{
		if (l < n && (filedata[l].mtime - filedata[largest].mtime) < 0)
			largest = l;
		if (r < n && (filedata[r].mtime - filedata[largest].mtime) < 0)
			largest = r;
		largest = cmp_time_2(filedata, n, i, largest);
	}
	else if (g_flag[3] == 'r')
	{
		if (l < n && (filedata[l].mtime - filedata[largest].mtime) > 0)
			largest = l;
		if (r < n && (filedata[r].mtime - filedata[largest].mtime) > 0)
			largest = r;
		largest = cmp_time_3(filedata, n, i, largest);
	}
	return (largest);
}
