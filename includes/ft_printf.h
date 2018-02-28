/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 03:30:05 by ravard            #+#    #+#             */
/*   Updated: 2018/02/28 20:31:23 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>

# define BUFF_SIZE 200

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
	char			b[BUFF_SIZE];
	int				len;
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

}					t_spe;

typedef struct		s_conv
{
	char			*s;
	void			(*f)(va_list *va, t_spe *e);
}					t_conv;

int					ft_printf(const char *format, ...);
int					conv(const char *s, va_list *va, t_conv const *tab);
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
char				*ft_rm_whitespace(char *str);
char				*rm_multi_space(char *str, char c);
char				*polarity(char *str, int *sign);
int					ft_len(char *buf);
int					ft_power(int x, int n);
void				ft_exit();
void				ft_memset(char *b, char c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					catch_pos_numb(char *s);
void				init_spe(t_spe *sp);
char				*ft_revstr(char *str);
size_t				ft_strlen(const char *s);
char				*add_nose(int n, char c, char *buff);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				put_one_char_buffer(char c, t_spe *sp);
void				write_buff_stdout(t_spe *sp);
void				d_verif_space(intmax_t i, t_spe *sp);
void				oux_verif_space(uintmax_t i, char b, t_spe *sp);
void				c_verif_space(char nb_char, t_spe *sp);
int					s_verif_space(char *str, t_spe *sp);
int					utf_32_to_8(wchar_t utf_32, char *utf_8);
#endif
