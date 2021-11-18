/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ps.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 01:42:44 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/20 22:22:41 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_PS_H
# define GET_NEXT_LINE_PS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "checker.h"
# include  "push_swap.h"

# define BUFF_SIZE 50
# define MAX_FD 4864

int	get_next_line_ps(const int fd, char **line);

#endif