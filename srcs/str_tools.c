/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:42:35 by ravard            #+#    #+#             */
/*   Updated: 2018/03/12 07:10:49 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_revstr(char *str)
{
	int		len;
	char	tmp;
	int		i;

	len = ft_strlen(str);
	i = -1;
	while (++i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
	return (str);
}

//char			*my_strncpy(char *dst, const char *src, size_t len)
//{
//	size_t	i;
//
//	i = -1;
//	while (++i < len)
//	{
//		dst[i] = src[i];
//		if (!src[i])
//			break ;
//	}
//	dst[i] = '\0';
//	return (dst);
//}

char			*add_nose(int nb, char c, char *buff)
{
	int		len;
	int		i;

	len = ft_strlen(buff);
	i = len;
	while (--i >= 0)
		buff[nb + i] = buff[i];
	i = -1;
	while (++i < nb)
		buff[i] = c;
	return (buff);
}

char			*add_tail(int nb, char c, char *buff)
{
	int		i;

	i = -1;
	while (++i < nb)
		buff[i] = c;
	return (buff);
}

size_t			ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int				wstrlen(wchar_t *wc)
{
	int		i;

	i = -1;
	while (wc[++i])
		;
	return (i);
}
