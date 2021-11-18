/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 03:20:28 by cfiora            #+#    #+#             */
/*   Updated: 2021/05/09 01:15:10 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	char			*dst;
	unsigned int	i;
	unsigned int	sum;

	sum = number * size;
	dst = malloc(sum);
	if (!dst)
		return (NULL);
	i = 0;
	while (sum--)
	{
		dst[i] = 0;
		i++;
	}
	return ((void *)dst);
}
