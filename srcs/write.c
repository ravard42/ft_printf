/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 02:47:24 by ravard            #+#    #+#             */
/*   Updated: 2018/03/02 01:24:03 by ravard           ###   ########.fr       */
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
		write_buff_stdout(sp);
	else
	{
		sp->buff.b[sp->buff.len] = c;
		++sp->buff.len;
	}
}

void	write_buff_stdout(t_spe *sp)
{
	sp->buff.ret += sp->buff.len;
	write(1, sp->buff.b, sp->buff.len);
	ft_memset(sp->buff.b, '\0', sp->buff.len);
	sp->buff.len = 0;
}
