/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:59:23 by julee             #+#    #+#             */
/*   Updated: 2018/08/09 15:01:41 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_arraycpy(char **array, char const *s, char c)
{
	int i;
	int w;
	int h;

	i = 0;
	h = 0;
	while (s[i] != '\0')
	{
		while ((char)s[i] == c && (char)s[i] != '\0')
			i++;
		if ((char)s[i] == '\0')
			break ;
		w = 0;
		while ((char)s[i] != c && (char)s[i] != '\0')
		{
			array[h][w] = (char)s[i];
			i++;
			w++;
		}
		h++;
	}
	return (array);
}

static char			**ft_char_count(char const *s, char c, char **array)
{
	int i;
	int w;
	int h;

	i = 0;
	h = 0;
	while (s[i] != '\0')
	{
		while ((char)s[i] == c && (char)s[i] != '\0')
			i++;
		if ((char)s[i] == '\0')
			break ;
		w = 0;
		while ((char)s[i] != c && (char)s[i] != '\0')
		{
			i++;
			w++;
		}
		array[h] = (char *)malloc(sizeof(char) * (w + 1));
		if (!array[h])
			return (NULL);
		array[h][w] = '\0';
		h++;
	}
	return (array);
}

static int			ft_word_count(char const *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while ((char)s[i] == c)
		{
			i++;
			if ((char)s[i] == '\0')
				return (k);
		}
		while ((char)s[i] != c)
		{
			i++;
			if ((char)s[i] == '\0')
				return (k + 1);
		}
		k++;
	}
	return (k);
}

char				**ft_strsplit(char const *s, char c)
{
	int		height;
	char	**array;

	if (!s || !c)
		return (NULL);
	height = ft_word_count(s, c) + 1;
	array = (char **)malloc(sizeof(char *) * height);
	if (!array)
		return (NULL);
	array[height - 1] = NULL;
	array = ft_char_count(s, c, array);
	array = ft_arraycpy(array, s, c);
	return (array);
}
