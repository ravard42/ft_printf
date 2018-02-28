/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:32:10 by ravard            #+#    #+#             */
/*   Updated: 2018/02/28 19:34:43 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_atoi(const char *str)
{
	char	*buf;
	int		i;
	int		*sign;
	int		len;
	int		result;

	sign = (int *)malloc(sizeof(int));
	buf = (char *)str;
	buf = polarity(ft_rm_whitespace(buf), sign);
	i = 0;
	len = ft_len(buf);
	result = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
	{
		result = result + (buf[i] - '0') * ft_power(10, len - i - 1);
		i++;
	}
	result = *sign * result;
	free(sign);
	return (result);
}
