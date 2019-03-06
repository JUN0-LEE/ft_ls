/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:47:42 by julee             #+#    #+#             */
/*   Updated: 2018/08/06 20:48:26 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_forward(char const *s, size_t j)
{
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	return (j);
}

static int		ft_backward(char const *s, size_t i)
{
	while (s[(int)i] == ' ' || s[(int)i] == '\n' || s[(int)i] == '\t')
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s == NULL)
		return (NULL);
	i = ft_strlen((const char *)s) - 1;
	i = ft_backward(s, i);
	if ((int)i == -1)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	j = 0;
	j = ft_forward(s, j);
	str = (char *)malloc(sizeof(char) * (i - j + 2));
	if (!str)
		return (NULL);
	str[i - j + 1] = '\0';
	k = 0;
	while (j <= i)
		str[k++] = s[j++];
	return (str);
}
