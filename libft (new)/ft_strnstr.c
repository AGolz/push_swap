/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 00:35:49 by cfiora            #+#    #+#             */
/*   Updated: 2021/05/13 01:53:13 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	slen;
	unsigned int	i;

	if (!*little)
		return ((char *)big);
	slen = 0;
	while (big[slen] != '\0' && (size_t)slen < len)
	{
		if (big[slen] == little[0])
		{
			i = 1;
			while (little[i] != '\0' && big[slen + i] == little[i] && \
					(size_t)(slen + i) < len)
				++i;
			if (little[i] == '\0')
				return ((char *)&big[slen]);
		}
		++slen;
	}
	return (NULL);
}
