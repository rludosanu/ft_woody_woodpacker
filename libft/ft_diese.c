/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diese.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 09:59:37 by cdrouet           #+#    #+#             */
/*   Updated: 2017/04/05 15:40:57 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_diese_o(char **ptr)
{
	int		i;

	i = 0;
	while ((*ptr)[i] == ' ')
		i++;
	if (i == 0 && ft_strlen(*ptr) == 0)
		(*ptr)[0] = '0';
	if ((*ptr)[i] == '0')
		return (*ptr);
	else if (i > 0)
	{
		(*ptr)[i - 1] = '0';
		return (*ptr);
	}
	else if (i == 0 && (*ptr)[ft_strlen(*ptr) - 1] != ' ')
		return (ft_strjoin("0", *ptr));
	else if (i == 0 && (*ptr)[ft_strlen(*ptr) - 1] == ' ')
		return (ft_strjoin_free("0",
					ft_strsub(*ptr, 0, ft_strlen(*ptr) - 1), 2));
	else
		return (*ptr);
}

static char	*ft_diese_x2(const char *restrict format, char **p, int i, int maj)
{
	int		j;
	int		dec;
	char	*x;
	char	*tmp;

	if ((*p)[i] == '0' && ft_strchr(format, 'p') == NULL)
		i++;
	dec = 0;
	j = ft_strlen(*p);
	while ((*p)[--j] == ' ' && dec <= 2
			&& j > (int)(ft_strlen(*p) - 3))
		dec++;
	if (maj == 0)
		x = "0x";
	else
		x = "0X";
	tmp = ft_strsub(*p, i, (int)ft_strlen(*p) - i - dec);
	x = ft_strjoin(x, tmp);
	free(tmp);
	return (x);
}

static char	*ft_diese_gx(const char *restrict format, char **ptr)
{
	int		i;

	i = 0;
	while ((*ptr)[i] == ' ')
		i++;
	if ((*ptr)[i] == '0' && (*ptr)[i + 1] == '0' && !ft_strchr(format, '.'))
	{
		(*ptr)[i + 1] = 'X';
		return (*ptr);
	}
	else if (ft_strchr(format, '.') != NULL && i >= 2)
		return (ft_strjoin_free(ft_strjoin_free(ft_strsub(*ptr, 0, i - 2),
				"0X", 1), ft_strsub(*ptr, i, (int)ft_strlen(*ptr) - i), 3));
	else if (ft_strchr(format, '.') != NULL && i < 2
			&& (*ptr)[ft_strlen(*ptr) - 1] != ' ')
		return (ft_strjoin_free(ft_strjoin_free(ft_strsub(*ptr, 0, i), "0X", 1)
					, ft_strsub(*ptr, i, (int)ft_strlen(*ptr) - i), 3));
	else if (i > 1)
	{
		(*ptr)[i - 2] = '0';
		(*ptr)[i - 1] = 'X';
	}
	else if (i <= 1)
		return (ft_diese_x2(format, ptr, i, 1));
	return (*ptr);
}

static char	*ft_diese_x(const char *restrict format, char **ptr)
{
	int		i;

	i = 0;
	i = init_diese_i(ptr);
	if ((*ptr)[i] == '0' && (*ptr)[i + 1] == '0' && !ft_strchr(format, '.'))
	{
		(*ptr)[i + 1] = 'x';
		return (*ptr);
	}
	else if (ft_strchr(format, '.') != NULL && i >= 2)
		return (ft_strjoin_free(ft_strjoin_free(ft_strsub(*ptr, 0, i - 2), "0x",
						1), ft_strsub(*ptr, i, (int)ft_strlen(*ptr) - i), 3));
	else if (ft_strchr(format, '.') != NULL && i < 2
			&& (*ptr)[ft_strlen(*ptr) - 1] != ' ')
		return (ft_strjoin_free(ft_strjoin_free(ft_strsub(*ptr, 0, i), "0x", 1),
						ft_strsub(*ptr, i, (int)ft_strlen(*ptr) - i), 3));
	else if (i > 1)
	{
		(*ptr)[i - 2] = '0';
		(*ptr)[i - 1] = 'x';
	}
	else if (i <= 1)
		return (ft_diese_x2(format, ptr, i, 0));
	return (*ptr);
}

char		*ft_diese(const char *restrict format, char **ptr, int base, int m)
{
	char	*res;

	res = *ptr;
	if (ft_atoi(*ptr) == 0 && ft_strchr(format, 'p') == NULL
			&& !ft_strchr(format, 'o') && !ft_strchr(format, 'O'))
		return (*ptr);
	if (base == 8)
		res = ft_diese_o(ptr);
	else if (base == 16 && m == 0)
		res = ft_diese_x(format, ptr);
	else if (base == 16 && m == 1)
		res = ft_diese_gx(format, ptr);
	return (res);
}
