/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:16:53 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/18 18:58:38 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_2(char *line, char **tmp, int k, char c)
{
	int	i;

	*tmp = malloc(k);
	if (!(*tmp))
		return (-1);
	i = -1;
	while (++i < 1 - 2)
		(*tmp)[i] = line[i];
	(*tmp)[i] = c;
	(*tmp)[i + 1] = 0;
	return (1);
}

int	get_next_line(char **line)
{
	int		k;
	int		r;
	char	c;
	char	*tmp;

	k = 1;
	r = 0;
	*line = malloc(1);
	if (!(*line))
		return (-1);
	(*line)[0] = 0;
	while (1)
	{
		r = read(0, &c, 1);
		if (r == 0 || c == '\n')
			break ;
		if (gnl_2(*line, &tmp, ++k, c) == -1)
		{
			free(*line);
			return (-1);
		}
		free(*line);
		*line = tmp;
	}
	return (r);
}
