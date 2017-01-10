/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:08:41 by jebossue          #+#    #+#             */
/*   Updated: 2017/01/10 19:33:32 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_realloc(char **old, t_struct stru)
{
	char	*tmp;

	tmp = ft_memalloc(stru.i + stru.ret);
	tmp = ft_memcpy(tmp, *old, stru.i);
//	printf("tmp: %s\n", tmp);
//	printf("buff: %s\n", stru.buff);
//	printf("slash: %d\n", stru.slash);
//	printf("i: %d\n", stru.i);
	if (stru.slash == -1)
	{
		ft_memcpy(tmp + stru.i - 1, stru.buff, stru.ret);
//		tmp [stru.i + stru.ret - 1] = '\0';
	}
	else
	{
		ft_memcpy(tmp + stru.i - 1, stru.buff, stru.slash);
//		tmp[stru.i + stru.slash - 1] = '\0';
	}
	return (tmp);
}

void	ft_buff(char **line, t_struct stru, int length)
{
//	printf("buff: %s\n", stru.buff);
	if (stru.i != 0)
	{
//		printf("buff:%s\n", stru.buff);
		*line = ft_realloc(line, stru);
//		printf("line:%s\n", *line);
	}
	else
	{
	printf("length: %d\n", length);
		*line = ft_memalloc(length);
		*line = ft_memcpy(*line, stru.buff, length);
		*line[length] = '\0';
		printf("line:%s\n", *line);
	}
//	printf("line: %s\n", *line);
}

int		ft_slash_n(char **line, t_struct *stru)
{
	if ((stru->slash = ft_memchrint(stru->buff, '\n', stru->ret)) != -1)
	{
//		printf("slash: %d\n", stru->slash);
		ft_buff(line, *stru, stru->slash);
		ft_memmove(stru->buff, stru->buff + stru->slash + 1,
				stru->ret - stru->slash + 1);
//		printf("buff: %s\n", stru->buff);
		stru->ret = stru->ret - stru->slash + 1;
		return (1);
	}
	else
		ft_buff(line, *stru, stru->ret);
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static t_struct	stru = {.slash = 0, .ret = 0, .i = 0};

	*line = NULL;
	if (stru.ret != 0)
	{
//		printf("buff: %s\n", stru.buff);
		if ((ft_slash_n(line, &stru)) == 1)
			return (1);
		else
			stru.i = stru.ret - 1;
	}
	while ((stru.ret = read(fd, stru.buff, BUFF_SIZE)) > 0)
	{
//	printf("ret: %d\n", stru.ret);
		if ((ft_slash_n(line, &stru)) == 1)
		{
			stru.i = 0;
			return (1);
		}
		stru.i = stru.i + stru.ret;
		stru.ret = 0;
	}
	if (stru.ret == 0)
			return (0);
	return (-1);
}
