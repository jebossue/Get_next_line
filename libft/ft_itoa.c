/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:42:25 by jebossue          #+#    #+#             */
/*   Updated: 2016/11/22 14:05:29 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrnumeration(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
	{
		n = 147483648;
		length = 2;
	}
	if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n >= 10)
	{
		n = n / 10;
		length++;
	}
	length++;
	return (length);
}

static int	ft_min(char *str, int i)
{
	str[0] = '-';
	str[1] = '2';
	i = 2;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		length;

	length = ft_nbrnumeration(n) + 1;
	if ((str = (char*)malloc(sizeof(*str) * (length))) == NULL)
		return (NULL);
	i = 0;
	str[length - 1] = '\0';
	if (n == -2147483648)
	{
		i = ft_min(str, i);
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		str[i++] = '-';
	}
	while (length-- > 0 && i != length)
	{
		str[length - 1] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
