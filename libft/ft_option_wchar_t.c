/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_wchar_t.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 11:47:00 by cdrouet           #+#    #+#             */
/*   Updated: 2017/04/05 13:37:21 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				nbr_bytes_wchar(wchar_t s)
{
	unsigned int	wc;
	char			*str;
	int				len;

	wc = s;
	str = ft_uitoa_base(wc, 2);
	len = ft_strlen(str);
	free(str);
	if (len <= 7)
		return (1);
	else if (len <= 11)
		return (2);
	else if (len <= 16)
		return (3);
	else
		return (4);
}

int				nbr_bytes_wstr(wchar_t *str)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (str[i] != 0)
		res += nbr_bytes_wchar(str[i++]);
	return (res);
}

static wchar_t	*decal_sf(wchar_t **str, wchar_t *ptr, int decal)
{
	int	i;
	int	j;

	ptr[0] = 0;
	ft_wstrcat(ptr, *str);
	i = 0;
	while (ptr[i] != 0)
		i++;
	j = -1;
	while (++j < (decal - nbr_bytes_wstr(*str)))
		ptr[i++] = ' ';
	ptr[i] = 0;
	return (ptr);
}

wchar_t			*decal_wstr(wchar_t **str, const char *restrict format, int nb)
{
	wchar_t	*ptr;
	char	c;
	int		i;

	i = -1;
	while (!(format[++i] >= '0' && format[i] <= '9') && format[i] != '*')
		if (!format[i] || format[i] == '.')
			return (*str);
	c = ' ';
	if (format[i] == '0')
		c = '0';
	if (format[i] == '*')
		i = nb;
	else
		i = ft_atoi(&format[i]);
	if (i <= nbr_bytes_wstr(*str))
		return (*str);
	ptr = (wchar_t*)malloc(sizeof(wchar_t) * (i + 1));
	if (ft_strchr(format, '-') != NULL)
		return (decal_sf(str, ptr, i));
	i = i - nbr_bytes_wstr(*str);
	ptr[i] = 0;
	while (--i >= 0)
		ptr[i] = c;
	return (ft_wstrcat(ptr, (*str)));
}

wchar_t			*ft_wstrcat(wchar_t *dest, wchar_t *src)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (dest[j] != 0)
		j++;
	while (src[++i] != 0)
		dest[j + i] = src[i];
	dest[j + i] = 0;
	return (dest);
}
