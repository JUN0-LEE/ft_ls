/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 22:12:45 by julee             #+#    #+#             */
/*   Updated: 2018/10/22 23:08:24 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wchar_conv(va_list ap)
{
	wchar_t	wc;

	wc = va_arg(ap, wchar_t);
	uni_to_utf(wc);
}

void	ft_char_conv(va_list ap)
{
	unsigned char c;

	if (g_fwpl.conv == 'C')
	{
		ft_wchar_conv(ap);
		return ;
	}
	c = (unsigned char)va_arg(ap, int);
	if (g_fwpl.flag[2] == '-')
	{
		ft_putchar_g_i(c);
		ft_print_pad(' ', g_fwpl.width - 1);
	}
	else if (g_fwpl.flag[2] == '?')
	{
		ft_print_pad(' ', g_fwpl.width - 1);
		ft_putchar_g_i(c);
	}
}
