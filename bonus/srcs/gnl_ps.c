/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_ps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:43:22 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/19 13:37:47 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/get_next_line_ps.h"

static int	ft_to_line(char **line, char **tmp, int ret)
{
	char	*tmp_b;
	int		n_ind;

	n_ind = 0;
	while ((*tmp)[n_ind] != '\0' && (*tmp)[n_ind] != '\n')
		n_ind++;
	if ((*tmp)[0] == '\0' && ret == 0)
	{
		ft_strdel(tmp);
		return (0);
	}
	*line = ft_strsub(*tmp, 0, n_ind);
	if (*line == NULL)
		return (-1);
	tmp_b = ft_strsub(*tmp, n_ind + 1, ft_strlen(*tmp) - n_ind);
	if (tmp_b == NULL)
		return (-1);
	free(*tmp);
	*tmp = tmp_b;
	return (1);
}

static int	ft_free_tmp(char **tmp)
{
	free(*tmp);
	return (-1);
}

static char	**buff_fill(char **tmp, const int fd)
{
	if (tmp[fd] == NULL)
	{
		tmp[fd] = ft_strnew(0);
		if (tmp[fd] == NULL)
			return (NULL);
		return (tmp);
	}
	return (tmp);
}

int	get_next_line_ps(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*tmp[MAX_FD + 1];
	char			*tmp_b;
	int				ret;

	if (line == NULL || fd < 0 || fd > MAX_FD)
		return (-1);
	if (buff_fill(tmp, fd) == NULL)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		tmp_b = ft_strjoin(tmp[fd], buf);
		if (tmp_b == NULL)
			return (ft_free_tmp(&tmp[fd]));
		free(tmp[fd]);
		tmp[fd] = tmp_b;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	return (ft_to_line(line, &tmp[fd], ret));
}
