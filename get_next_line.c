/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:08:41 by jebossue          #+#    #+#             */
/*   Updated: 2017/01/20 12:24:19 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_realloc(char **old, t_struct stru)
{
	char	*tmp;

	tmp = ft_memalloc(stru.i + stru.ret + 1);
	tmp = ft_memcpy(tmp, *old, stru.i);
	if (stru.slash == -1)
		ft_memcpy(tmp + stru.i, stru.buff, stru.ret);
	else
		ft_memcpy(tmp + stru.i, stru.buff, stru.slash);
	free(*old);
	return (tmp);
}

void	ft_buff(char **line, t_struct stru, int length)
{
	if (stru.i != 0)
		*line = ft_realloc(line, stru);
	else
	{
		*line = ft_memalloc(length + 1);
		*line = ft_memcpy(*line, stru.buff, length);
	}
}

int		ft_slash_n(char **line, t_struct *stru)
{
	if ((stru->slash = ft_memchrint(stru->buff, '\n', stru->ret)) != -1)
	{
		ft_buff(line, *stru, stru->slash);
		ft_memmove(stru->buff, stru->buff + stru->slash + 1,
				stru->ret - stru->slash - 1);
		stru->ret = stru->ret - stru->slash - 1;
		stru->i = 0;
		return (1);
	}
	else
		ft_buff(line, *stru, stru->ret);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_struct	stru = {.slash = -1, .ret = 0, .i = 0};

	if (line == NULL || fd < 0)
		return (-1);
	*line = NULL;
	if (stru.ret > 0)
	{
		if ((ft_slash_n(line, &stru)) == 1)
			return (1);
		else
			stru.i = stru.ret;
	}
	while ((stru.ret = read(fd, stru.buff, BUFF_SIZE)) > 0)
	{
		if ((ft_slash_n(line, &stru)) == 1)
			return (1);
		stru.i = stru.i + stru.ret;
	}
	if (stru.ret < 0)
		return (-1);
	if (stru.ret == 0 && stru.i > 0)
	{
		stru.i = 0;
		return (1);
	}
	return (0);
}
