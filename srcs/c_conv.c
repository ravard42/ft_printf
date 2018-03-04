/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 02:24:19 by ravard            #+#    #+#             */
/*   Updated: 2018/03/04 06:05:31 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		width_and_flags(t_spe *sp)
{
	char	*buff;
	char	offset;
	int		w;
	char	c;

	buff = sp->buff.b + sp->buff.len;
	offset = (buff[0]) ? ft_strlen(buff) : 1;
	w = sp->w - offset;
	if (w > 0)
	{
		if (sp->fl.min)
			add_tail(w, ' ', buff + offset);
		else
		{
			c = (sp->fl.ze) ? '0' : ' ';
			add_nose(w, c, buff);
		}
	}
}

static int		verif(wchar_t c, t_spe *sp)
{
	if (c > 255)
		return (-1);
	return (1);
}

static void		handle_null(char c, t_spe *sp)
{
	putchar_buffer(c, sp->buff.b + sp->buff.len);
	width_and_flags(sp);
	sp->buff.len += (sp->w >= 2) ? sp->w : 1;
}

void			c_conv(va_list *va, t_spe *sp)
{
	char			utf_8[5];
	wchar_t			c;
	char			nb_char;

	ft_memset(utf_8, '\0', 5);
	c = va_arg(*va, wchar_t);
	nb_char = (sp->size == 'l' && MB_CUR_MAX == 4) ?
		utf_32_to_8(c, utf_8) : verif(c, sp);
	if (nb_char == -1 && (sp->size = -42))
		return ;
	c_verif_space(nb_char, sp);
	if (!c)
		handle_null(c, sp);
	else
	{
		if (sp->size == 'l' && MB_CUR_MAX == 4)
			putstr_buffer(utf_8, sp->buff.b + sp->buff.len);
		else
			putchar_buffer(c, sp->buff.b + sp->buff.len);
		width_and_flags(sp);
		sp->buff.len += ft_strlen(sp->buff.b + sp->buff.len);
	}
}
