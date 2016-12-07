/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:20:49 by jebossue          #+#    #+#             */
/*   Updated: 2016/12/07 18:01:02 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_realloc(char *old, int nbr_old, int nbr_new)
{
	char	*tmp;
	char	*new_str;

	tmp = ft_memalloc(nbr_old);
	tmp = ft_memcpy(tmp, old, nbr_old);
	free(old);
	old = NULL;
	new_str = ft_memalloc(nbr_old + nbr_new);
	new_str = ft_memcpy(new_str, tmp, nbr_old);
	return (new_str);
}

int		ft_

int		ft_get_next_line(const int fd, char **line)
{
	static int	ret;
	static int	slash_n;
	char		buff[BUFF_SIZE];
	int			index;
	static char	*tmp;
	int			old_slash_n;
	
	tmp = NULL;
	index = 0;
	if (tmp)
	{
		free(*line);
		line = NULL;
		old_slash_n = slash_n + 1;
		if ((slash_n = ft_memchrint(tmp + old_slash_n, '\n',
						ret - old_slash_n + 1)) == -1)
		{
			*line = ft_memalloc(ret - old_slash_n);
			*line = ft_memcpy(*line, tmp + old_slash_n, ret - old_slash_n + 1);
			free(tmp);
			tmp = NULL;
		}
		else
		{
			*line = ft_memalloc(slash_n - old_slash_n);
			*line = ft_memcpy(*line, tmp + old_slash_n, slash_n - old_slash_n);
		}
		return (1);
	}
	while (((ret = read(fd, buff, BUFF_SIZE)) != 0) &&
		((slash_n = ft_memchrint(buff, '\n', ret)) == -1))
	{
		if (index == 0)
			*line = ft_memalloc(ret);
		else
			*line = ft_realloc(*line, index, index + ret);
		*line = ft_memcpy(*line + index, buff, ret);
		index = ret + index;
	}
	if (index == 0)
		*line = ft_memalloc(slash_n);
	else
		*line = ft_realloc(*line, index, index + slash_n);
	*line = ft_memcpy(*line + index, buff, slash_n);
	if (slash_n != 0)
	{
		tmp = ft_memalloc(ret - slash_n - 1);
		tmp = ft_memcpy(tmp, buff + slash_n + 1, ret - slash_n - 1);
		slash_n = -1;
		return (1);
	}
	if (ret == 0)
		return (0);
	return (1);
}
