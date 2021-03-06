/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 03:30:05 by ravard            #+#    #+#             */
/*   Updated: 2018/03/12 14:25:27 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>

# define MARGE 5

typedef struct		s_flags
{
	char			hash;
	char			min;
	char			plu;
	char			sp;
	char			ze;
}					t_flags;

typedef struct		s_buff
{
	char			*b;
	int				ret;
}					t_buff;

typedef struct		s_spe
{
	t_flags			fl;
	int				w;
	int				pre;
	char			size;
	char			type;
	t_buff			buff;
	char			*out;
	int				c_null_conv;
}					t_spe;

typedef struct		s_conv
{
	char			*s;
	void			(*f)(va_list *va, t_spe *e);
}					t_conv;

int					ft_sprintf(char *str, const char *format, ...);
int					ft_printf(const char *format, ...);
int					conv(char *str, const char *s, va_list *va,
						t_conv const *tab);
void				c_conv(va_list *va, t_spe *sp);
void				s_conv(va_list *va, t_spe *sp);
void				d_conv(va_list *va, t_spe *sp);
void				oux_conv(va_list *va, t_spe *sp);
void				bin_conv(va_list *va, t_spe *sp);
void				undefined_conv(va_list *va, t_spe *sp);
int					extract_specifier(char const *s, t_spe *spe);
void				putchar_buffer(char c, char *buff);
void				putstr_buffer(char *str, char *buff);
void				putnbr_buffer(intmax_t n, char *buff);
void				putbnbr_buffer(uintmax_t n, char *param, char *buff);
int					ft_atoi(const char *str);
int					ft_hexatoi(const char *str);
char				*ft_rm_whitespace(char *str);
char				*polarity(char *str, int *sign);
int					ft_len(char *buf, char mode);
int					ft_power(int x, int n);
void				ft_exit(char *error);
void				ft_memset(char *b, char c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					catch_pos_numb(char *s);
void				init_spe(t_spe *sp);
char				*ft_revstr(char *str);
size_t				ft_strlen(const char *s);
int					wstrlen(wchar_t *wc);
char				*add_nose(int n, char c, char *buff);
char				*add_tail(int n, char c, char *buff);
void				my_putstr(char *str);
int					write_no_spe(char const *s, t_spe *sp);
void				write_spe(t_spe *sp);
char				*buff_malloc(int *offset, char const *s, t_spe *sp);
void				d_malloc(intmax_t i, t_spe *sp);
void				oux_malloc(uintmax_t i, char b, t_spe *sp);
void				c_malloc(char nb_char, t_spe *sp);
void				s_malloc(char *str, t_spe *sp);
int					utf_32_to_8(wchar_t utf_32, char *utf_8);
#endif
