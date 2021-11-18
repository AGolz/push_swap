/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:41:05 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/13 23:40:34 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;

	if (n == 0)
		return (0);
	ptr_1 = (unsigned char *)arr1;
	ptr_2 = (unsigned char *)arr2;
	i = 0;
	while (*ptr_1 == *ptr_2 && ++i < n)
	{
		ptr_1++;
		ptr_2++;
	}
	return ((int)(*ptr_1 - *ptr_2));
}
