/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:26:44 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/19 13:19:17 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnbr(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

static char	*ft_plus(int n, int len)
{
	char	*str;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

static char	*ft_minus(int n, int len)
{
	char	*str;

	str = malloc(len + 2);
	if (!str)
		return (NULL);
	len++;
	str[len] = '\0';
	len--;
	str[0] = '-';
	while (len > 0)
	{
		str[len] = '0' - n % 10;
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_cnbr(n);
	if (n >= 0)
	{
		str = ft_plus(n, len);
		return (str);
	}
	else
		str = ft_minus(n, len);
	return (str);
}
