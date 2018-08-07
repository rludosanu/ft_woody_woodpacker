/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:36:36 by cdrouet           #+#    #+#             */
/*   Updated: 2017/04/05 16:12:12 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int		init_diese_i(char **ptr);
char	*all_flag_spe(long long i,
		const char *restrict format, int nb1, int nb2);
int		print_nopct(const char *restrict fomat, char c, va_list ap);
char	*decal_c(char **ptr, const char *restrict format, int nb1);
int		star_or_nb(const char *restrict_format);
char	*width_d(char **ptr, const char *restrict format, int nb1, int nb2);
char	*plus_d(char **ptr, const char *restrict format, long long i);
char	*precis_d(char **ptr, const char *restrict format, int nbr);
int		verif_flag(const char *restrict format, int s);
void	init_nb(int *nb1, int *nb2, const char *restrict format);
void	pct_n(int n, va_list ap, const char *restrict format);
void	print_str_color(char *str);
int		ft_color(char *color);
int		ft_atoi(const char *str);
char	*ft_ctoa_base(char nb, int base);
int		ft_wstrlen(wchar_t *str);
int		ft_putwmem(wchar_t *str, int i);
wchar_t	*precis_wchar_t(wchar_t *ptr, const char *restrict format, int nb);
wchar_t	*decal_wstr(wchar_t **str, const char *restrict format, int nb);
wchar_t	*ft_wstrcat(wchar_t *dest, wchar_t *src);
int		nbr_bytes_wchar(wchar_t s);
int		nbr_bytes_wstr(wchar_t *str);
int		ft_putwstr_t(wchar_t *str);
int		pct_ls(const char *restrict format, va_list ap);
int		ft_putwchar_t(wchar_t s);
int		ft_atoi_base(const char *str, int base);
int		pct_lc(const char *restrict format, va_list ap);
char	*ft_diese(const char *restrict format, char **ptr, int base, int maj);
void	ft_strtoupper(char *str);
int		pct_hho(va_list ap, const char *restrict format, int base, int maj);
int		pct_ho(va_list ap, const char *restrict format, int base, int maj);
int		pct_llo(va_list ap, const char *restrict format, int base, int maj);
int		pct_lo(va_list ap, const char *restrict format, int base, int maj);
int		pct_jo(va_list ap, const char *restrict format, int base, int maj);
int		pct_zo(va_list ap, const char *restrict format, int base, int maj);
int		pct_oo(va_list ap, const char *restrict format, int base, int maj);
void	aj_decal_g(int i, const char *restrict format, char *res, char **ptr);
void	aj_decal_d(int i, char **ptr, char *res, char c);
void	init(int *nb1, int *nb2, va_list ap);
char	*aj_zero(char **ptr, const char *restrict format, int nb);
char	*aj_decal(char **ptr, const char *restrict format, int nb);
int		cont_carac(char *s, char c);
char	*ft_itoa_base(int nb, int base);
char	*ft_ltoa_base(long nb, int base);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_toupper(int c);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
void	ft_putstr(char const *s);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_stoa_base(short nb, int base);
char	*ft_lltoa_base(long long nb, int base);
char	*ft_ctoa_base(char nb, int base);
char	*ft_lltoa(long long nbr);
char	*ft_uitoa_base(unsigned int nbr, int base);
char	*ft_ultoa_base(unsigned long nbr, int base);
char	*ft_ulltoa_base(unsigned long long nbr, int base);
int		recur_lltoa(unsigned long long nbr, char *ptr, int index);
int		ft_printf(const char *restrict format, ...);
int		pct_d(const char *restrict format, va_list ap);
int		pct_b(const char *restrict format, va_list ap);
int		pct_s(const char *restrict format, va_list ap);
int		pct_gs(const char *restrict format, va_list ap);
int		pct_p(const char *restrict format, va_list ap);
int		pct_gd(const char *restrict format, va_list ap);
int		pct_i(const char *restrict format, va_list ap);
int		pct_o(const char *restrict format, va_list ap);
int		pct_go(const char *restrict format, va_list ap);
int		pct_u(const char *restrict format, va_list ap);
int		pct_gu(const char *restrict format, va_list ap);
int		pct_x(const char *restrict format, va_list ap);
int		pct_gx(const char *restrict format, va_list ap);
int		pct_c(const char *restrict format, va_list ap);
int		pct_gc(const char *restrict format, va_list ap);
int		pct_pct(const char *restrict format, va_list ap);
int		ft_plus(char *str, int width);
int		ft_decal(char *str, int width);
int		ft_moin(char *str, int width);
int		pct_hhd(va_list ap, const char *restrict format);
int		pct_hd(va_list ap, const char *restrict format);
int		pct_lld(va_list ap, const char *restrict format);
int		pct_ld(va_list ap, const char *restrict format);
int		pct_zd(va_list ap, const char *restrict format);
int		pct_jd(va_list ap, const char *restrict format);
int		pct_dd(va_list ap, const char *restrict format);
char	*ft_strjoin_free(char *s1, char *s2, int bin);
void	replace_ptr(char **ptr1, char **ptr2);
int		put_len_free(char *ptr);

#endif
