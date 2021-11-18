/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 01:23:35 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/11 22:02:44 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str_1, const char *str_2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && *str_1 == *str_2 && *str_1 != '\0' && *str_2 != '\0')
	{
		str_1++;
		str_2++;
	}
	return ((unsigned char)*str_1 - (unsigned char)*str_2);
}
