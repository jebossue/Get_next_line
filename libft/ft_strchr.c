/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:52:32 by jebossue          #+#    #+#             */
/*   Updated: 2016/12/09 14:48:21 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*tmp_s;

	tmp_s = (char *)s;
	i = 0;
	while (tmp_s[i] && tmp_s[i] != (char)c)
		i++;
	if (tmp_s[i] != (char)c)
		return (NULL);
	return (tmp_s + i);
}
