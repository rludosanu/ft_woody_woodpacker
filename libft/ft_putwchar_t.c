/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 13:49:05 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/28 11:12:24 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_3o(char *str)
{
	char	*mask[3];
	int		i;

	mask[0] = ft_strjoin("11", "10");
	mask[1] = ft_strjoin("10", ft_strsub(&str[ft_strlen(str) - 12], 0, 6));
	mask[2] = ft_strjoin("10", ft_strsub(&str[ft_strlen(str) - 6], 0, 6));
	i = -1;
	while ((ft_strlen(mask[0]) +
		ft_strlen(ft_strsub(str, 0, ft_strlen(str) - 12))) < 8)
		mask[0] = ft_strjoin(mask[0], "x");
	mask[0] = ft_strjoin(mask[0], ft_strsub(str, 0, ft_strlen(str) - 12));
	while (mask[0][++i])
		if (mask[0][i] == 'x')
			mask[0][i] = '0';
	i = ft_atoi_base(mask[0], 2);
	write(1, &i, 1);
	i = ft_atoi_base(mask[1], 2);
	write(1, &i, 1);
	i = ft_atoi_base(mask[2], 2);
	write(1, &i, 1);
	i = -1;
	while (++i < 3)
		free(mask[i]);
	return (3);
}

static int	put_4o(char *str)
{
	char	*mask[4];
	int		i;

	mask[0] = ft_strjoin("111", "10");
	mask[1] = ft_strjoin("10", ft_strsub(&str[ft_strlen(str) - 18], 0, 6));
	mask[2] = ft_strjoin("10", ft_strsub(&str[ft_strlen(str) - 12], 0, 6));
	mask[3] = ft_strjoin("10", ft_strsub(&str[ft_strlen(str) - 6], 0, 6));
	i = -1;
	while ((ft_strlen(mask[0]) +
		ft_strlen(ft_strsub(str, 0, ft_strlen(str) - 18))) < 8)
		mask[0] = ft_strjoin(mask[0], "0");
	mask[0] = ft_strjoin(mask[0], ft_strsub(str, 0, ft_strlen(str) - 18));
	i = ft_atoi_base(mask[0], 2);
	write(1, &i, 1);
	i = ft_atoi_base(mask[1], 2);
	write(1, &i, 1);
	i = ft_atoi_base(mask[2], 2);
	write(1, &i, 1);
	i = ft_atoi_base(mask[3], 2);
	write(1, &i, 1);
	i = -1;
	while (++i < 4)
		free(mask[i]);
	return (4);
}

static int	put_2o(char *str)
{
	char	*mask[2];
	int		i;

	mask[0] = ft_strjoin("11", "0");
	mask[1] = ft_strjoin("10", ft_strsub(&str[ft_strlen(str) - 6], 0, 6));
	i = -1;
	while ((ft_strlen(mask[0]) +
		ft_strlen(ft_strsub(str, 0, ft_strlen(str) - 6))) < 8)
		mask[0] = ft_strjoin(mask[0], "x");
	mask[0] = ft_strjoin(mask[0], ft_strsub(str, 0, ft_strlen(str) - 6));
	while (mask[0][++i])
		if (mask[0][i] == 'x')
			mask[0][i] = '0';
	i = ft_atoi_base(mask[0], 2);
	write(1, &i, 1);
	i = ft_atoi_base(mask[1], 2);
	write(1, &i, 1);
	i = -1;
	while (++i < 2)
		free(mask[i]);
	return (2);
}

int			ft_putwchar_t(wchar_t s)
{
	unsigned int	wc;
	char			*str;

	wc = s;
	str = ft_uitoa_base(wc, 2);
	if (ft_strlen(str) <= 7)
	{
		write(1, &s, 1);
		return (1);
	}
	else if (ft_strlen(str) <= 11)
		return (put_2o(str));
	else if (ft_strlen(str) <= 16)
		return (put_3o(str));
	else
		return (put_4o(str));
	return (0);
}

int			ft_putwstr_t(wchar_t *str)
{
	int	i;
	int	ow;

	ow = 0;
	i = 0;
	while (str[i] != 0)
		ow += ft_putwchar_t(str[i++]);
	return (ow);
}
