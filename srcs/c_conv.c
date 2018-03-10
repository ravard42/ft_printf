/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 02:24:19 by ravard            #+#    #+#             */
/*   Updated: 2018/03/10 17:50:35 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		width_and_flags(t_spe *sp)
{
	char	*buff;
	char	offset;
	int		w;
	char	c;

	buff = sp->buff.b;
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
	width_and_flags(sp);
	sp->buff.ret += (sp->w >= 2) ? write(1, sp->buff.b, sp->w)
		: write(1, sp->buff.b, 1);
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
	c_malloc(nb_char, sp);
	if (!c)
		handle_null(c, sp);
	else
	{
		if (sp->size == 'l' && MB_CUR_MAX == 4)
			putstr_buffer(utf_8, sp->buff.b);
		else
			putchar_buffer(c, sp->buff.b);
		width_and_flags(sp);
		sp->buff.ret += write(1, sp->buff.b, ft_strlen(sp->buff.b));
	}
	free(sp->buff.b);
	sp->buff.b = NULL;
}
