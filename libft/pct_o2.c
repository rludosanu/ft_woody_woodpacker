/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_o2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:42:15 by cdrouet           #+#    #+#             */
/*   Updated: 2017/04/05 16:13:09 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_jo(va_list ap, const char *restrict format, int base, int maj)
{
	intmax_t	ptr;
	char		*res;
	char		*tmp;
	int			nb1;
	int			nb2;

	nb1 = 0;
	nb2 = 0;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	ptr = (intmax_t)va_arg(ap, intmax_t);
	res = ft_ulltoa_base((long long)ptr, base);
	if ((tmp = precis_d(&res, format, nb2)) != res)
		replace_ptr(&res, &tmp);
	if ((tmp = width_d(&res, format, nb1, nb2)) != res)
		replace_ptr(&res, &tmp);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	if (ft_strchr(format, '#') != NULL)
		if ((tmp = ft_diese(format, &res, base, maj)) != res)
			replace_ptr(&res, &tmp);
	return (put_len_free(res));
}

int		pct_zo(va_list ap, const char *restrict format, int base, int maj)
{
	size_t	ptr;
	char	*res;
	char	*tmp;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = 0;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	ptr = (size_t)va_arg(ap, size_t);
	res = ft_ulltoa_base((long long)ptr, base);
	if ((tmp = precis_d(&res, format, nb2)) != res)
		replace_ptr(&res, &tmp);
	if ((tmp = width_d(&res, format, nb1, nb2)) != res)
		replace_ptr(&res, &tmp);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	if (ft_strchr(format, '#') != NULL)
		if ((tmp = ft_diese(format, &res, base, maj)) != res)
			replace_ptr(&res, &tmp);
	return (put_len_free(res));
}

int		pct_oo(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned int	ptr;
	char			*res;
	char			*tmp;
	int				nb1;
	int				nb2;

	nb1 = 0;
	nb2 = 0;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	ptr = (unsigned int)va_arg(ap, unsigned int);
	res = ft_uitoa_base((unsigned int)ptr, base);
	if ((tmp = precis_d(&res, format, nb2)) != res)
		replace_ptr(&res, &tmp);
	if ((tmp = width_d(&res, format, nb1, nb2)) != res)
		replace_ptr(&res, &tmp);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	if (ft_strchr(format, '#') != NULL)
		if ((tmp = ft_diese(format, &res, base, maj)) != res)
			replace_ptr(&res, &tmp);
	return (put_len_free(res));
}

void	ft_strtoupper(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = ft_toupper(str[i]);
}
