/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:29:12 by ravard            #+#    #+#             */
/*   Updated: 2018/02/28 19:31:33 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		bin_disp_char(char c, t_spe *sp)
{
	size_t	k;

	k = -1;
	while (++k < 8)
		putchar_buffer('0' + (c >> k & 1), sp->buff.b + sp->buff.len + 7 - k);
	putchar_buffer('\n', sp->buff.b + sp->buff.len + 8);
	sp->buff.len += 9;
}

static void		bin_disp(int val, size_t len, t_spe *sp)
{
	char		*tmp;
	size_t		i;

	tmp = (char *)&val;
	i = -1;
	while (++i < len)
		bin_disp_char(tmp[i], sp);
}

void			bin_conv(va_list *va, t_spe *sp)
{
	char	nb_char;

	nb_char = 1;
	if (sp->size == 'h')
		nb_char = 2;
	else if (sp->size == 'l')
		nb_char = 4;
	if (BUFF_SIZE - sp->buff.len <= nb_char * 9)
		write_buff_stdout(sp);
	bin_disp(va_arg(*va, int), nb_char, sp);
	sp->buff.len = ft_strlen(sp->buff.b);
}
