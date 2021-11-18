/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:31:44 by cfiora            #+#    #+#             */
/*   Updated: 2021/05/06 20:04:42 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{	
	unsigned char		*str_1;
	unsigned char		*str_2;

	str_1 = (unsigned char *)dst;
	str_2 = (unsigned char *)src;
	if (!n || dst == src)
		return (dst);
	while (n--)
		*str_1++ = *str_2++;
	return (dst);
}
