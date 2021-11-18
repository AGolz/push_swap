/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:59:26 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/19 13:42:39 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_w_count(char const *str, char c)
{
	size_t	i;
	size_t	ct;

	i = 0;
	ct = 0;
	while (str[i] != 0)
	{
		if ((i == 0 || str[i - 1] == c) && str[i] != c)
			ct++;
		i++;
	}
	return (ct);
}

static size_t	ft_c_count(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i] != 0)
		i++;
	return (i);
}

static char	**ft_split_free(char **buf, int j)
{
	while (j >= 0)
	{
		free(buf[j]);
		j--;
	}
	free(buf);
	return (NULL);
}

char	**ft_strsplit(char const *str, char c)
{
	size_t	i;
	size_t	j;
	char	**buf;

	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	buf = (char **)malloc(sizeof(char *) * (ft_w_count(str, c) + 1));
	if (buf == NULL)
		return (NULL);
	while (str[i] != 0)
	{
		if ((i == 0 || str [i - 1] == c) && str[i] != c)
		{
			buf[j] = ft_strsub(str, i, ft_c_count(&str[i], c));
			if (buf[j] == NULL)
				return (ft_split_free(buf, j));
			j++;
		}
		i++;
	}
	buf[j] = NULL;
	return (buf);
}
