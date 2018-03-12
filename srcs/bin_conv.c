/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:29:12 by ravard            #+#    #+#             */
/*   Updated: 2018/03/12 07:56:44 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		bin_disp_char(char c, char *buff)
{
	size_t	k;

	k = -1;
	while (++k < 8)
		putchar_buffer('0' + (c >> k & 1), buff + 7 - k);
	putchar_buffer('\n', buff + 8);
}

static void		bin_disp(int val, size_t len, t_spe *sp)
{
	char		*tmp;
	size_t		i;

	tmp = (char *)&val;
	i = -1;
	while (++i < len)
		bin_disp_char(tmp[i], sp->buff.b + 9 * i);
}

void			bin_conv(va_list *va, t_spe *sp)
{
	int		k;
	char	nb_char;

	nb_char = 1;
	if (sp->size == 'h')
		nb_char = 2;
	else if (sp->size == 'l')
		nb_char = 4;
	k = nb_char * 9 + MARGE;
	if (!(sp->buff.b = (char *)malloc(sizeof(char) * (k + 1))))
		ft_exit("probleme de memoire via s_malloc\n");
	ft_memset(sp->buff.b, '\0', k + 1);
	bin_disp(va_arg(*va, int), nb_char, sp);
	sp->buff.ret += write(1, sp->buff.b, ft_strlen(sp->buff.b));
	free(sp->buff.b);
	sp->buff.b = NULL;
}
