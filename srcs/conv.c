/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 02:48:06 by ravard            #+#    #+#             */
/*   Updated: 2018/03/09 11:54:55 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	exception(t_spe *sp)
{
	char	c;

	if ((c = sp->type) == 'D' || c == 'O' || c == 'U' || c == 'p'
			|| c == 'C' || c == 'S')
	{
		sp->size = 'l';
		if (sp->type == 'D' && (sp->type = 'd'))
			return (2);
		else if (sp->type == 'O' && (sp->type = 'o'))
			return (3);
		else if (sp->type == 'U' && (sp->type = 'u'))
			return (3);
		else if (sp->type == 'p' && (sp->type = 'x'))
		{
			sp->fl.hash = 2;
			return (3);
		}
		else if (sp->type == 'C' && (sp->type = 'c'))
			return (0);
		else if (sp->type == 'S' && (sp->type = 's'))
			return (1);
	}
	return (-1);
}

static int	select_conv(t_conv const *tab, t_spe *sp)
{
	int		i;
	int		j;

	if ((i = exception(sp)) != -1)
		return (i);
	while (tab[++i].s[0])
	{
		j = -1;
		while (tab[i].s[++j] && tab[i].s[j] != sp->type)
			;
		if (tab[i].s[j] && tab[i].s[j] == sp->type)
			return (i);
	}
	return (i);
}

static void	init_sp(char *str, t_spe *sp)
{
	sp->out = str;
	sp->outlen = 0;
	ft_memset(sp->buff.b, '\0', BUFF_SIZE);
	sp->buff.len = 0;
	sp->buff.ret = 0;
}

int			conv(char *str, const char *s, va_list *va, t_conv const *tab)
{
	int		i;
	t_spe	sp;

	init_sp(str, &sp);
	i = -1;
	while (s[++i])
	{
		if (s[i] != '%')
			put_one_char_buffer(s[i], &sp);
		else
		{
			i += extract_specifier(s + i + 1, &sp);
			tab[select_conv(tab, &sp)].f(va, &sp);
			if (sp.size != -42)
				sp.buff.last_valid_index = sp.buff.len;
		}
		if (sp.size == -42 && (sp.buff.ret = -1))
			break ;
	}
	write_buff(&sp);
	return (sp.buff.ret);
}
