/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 23:42:50 by cfiora            #+#    #+#             */
/*   Updated: 2021/05/06 23:44:49 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *strB, const char *strA)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (strA[0] == '\0')
		return ((char *)strB);
	while (strB[i])
	{
		while (strB[i] == strA[j] || strA[j] == '\0')
		{
			i++;
			j++;
			if (strA[i] == '\0')
				return ((char *)&strB[i - j]);
		}
		i++;
	}
	return (NULL);
}
