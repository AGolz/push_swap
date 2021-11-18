/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 22:57:11 by cfiora            #+#    #+#             */
/*   Updated: 2021/05/11 02:14:40 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char			*ptr;

	ptr = NULL;
	while (*str)
	{
		if (*str == (char)ch)
			ptr = (char *)str;
		str++;
	}
	if ((char)ch == *str)
		return ((char *)str);
	return (ptr);
}
