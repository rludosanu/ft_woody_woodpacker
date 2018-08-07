/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:32:20 by cdrouet           #+#    #+#             */
/*   Updated: 2017/04/05 14:56:57 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	global_init(int (**f)(const char *reformatict, va_list),
	int *i)
{
	f[0] = &pct_s;
	f[1] = &pct_gs;
	f[2] = &pct_p;
	f[3] = &pct_d;
	f[4] = &pct_gd;
	f[5] = &pct_i;
	f[6] = &pct_o;
	f[7] = &pct_go;
	f[8] = &pct_u;
	f[9] = &pct_gu;
	f[10] = &pct_x;
	f[11] = &pct_gx;
	f[12] = &pct_c;
	f[13] = &pct_gc;
	f[14] = &pct_b;
	f[15] = &pct_pct;
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
}

static void	init_i_s(const char *restrict format, int *i, char *ptr)
{
	i[2] += i[1];
	i[0] += i[1];
	i[1] = -1;
	i[3] = '\0';
	while (++i[1] < 17)
		if (cont_carac((char*)&format[i[0] + 1], ptr[i[1]]) >= 0)
			if ((cont_carac((char*)&format[i[0] + 1], i[3]) >
						cont_carac((char*)&format[i[0] + 1], ptr[i[1]])))
				i[3] = ptr[i[1]];
	i[1] = 0;
	while (ptr[i[1]] != i[3] && ptr[i[1]])
		i[1]++;
}

static void	traitement_2(int *i, const char *restrict t, va_list ap, int j)
{
	int		l;
	char	*tmp;

	tmp = ft_strsub(&t[i[0] + 1], 0,
		cont_carac((char*)&t[i[0] + 1], i[3]) + 1);
	l = print_nopct(tmp, t[i[0] + 1 + j], ap);
	i[2] += l;
	if (t[i[0] + 1 + j])
		i[0] += j + 2;
	else
		i[0] += j + 1;
	free(tmp);
}

static void	traitement(int *i, const char *restrict t, va_list ap,
	int (**f)(const char *restrict, va_list))
{
	int		j;
	char	*tmp;

	tmp = ft_strsub(&t[i[0] + 1], 0,
			cont_carac((char*)&t[i[0] + 1], i[3]) + 1);
	if (i[3] == 'n')
	{
		pct_n(i[2], ap, tmp);
		i[0] += cont_carac((char*)&t[i[0]], i[3]) + 1;
	}
	else if (i[1] != 17 && (verif_flag(tmp, i[3]) == -1))
	{
		i[2] += f[i[1]](tmp, ap);
		if (i[3] == '%')
			i[0]++;
		i[0] += cont_carac((char*)&t[i[0]], i[3]) + 1;
	}
	else if ((j = verif_flag(tmp, i[3])) != -1
			|| i[1] == 17)
		traitement_2(i, t, ap, j);
	free(tmp);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		i[4];
	char	*ptr;
	char	*tmp;
	int		(*f[16])(const char *restrict, va_list);

	ptr = "sSpdDioOuUxXcCb%n";
	global_init(f, i);
	va_start(ap, format);
	while ((i[1] = cont_carac((char*)&format[i[0]], '%')) >= 0)
	{
		tmp = ft_strsub(&format[i[0]], 0, i[1]);
		print_str_color(tmp);
		free(tmp);
		init_i_s(format, i, ptr);
		traitement(i, format, ap, f);
	}
	i[2] += ft_strlen(&format[i[0]]);
	print_str_color((char*)&format[i[0]]);
	va_end(ap);
	if (i[2] < 0)
		i[2] = 0;
	return (i[2]);
}
