/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:58:40 by cdrouet           #+#    #+#             */
/*   Updated: 2017/04/05 16:11:48 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_o(const char *restrict format, va_list ap)
{
	if ((ft_strchr(format, 'h') != NULL)
		&& (ft_strchr(format, 'h') != ft_strrchr(format, 'h')))
		return (pct_hho(ap, format, 8, 0));
	else if (ft_strchr(format, 'h') != NULL)
		return (pct_ho(ap, format, 8, 0));
	else if ((ft_strchr(format, 'l') != NULL)
		&& (ft_strchr(format, 'l') != ft_strrchr(format, 'l')))
		return (pct_llo(ap, format, 8, 0));
	else if (ft_strchr(format, 'l'))
		return (pct_lo(ap, format, 8, 0));
	else if (ft_strchr(format, 'j'))
		return (pct_jo(ap, format, 8, 0));
	else if (ft_strchr(format, 'z'))
		return (pct_zo(ap, format, 8, 0));
	else
		return (pct_oo(ap, format, 8, 0));
}

int		pct_hho(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned char	ptr;
	char			*res;
	char			*tmp;
	int				nb1;
	int				nb2;

	nb1 = 0;
	nb2 = -1;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	ptr = (unsigned char)va_arg(ap, int);
	res = ft_itoa_base(ptr, base);
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

int		pct_ho(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned short	ptr;
	char			*res;
	char			*tmp;
	int				nb1;
	int				nb2;

	nb1 = 0;
	nb2 = -1;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	ptr = (unsigned short)va_arg(ap, int);
	res = ft_itoa_base(ptr, base);
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

int		pct_llo(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned long long	ptr;
	char				*res;
	char				*tmp;
	int					nb1;
	int					nb2;

	nb1 = 0;
	nb2 = -1;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	ptr = (unsigned long long)va_arg(ap, unsigned long long);
	res = ft_ulltoa_base((unsigned long long)ptr, base);
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

int		pct_lo(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned long	ptr;
	char			*res;
	char			*tmp;
	int				nb1;
	int				nb2;

	nb1 = 0;
	nb2 = -1;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	ptr = (unsigned long)va_arg(ap, unsigned long);
	res = ft_ultoa_base((unsigned long)ptr, base);
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
