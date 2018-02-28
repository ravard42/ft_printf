/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf_32_to_8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:26:14 by ravard            #+#    #+#             */
/*   Updated: 2018/02/28 20:26:46 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		utf_32_to_8(wchar_t utf_32, char *utf_8)
{
	unsigned int	codepoint;
	int				nb;
	int				i;

	codepoint = (unsigned int)utf_32;
	if (codepoint <= 0x7F && !(utf_8[0] = 0))
		nb = 1;
	else if (codepoint <= 0x7FF && (utf_8[0] = 0xC0))
		nb = 2;
	else if (codepoint <= 0xFFFF && (utf_8[0] = 0xE0))
		nb = 3;
	else if (codepoint <= 0x10FFFF && (utf_8[0] = 0xF0))
		nb = 4;
	else
		ft_exit();
	i = 0;
	while (++i < nb)
	{
		utf_8[nb - i] = 0x80 | (unsigned int)(codepoint & 0x3F);
		codepoint >>= 6;
	}
	utf_8[0] |= (unsigned int)codepoint;
	return (nb);
}
