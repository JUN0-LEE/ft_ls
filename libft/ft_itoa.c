/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:03:41 by julee             #+#    #+#             */
/*   Updated: 2018/08/28 19:54:07 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_num_count(int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int nbr)
{
	long long int	nb;
	char			*str;
	int				i;
	long long int	sign;

	sign = 1;
	if (nbr < 0)
		sign = -1;
	nb = nbr * sign;
	i = ft_num_count(nbr);
	if (sign < 0)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (--i > 0)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (sign < 0)
		str[i] = '-';
	else
		str[i] = nb % 10 + '0';
	return (str);
}
