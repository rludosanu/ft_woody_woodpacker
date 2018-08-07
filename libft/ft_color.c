/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 09:45:45 by cdrouet           #+#    #+#             */
/*   Updated: 2017/04/05 15:05:37 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	**init_color(void)
{
	char	**ptr;
	int		i;

	ptr = (char**)malloc(sizeof(char*) * 9);
	i = -1;
	while (++i < 9)
		ptr[i] = ft_strnew(8);
	ptr[0] = ft_strcpy(ptr[0], "noir");
	ptr[1] = ft_strcpy(ptr[1], "rouge");
	ptr[2] = ft_strcpy(ptr[2], "vert");
	ptr[3] = ft_strcpy(ptr[3], "jaune");
	ptr[4] = ft_strcpy(ptr[4], "bleu");
	ptr[5] = ft_strcpy(ptr[5], "rose");
	ptr[6] = ft_strcpy(ptr[6], "cyan");
	ptr[7] = ft_strcpy(ptr[7], "gris");
	ptr[8] = ft_strcpy(ptr[8], "eoc");
	return (ptr);
}

static int	end_ft_color(char *prcolor, char **ptr)
{
	int	i;

	prcolor = ft_strcat(prcolor, "m");
	ft_putstr(prcolor);
	i = -1;
	while (++i < 9)
		free(ptr[i]);
	free(ptr);
	i = ft_strlen(prcolor);
	free(prcolor);
	return (i);
}

int			ft_color(char *color)
{
	char	**ptr;
	int		i;
	char	*prcolor;
	char	*tmp;

	ptr = init_color();
	i = -1;
	while (++i < 9)
		if (!ft_strcmp(color, ptr[i]))
			break ;
	if (i == 9)
		return (0);
	prcolor = ft_strnew(8);
	prcolor = ft_strcpy(prcolor, "\033[");
	if (i < 8)
	{
		tmp = ft_itoa(i + 30);
		prcolor = ft_strcat(prcolor, tmp);
		free(tmp);
	}
	else
		prcolor = ft_strcat(prcolor, "0");
	return (end_ft_color(prcolor, ptr));
}

static void	print_else(char **ptr, int *i)
{
	write(1, &(*ptr)[(*i)], 1);
	(*ptr) = &(*ptr)[(*i) + 1];
	(*i) = -1;
}

void		print_str_color(char *str)
{
	int		i;
	char	*ptr;
	char	*secur;
	char	*tmp;

	ptr = ft_strjoin("", str);
	secur = ptr;
	i = -1;
	while (ptr[++i])
		if (ptr[i] == '{')
		{
			write(1, ptr, i);
			tmp = ft_strsub(&ptr[i + 1], 0, cont_carac(&ptr[i + 1], '}'));
			if (ft_strchr(&str[i], '}') != NULL &&
				ft_color(tmp) != 0)
			{
				ptr = ft_strchr(ptr, '}') + 1;
				i = -1;
			}
			else
				print_else(&ptr, &i);
			free(tmp);
		}
	write(1, ptr, i);
	free(secur);
}
