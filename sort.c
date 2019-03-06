/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 18:18:16 by julee             #+#    #+#             */
/*   Updated: 2018/10/23 15:26:14 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap_value(t_vec *a, t_vec *b)
{
	t_vec tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	heapify(t_vec *filedata, int n, int i)
{
	int		largest;

	largest = i;
	if (g_flag[4] != 't')
		largest = cmp_alpha(filedata, n, i, largest);
	else if (g_flag[4] == 't')
		largest = cmp_time(filedata, n, i, largest);
	if (largest != i)
	{
		swap_value(&filedata[i], &filedata[largest]);
		heapify(filedata, n, largest);
	}
}

void	heap_sort(t_vec *filedata)
{
	int	i;
	int	size;

	size = filedata->size;
	i = size / 2 - 1;
	while (i >= 0)
	{
		heapify(filedata, size, i);
		i--;
	}
	i = size - 1;
	while (i >= 0)
	{
		swap_value(&filedata[0], &filedata[i]);
		heapify(filedata, i, 0);
		i--;
	}
	filedata->size = size;
}
