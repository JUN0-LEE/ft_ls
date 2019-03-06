/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:29:54 by julee             #+#    #+#             */
/*   Updated: 2018/10/23 15:11:04 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flag_initializer(void)
{
	int		i;

	i = 0;
	while (i < 5)
		g_flag[i++] = '?';
	g_flag[i] = '\0';
}

void	check_flag(char c)
{
	if (c == 'l')
		g_flag[0] = 'l';
	else if (c == 'R')
		g_flag[1] = 'R';
	else if (c == 'a')
		g_flag[2] = 'a';
	else if (c == 'r')
		g_flag[3] = 'r';
	else if (c == 't')
		g_flag[4] = 't';
}

int		recog_flag(char *str)
{
	flag_initializer();
	if (*str == '-')
		str++;
	if (*str == '\0')
	{
		ft_printf("ft_ls: -: No such file or directory\n");
		return (0);
	}
	while (*str == 'l' || *str == 'R' ||
			*str == 'a' || *str == 'r' || *str == 't')
	{
		check_flag(*str);
		str++;
	}
	if (*str != '\0')
	{
		ft_printf("ft_ls: illegal option -- %c\n", *str);
		ft_printf("usage: ft_ls [-lRart] [file ...]\n");
		return (0);
	}
	return (1);
}
