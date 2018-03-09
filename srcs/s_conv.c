/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 02:24:31 by ravard            #+#    #+#             */
/*   Updated: 2018/03/09 11:33:00 by ravard           ###   ########.fr       */
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

static int		wstrlen(wchar_t *wc)
{
	int		i;

	i = -1;
	while (wc[++i])
		;
	return (i);
}

static char		*handle_wchar(wchar_t *wstr, t_spe *sp)
{
	int				i[3];
	char			*utf_8;
	int				nb;

	i[0] = wstrlen(wstr);
	if (!(utf_8 = (char *)malloc(sizeof(char) * (i[0] * 4 + 1))))
		ft_exit("soucis de malloc\n");
	ft_memset(utf_8, 0, i[0] * 4 + 1);
	i[1] = -1;
	i[2] = 0;
	while (++i[1] < i[0])
	{
		if (sp->pre != -1 && i[2] >= sp->pre)
			break ;
		if (MB_CUR_MAX == 1 && wstr[i[1]] > 255 && (sp->size = -42))
			break ;
		else if (MB_CUR_MAX == 1 && ++i[2])
			utf_8[i[2] - 1] = (char)wstr[i[1]];
		else if ((nb = utf_32_to_8(*(wstr + i[1]), utf_8 + i[2])) != -1)
			i[2] += nb;
		else if (nb == -1 && (sp->size = -42))
			break ;
	}
	return (utf_8);
}

void			s_conv(va_list *va, t_spe *sp)
{
	wchar_t			*wstr;
	char			*utf_8;

	wstr = NULL;
	utf_8 = va_arg(*va, char *);
	if (!utf_8 && s_verif_space(utf_8, sp))
		putstr_buffer("(null)", sp->buff.b + sp->buff.len);
	else if (sp->size == 'l' && (wstr = (wchar_t *)utf_8))
		utf_8 = handle_wchar(wstr, sp);
	if (sp->size != -42)
	{
		s_verif_space(utf_8, sp);
		putstr_buffer(utf_8, sp->buff.b + sp->buff.len);
		preci(sp);
		width_and_flags(sp);
		sp->buff.len += ft_strlen(sp->buff.b + sp->buff.len);
	}
	if (wstr)
		free(utf_8);
}
