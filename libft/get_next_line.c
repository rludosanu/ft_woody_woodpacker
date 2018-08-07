/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:40:55 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/27 09:05:24 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int const fd, char **line)
{
	static char	*c[20] = {NULL};
	int			j[4];

	init_j(j);
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	j[3] = search_index(c, fd);
	if (c[j[3]] == NULL)
	{
		c[j[3]] = (char*)malloc(sizeof(char) * (BUFF_SIZE + 3));
		if ((j[2] = read_gnl(c[j[3]], fd)) <= 0)
			return (j[2]);
	}
	*line = NULL;
	while (j[2] > 0 && ft_strchr(c[j[3]], '\n') == NULL)
	{
		*line = ft_strjoin(*line, c[j[3]]);
		if ((j[2] = read_gnl(c[j[3]], fd)) < 0)
			return (j[2]);
	}
	while (c[j[3]][j[1]] != '\n' && c[j[3]][j[1]])
		j[1]++;
	if (j[2] > 0)
		*line = ft_strjoin(*line, ft_strsub(c[j[3]], 0, j[1]));
	return (verif_end(j, c));
}

void			init_j(int *j)
{
	j[0] = -1;
	j[1] = 0;
	j[2] = BUFF_SIZE;
	j[3] = -1;
}

int				search_index(char **c, int fd)
{
	int	j;

	j = -1;
	while (++j < 20)
	{
		if (c[j] != NULL)
		{
			if (c[j][BUFF_SIZE + 2] == fd)
				return (j);
		}
	}
	j = -1;
	while (++j < 20)
		if (c[j] == NULL)
			return (j);
	return (j);
}

int				read_gnl(char *c, int fd)
{
	int		ret;
	char	buf[BUFF_SIZE];

	if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
		return (ret);
	ft_strcpy(c, buf);
	c[ret] = '\0';
	c[BUFF_SIZE + 2] = fd;
	return (ret);
}

int				verif_end(int *i, char **c)
{
	if (!i[2])
	{
		i[2] = ft_strlen(c[i[3]]);
		c[i[3]] = NULL;
		return (i[2]);
	}
	if (c[i[3]][i[1]] == '\n')
	{
		ft_memcpy(c[i[3]], &c[i[3]][i[1] + 1], BUFF_SIZE + 2);
		c[i[3]][BUFF_SIZE - i[1]] = '\0';
		return (1);
	}
	return (0);
}
