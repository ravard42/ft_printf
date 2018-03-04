/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:03:16 by ravard            #+#    #+#             */
/*   Updated: 2018/03/04 04:35:18 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width_flags(char *buff, t_spe *sp)
{
	int		w;

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
	char	*buff;

	buff = sp->buff.b + sp->buff.len;
	buff[0] = sp->type;
	ft_width_flags(buff, sp);
	sp->buff.len += ft_strlen(sp->buff.b + sp->buff.len);
}
