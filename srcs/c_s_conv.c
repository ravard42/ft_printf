/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 02:46:42 by ravard            #+#    #+#             */
/*   Updated: 2018/02/28 20:05:47 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		preci(t_spe *sp)
{
	char	*buff;
	int		i;

	buff = sp->buff.b + sp->buff.len;
	if (sp->pre != -1)
	{
		if (ft_strlen(buff) > sp->pre && sp->size != 'l')
			ft_memset(buff + sp->pre, 0, ft_strlen(buff) - sp->pre);
		else if (ft_strlen(buff) > sp->pre && sp->size == 'l')
		{
			i = sp->pre;
			while (i != 0 && (buff[i] >> 7 & 1) && !(buff[i] >> 6 & 1))
				i--;
			ft_memset(buff + i, 0, ft_strlen(buff) - i);
		}
	}
}

static void		width_and_flags(t_spe *sp)
{
	char	*buff;
	char	offset;
	int		w;
	char	c;

	buff = sp->buff.b + sp->buff.len;
	w = sp->w - ft_strlen(buff);
	if (w > 0)
	{
		if (sp->fl.min)
			add_nose(w, ' ', buff + ft_strlen(buff));
		else
		{
			c = (sp->fl.ze) ? '0' : ' ';
			add_nose(w, c, buff);
		}
	}
}

void			c_conv(va_list *va, t_spe *sp)
{
	wchar_t			c;
	char			utf_8[4];
	char			nb_char;

	ft_memset(utf_8, '\0', 4);
	c = va_arg(*va, wchar_t);
	if (!c)
	{
		sp->w = sp->w - 1;
		putchar_buffer(c, sp->buff.b + sp->buff.len);
		width_and_flags(sp);
		sp->buff.len = ft_strlen(sp->buff.b) + 1;
		write_buff_stdout(sp);
	}
	else
	{
		nb_char = (sp->size == 'l') ? utf_32_to_8(c, utf_8) : 1;
		c_verif_space(nb_char, sp);
		if (sp->size == 'l')
			putstr_buffer(utf_8, sp->buff.b + sp->buff.len);
		else
			putchar_buffer(c, sp->buff.b + sp->buff.len);
		width_and_flags(sp);
		sp->buff.len = ft_strlen(sp->buff.b);
	}
}

static int		wstrlen(wchar_t *wc)
{
	int		i;

	i = -1;
	while (wc[++i])
		;
	return (i);
}

void			s_conv(va_list *va, t_spe *sp)
{
	wchar_t			*wstr;
	char			*utf_8;
	int				i[3];

	wstr = NULL;
	utf_8 = va_arg(*va, char *);
	if (!utf_8 && s_verif_space(utf_8, sp))
		putstr_buffer("(null)", sp->buff.b + sp->buff.len);
	else if (sp->size == 'l' && (wstr = (wchar_t *)utf_8))
	{
		i[0] = wstrlen(wstr);
		utf_8 = (char *)malloc(sizeof(char) * (i[0] * 4 + 1));
		i[1] = -1;
		i[2] = 0;
		while (++i[1] < i[0])
			i[2] += utf_32_to_8(*(wstr + i[1]), utf_8 + i[2]);
		utf_8[i[2]] = '\0';
	}
	s_verif_space(utf_8, sp);
	putstr_buffer(utf_8, sp->buff.b + sp->buff.len);
	if (wstr)
		free(utf_8);
	preci(sp);
	width_and_flags(sp);
	sp->buff.len = ft_strlen(sp->buff.b);
}
