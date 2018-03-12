/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 02:47:24 by ravard            #+#    #+#             */
/*   Updated: 2018/03/12 08:01:34 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void			my_putstr(char *str)
{
	int	i;

	i = -1;
	if (str)
		while (str[++i])
			ft_putchar(str[i]);
}

int				no_spe(char const *s, t_spe *sp)
{
	int		i;

	i = -1;
	while (s[++i] && s[i] != '%')
	{
		if (sp->out != NULL && (sp->out[sp->outlen] = s[i]))
			sp->outlen++;
	}
	if (sp->out == NULL)
		sp->buff.ret += write(1, s, i);
	return (i);
}
