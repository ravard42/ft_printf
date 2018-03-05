/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 02:47:24 by ravard            #+#    #+#             */
/*   Updated: 2018/03/05 23:36:30 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putstr(char *str)
{
	int	i;

	i = -1;
	if (str)
		while (str[++i])
			ft_putchar(str[i]);
}

void	put_one_char_buffer(char c, t_spe *sp)
{
	if (sp->buff.len == BUFF_SIZE)
		write_buff(sp);
	else
	{
		sp->buff.b[sp->buff.len] = c;
		++sp->buff.len;
	}
}

void	write_buff(t_spe *sp)
{
	int		i;

	sp->buff.ret += (sp->size != -42) ? sp->buff.len : 0;
	sp->buff.len = (sp->size != -42) ? sp->buff.len : sp->buff.last_valid_index;
	if (sp->out == NULL)
		write(1, sp->buff.b, sp->buff.len);
	else
	{
		i = ft_strlen(sp->out) - 1;
		while (++i < sp->buff.len)
			sp->out[i] = sp->buff.b[i];
		sp->out[i] = 0;
	}
	ft_memset(sp->buff.b, '\0', sp->buff.len);
	sp->buff.len = 0;
}
