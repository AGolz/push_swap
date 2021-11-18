/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:32:04 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/19 12:53:50 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	num;
	int			negative;
	int			i;

	num = 0;
	i = ft_skipspace(str);
	negative = 1;
	while (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		negative = -1;
		i++;
	}
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - 48;
		if (num != -2147483648 && num < 0 && negative == -1)
			return (0);
		else if (num != -2147483648 && num < 0)
			return (-1);
		i++;
	}
	return (num * negative);
}
