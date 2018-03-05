/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_buff_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:28:07 by ravard            #+#    #+#             */
/*   Updated: 2018/03/05 23:21:20 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		d_verif_space(intmax_t i, t_spe *sp)
{
	int		k;

	k = 2;
	if (i < 0)
		i = -i;
	while ((i /= 10) != 0)
		++k;
	k = (sp->pre > k) ? sp->pre + 1 : k;
	k = (sp->w > k) ? sp->w : k;
	if (BUFF_SIZE - sp->buff.len > k)
		;
	else if (k < BUFF_SIZE)
		write_buff(sp);
	else
		ft_exit("who dare brutalise my printouf?!\n");
}

void		oux_verif_space(uintmax_t i, char b, t_spe *sp)
{
	int		k;

	k = 3;
	while ((i /= b) != 0)
		++k;
	k = (sp->pre > k) ? sp->pre + 2 : k;
	k = (sp->w > k) ? sp->w : k;
	if (BUFF_SIZE - sp->buff.len > k)
		;
	else if (k < BUFF_SIZE)
		write_buff(sp);
	else
		ft_exit("who dare brutalise my printouf?!\n");
}

void		c_verif_space(char nb_char, t_spe *sp)
{
	int		k;

	k = (sp->w > nb_char) ? sp->w : nb_char;
	if (BUFF_SIZE - sp->buff.len > k)
		;
	else if (k < BUFF_SIZE)
		write_buff(sp);
	else
		ft_exit("who dare brutalise my printouf?!\n");
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
