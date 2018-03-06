/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fT_atoi_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:33:21 by ravard            #+#    #+#             */
/*   Updated: 2018/03/06 02:03:12 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_rm_whitespace(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] == '\n' || str[i] == '\v' || str[i] == ' ' ||
			str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
			i++;
		return (str + i);
	}
	return (NULL);
}

char		*polarity(char *str, int *sign)
{
	if (str[0] == '-')
	{
		*sign = -1;
		return (str + 1);
	}
	else if (str[0] == '+')
	{
		*sign = 1;
		return (str + 1);
	}
	else
	{
		*sign = 1;
		return (str);
	}
}

int			ft_len(char *buf, char mode)
{
	int	i;

	i = 0;
	if (mode == 0)
	{
		while (buf[i] >= '0' && buf[i] <= '9')
			i++;
	}
	else if (mode == 1)
	{
		while ((buf[i] >= '0' && buf[i] <= '9')
				|| (buf[i] >= 'a' && buf[i] <= 'f')
				|| (buf[i] >= 'A' && buf[i] <= 'F'))
			i++;
	}
	return (i);
}

int			ft_power(int x, int n)
{
	int	i;
	int	ret;

	ret = 1;
	i = 0;
	while (++i <= n)
		ret *= x;
	return (ret);
}
