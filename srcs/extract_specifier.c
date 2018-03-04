/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:06:05 by ravard            #+#    #+#             */
/*   Updated: 2018/03/04 04:57:07 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			find_type(char *buff, char const *s, t_spe *sp)
{
	static const char	*no_type = "#-+ 0123456789.hljz";
	int					i;
	int					j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (no_type[++j])
			if (s[i] == no_type[j])
				break ;
		if (!no_type[j] && (sp->type = s[i]))
			break ;
		if (i >= 31)
			ft_exit("who dare brutalise my printouf?!\n");
		buff[i] = s[i];
	}
	buff[i] = '\0';
	sp->type = (sp->type == 'i') ? 'd' : sp->type;
	if (sp->type == '\0')
		return (i);
	return (i + 1);
}

static void			catch_flags(char *s, t_spe *sp)
{
	int		field;
	int		i;

	field = 0;
	i = -1;
	while (s[++i])
	{
		field = ((s[i] > '0' && s[i] <= '9') || s[i] == '.') ? 1 : field;
		sp->fl.hash = (s[i] == '#') ? 1 : sp->fl.hash;
		sp->fl.min = (s[i] == '-') ? 1 : sp->fl.min;
		sp->fl.plu = (s[i] == '+') ? 1 : sp->fl.plu;
		sp->fl.sp = (s[i] == ' ') ? 1 : sp->fl.sp;
		sp->fl.ze = (s[i] == '0' && field == 0) ? 1 : sp->fl.ze;
	}
	sp->fl.sp = (sp->fl.plu) ? 0 : sp->fl.sp;
	sp->fl.ze = (sp->fl.min) ? 0 : sp->fl.ze;
}

static void			catch_w_and_pre(char *s, t_spe *sp)
{
	int		i;
	int		w_is_set;

	w_is_set = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '.')
		{
			sp->pre = catch_pos_numb(s + i + 1);
			break ;
		}
		if (s[i] > '0' && s[i] <= '9' && !w_is_set++)
			sp->w = catch_pos_numb(s + i);
	}
}

static void			catch_size(char *s, t_spe *sp)
{
	int		i;
	int		breakk;

	breakk = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == 'h')
		{
			sp->size = (s[i + 1] == 'h') ? 'H' : 'h';
			i += (s[i + 1] == 'h') ? 1 : 0;
		}
		else if (s[i] == 'l' && (breakk = 1))
			sp->size = (s[i + 1] == 'l') ? 'L' : 'l';
		else if (s[i] == 'j' && (breakk = 1))
			sp->size = 'j';
		else if (s[i] == 'z' && (breakk = 1))
			sp->size = 'z';
		if (breakk)
			break ;
	}
}

int					extract_specifier(char const *s, t_spe *sp)
{
	int			offset;
	char		buff[32];

	init_spe(sp);
	offset = find_type(buff, s, sp);
	catch_flags(buff, sp);
	catch_w_and_pre(buff, sp);
	catch_size(buff, sp);
	return (offset);
}
