/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:54:50 by julee             #+#    #+#             */
/*   Updated: 2018/10/23 15:22:39 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		nbr_length(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		nbr_length_long(long long int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
