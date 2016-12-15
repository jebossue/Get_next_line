/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:08:41 by jebossue          #+#    #+#             */
/*   Updated: 2016/12/15 19:11:41 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_realloc(char **old, t_struct stru)
{
	char	*tmp;

	tmp = ft_memalloc(stru.i);
	tmp = ft_memcpy(tmp, *old, stru.i);
	if (stru.slash == -1)
		tmp = ft_memcpy(tmp + stru.i, stru.buff, stru.ret);
	else
		tmp = ft_memcpy(tmp + stru.i, stru.buff, stru.slash);
	free(old);
	old = NULL;
	return (tmp - stru.i);
}

int	ft_buff(char **line, t_struct stru)
{
	
}

int	get_next_line(const ind fd, char **line)
{
	static t_struct	stru = {.slash = 0, .ret = 0, .i = 0};
/*	if (stru.ret)
	{
		while (stru.buff[stru.i] != '\n' && stru.i < stru.ret)
			stru.i++;
		if (stru.buff[i] == '\n')
	}*/
	while (stru.ret = read(fd, str.buff, BUFF_SIZE) >= 0)
	{
		if ((stru.slash = ft_memchrint(stru.buff, '\n', stru.ret)) != -1)
		{
			ft_buff(line, stru);
/*			*line = ft_memalloc(stru.slash + 1);
			*line = ft_memcpy(*line, stru.buff, stru.slash + 1);
			buff = ft_memmove(buff, buff + stru.slash, stru.ret - stru.slash);*/
			return (1);
		}
		else
		{
			if (stru.i == 0)
			{
				ft_buff();
				*line = ft_memalloc(stru.ret);
				*line = ft_memcpy(*line, stru.buff, stru.ret);
			}
			else
			{
				ft_buff();
				*line = ft_realloc(line, stru);
			}
			free(buff);
			buff = NULL;
		}
		stru.i = stru.i + stru.ret;
	}
	if (stru.ret == 0)
		return (0);
	return (-1);
}
