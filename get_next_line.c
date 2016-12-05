/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:20:49 by jebossue          #+#    #+#             */
/*   Updated: 2016/12/05 19:51:08 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		ft_get_next_line(const int fd, char **line)
{
	int			ret;
	static int	slash_n;
	static int	index;
	char		buff[BUFF_SIZE];
	static char	*tmp;
	
	index = BUFF_SIZE;
	if (slash_n)
	{
		line = ft_memcpy(line, tmp, BUFF_SIZE - slash_n);
		index = BUFF_SIZE - slash_n;
	}
	while (((ret = read(fd, buff, BUFF_SIZE)) != 0) &&
		((slash_n = ft_memchrint(buff, '\n', BUFF_SIZE)) == 0))

	{
		*line = ft_memcpy(line + index, buff, BUFF_SIZE);
		index++;
	}
	*line = ft_memcpy(*line + index, buff, slash_n);
		printf("%s\n", *line);
	if (slash_n < BUFF_SIZE)
	{
		tmp = (char *)malloc(sizeof(tmp) * (BUFF_SIZE - slash_n));
		tmp = ft_memcpy(tmp, buff + slash_n, BUFF_SIZE - slash_n);
	}
	slash_n = index - slash_n;
	if (ret == 0)
		return (0);
	else
		return (1);
}
