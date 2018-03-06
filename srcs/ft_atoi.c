/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:32:10 by ravard            #+#    #+#             */
/*   Updated: 2018/03/06 02:25:03 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_atoi(const char *str)
{
	char	*buf;
	int		sign;
	int		i[2];
	int		result;

	buf = polarity(ft_rm_whitespace((char *)str), &sign);
	i[0] = -1;
	i[1] = ft_len(buf, 0);
	result = 0;
	while (++i[0] < i[1])
		result += (buf[i[0]] - '0') * ft_power(10, i[1] - i[0] - 1);
	result = sign * result;
	return (result);
}

int				ft_hexatoi(const char *str)
{
	char	*buf;
	int		i[2];
	int		result;

	buf = ft_rm_whitespace((char *)str);
	i[0] = -1;
	i[1] = ft_len(buf, 1);
	result = 0;
	while (++i[0] < i[1])
		result += (buf[i[0]] >= '0' && buf[i[0]] <= '9') ?
			(buf[i[0]] - '0') * ft_power(16, i[1] - i[0] - 1) :
			(buf[i[0]] - 'a' + 10) * ft_power(16, i[1] - i[0] - 1);
	return (result);
}
