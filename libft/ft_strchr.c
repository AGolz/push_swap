/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:30:07 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/19 13:41:22 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;

	i = 0;
	if (str[i] == ch)
		return ((char *)&str[i]);
	while (str[i] != 0)
	{
		if (str[i + 1] == ch)
			return ((char *)&str[i + 1]);
		i++;
	}
	return (NULL);
}
