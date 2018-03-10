/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_buff_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:28:07 by ravard            #+#    #+#             */
/*   Updated: 2018/03/10 17:18:37 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*buff_malloc(int *offset, char const *s, t_spe *sp)
{
	static const char	*no_type = "#-+ 0123456789.hljz";
	int					i[2];
	char				*buff;
	
	i[0] = -1;
	while (s[++i[0]])
	{
		i[1] = -1;
		while (no_type[++i[1]])
			if (s[i[0]] == no_type[i[1]])
				break ;
		if (!no_type[i[1]] && (sp->type = s[i[0]]))
			break ;
	}
	if (!(buff = (char *)malloc(sizeof(char) * (i[0] + 1))))
		ft_exit("probleme de memoire via buff_malloc\n");
	*offset = (sp->type) ? i[0] + 1 : i[0];
	return (buff);
}

void		d_malloc(intmax_t i, t_spe *sp)
{
	int		k;

	k = MARGE;
	if (i < 0)
		i = -i;
	while ((i /= 10) != 0)
		++k;
	k = (sp->pre >= k) ? sp->pre + MARGE : k;
	k = (sp->w >= k) ? sp->w + MARGE : k;
	if (!(sp->buff.b = (char *)malloc(sizeof(char) * (k + 1))))
		ft_exit("probleme de memoire via d_malloc\n");
	ft_memset(sp->buff.b, '\0', k + 1);
}

void		oux_malloc(uintmax_t i, char b, t_spe *sp)
{
	int		k;

	k = MARGE;
	while ((i /= b) != 0)
		++k;
	k = (sp->pre >= k - 1) ? sp->pre + MARGE : k;
	k = (sp->w >= k - 1) ? sp->w + MARGE : k;
	if (!(sp->buff.b = (char *)malloc(sizeof(char) * (k + 1))))
		ft_exit("probleme de memoire via oux_malloc\n");
	ft_memset(sp->buff.b, '\0', k + 1);
}

void		c_malloc(char nb_char, t_spe *sp)
{
	int		k;

	k = (sp->w > nb_char) ? sp->w : nb_char;
	if (!(sp->buff.b = (char *)malloc(sizeof(char) * (k + 1))))
		ft_exit("probleme de memoire via c_malloc\n");
	ft_memset(sp->buff.b, '\0', k + 1);
}

int			s_verif_space(char *str, t_spe *sp)
{
	int		k;

	k = (str) ? ft_strlen(str) : ft_strlen("(null)");
	k = (sp->pre != -1 && sp->pre < k) ? sp->pre : k;
	k = (sp->w > k) ? sp->w : k;
	if (BUFF_SIZE - sp->buff.len > k)
		return (1);
	else if (k < BUFF_SIZE)
	{
		write_buff(sp);
		return (1);
	}
	else
		ft_exit("who dare brutalise my printouf?!\n");
	return (0);
}
