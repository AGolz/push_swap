/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:24:54 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/15 07:13:33 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str_1, const char *str_2)
{
	int				i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	ns1 = (unsigned char *)str_1;
	ns2 = (unsigned char *)str_2;
	i = 0;
	while ((ns1[i] && ns2[i]) && (ns1[i] == ns2[i]))
	{
		i++;
	}
	return (ns1[i] - ns2[i]);
}
