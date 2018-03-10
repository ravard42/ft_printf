/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 02:24:31 by ravard            #+#    #+#             */
/*   Updated: 2018/03/10 19:43:16 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		preci(t_spe *sp)
{
	char	*buff;
	int		i;

	buff = sp->buff.b;
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

	buff = sp->buff.b;
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

static int		wstrlen(wchar_t *wc)
{
	int		i;

	i = -1;
	while (wc[++i])
		;
	return (i);
}

static void		handle_wchar(wchar_t *wstr, t_spe *sp)
{
	int				i[3];
	int				nb;

	i[0] = wstrlen(wstr);
	if (!(sp->buff.b = (char *)malloc(sizeof(char) * (i[0] * 4 + 1))))
		ft_exit("soucis de malloc utf_8 wchar\n");
	ft_memset(sp->buff.b, 0, i[0] * 4 + 1);
	i[1] = -1;
	i[2] = 0;
	while (++i[1] < i[0])
	{
		if (sp->pre != -1 && i[2] >= sp->pre)
			break ;
		if (MB_CUR_MAX == 1 && wstr[i[1]] > 255 && (sp->size = -42))
			break ;
		else if (MB_CUR_MAX == 1 && ++i[2])
			sp->buff.b[i[2] - 1] = (char)wstr[i[1]];
		else if ((nb = utf_32_to_8(*(wstr + i[1]), sp->buff.b + i[2])) != -1)
			i[2] += nb;
		else if (nb == -1 && (sp->size = -42))
			break ;
	}
}

void			s_conv(va_list *va, t_spe *sp)
{
	char			*str;
	wchar_t			*wstr;

	str = va_arg(*va, char *);
	wstr = (wchar_t *)str;
	if (sp->size == 'l')
		handle_wchar(wstr, sp);
	else
	{
		s_malloc(str, sp);
		if (str == NULL)
			putstr_buffer("(null)", sp->buff.b);
		else
			putstr_buffer(str, sp->buff.b);
	}
	if (sp->size != -42)
	{
		preci(sp);
		width_and_flags(sp);
		sp->buff.ret += write(1, sp->buff.b, ft_strlen(sp->buff.b));
	}
	free(sp->buff.b);
	sp->buff.b = NULL;
}
