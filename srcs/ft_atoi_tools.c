/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fT_atoi_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:33:21 by ravard            #+#    #+#             */
/*   Updated: 2018/02/28 19:39:20 by ravard           ###   ########.fr       */
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

char		*rm_multi_space(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		str[j] = str[i];
		if (str[i] == c)
		{
			while (str[++i] == c)
				;
			i--;
		}
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
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

int			ft_len(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
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
