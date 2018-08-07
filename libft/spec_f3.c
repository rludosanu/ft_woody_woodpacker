/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:42:40 by cdrouet           #+#    #+#             */
/*   Updated: 2017/04/05 13:09:11 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_nopct(const char *restrict format, char c, va_list ap)
{
	char	*ptr;
	int		j;
	int		i;

	j = 0;
	while (format[j] && !ft_isdigit(format[j]) && format[j] != '*')
		j++;
	if (format[j])
	{
		if (format[j] == '*')
			init(&i, &j, ap);
		ptr = ft_strnew(2);
		ptr[0] = c;
		ptr = decal_c(&ptr, format, j);
		ft_putstr(ptr);
		i = ft_strlen(ptr);
		free(ptr);
		return (i);
	}
	else if (c != '\0')
		ft_putchar(c);
	else
		return (0);
	return (1);
}

int			cont_carac(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c)
		if (s[i++] == '\0')
			return (-1);
	return (i);
}

int			pct_pct(const char *restrict format, va_list ap)
{
	char	*res;
	int		i;

	(void)ap;
	res = ft_strnew(2);
	res[0] = '%';
	res = aj_decal(&res, format, 0);
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	return (i);
}

static int	recur_uitoa_b(unsigned int nbr, int base, char *ptr, int index)
{
	char	*str;

	str = "0123456789abcdef";
	if (nbr >= (unsigned int)base)
	{
		index = recur_uitoa_b(nbr / base, base, ptr, index);
		index = recur_uitoa_b(nbr % base, base, ptr, index);
	}
	else
	{
		ptr[index] = str[nbr];
		index++;
	}
	return (index);
}

char		*ft_uitoa_base(unsigned int nbr, int base)
{
	char	*ptr;

	ptr = ft_strnew(20);
	recur_uitoa_b(nbr, base, ptr, 0);
	return (ptr);
}
