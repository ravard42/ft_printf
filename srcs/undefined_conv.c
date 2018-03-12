/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:03:16 by ravard            #+#    #+#             */
/*   Updated: 2018/03/12 07:35:11 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width_flags(t_spe *sp)
{
	char	*buff;
	int		w;

	buff = sp->buff.b;
	w = sp->w - ft_strlen(buff);
	if (sp->fl.ze && w > 0)
		add_nose(w, '0', buff);
	else if (w > 0)
	{
		if (!sp->fl.min)
			add_nose(w, ' ', buff);
		else
			ft_revstr(add_nose(w, ' ', ft_revstr(buff)));
	}
}

void			undefined_conv(va_list *va, t_spe *sp)
{
	int		k;

	k = MARGE;
	k = (sp->w >= k) ? sp->w : k;
	if (!(sp->buff.b = (char *)malloc(sizeof(char) * (k + 1))))
		ft_exit("probleme de memoire via s_malloc\n");
	ft_memset(sp->buff.b, '\0', k + 1);
	sp->buff.b[0] = sp->type;
	ft_width_flags(sp);
	sp->buff.ret += write(1, sp->buff.b, ft_strlen(sp->buff.b));
	free(sp->buff.b);
	sp->buff.b = NULL;
}
