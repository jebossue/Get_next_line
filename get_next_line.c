/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:20:49 by jebossue          #+#    #+#             */
/*   Updated: 2016/12/09 19:37:02 by jebossue         ###   ########.fr       */
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
	return (new_str);
}

int		ft_tmp(char **line, int *slash_n, int *ret, char **tmp)
{
	static int	old_slash_n = 0;

	free(*line);
	*line = NULL;
	old_slash_n = (*slash_n) + old_slash_n + 1;
	if ((*slash_n = ft_memchrint(*tmp + old_slash_n, '\n',
					*ret - old_slash_n - 1)) == -1)
	{
		*line = ft_memalloc(*ret - old_slash_n);
		*line = ft_memcpy(*line, *tmp + old_slash_n, *ret - old_slash_n - 1);
		free(*tmp);
		*tmp = NULL;
	}
	else
	{
		*line = ft_memalloc(*slash_n + 1);
		*line = ft_memcpy(*line, *tmp + old_slash_n, *slash_n);
	}
	return (1);
}

t_struct	*ft_read(char **line, const int fd, int *slash_n,
		t_struct *truct)
{
	while (((truct->ret = read(fd, truct->buff, BUFF_SIZE)) != 0) &&
			((*slash_n = ft_memchrint(truct->buff, '\n', truct->ret)) == -1))
	{
		if (truct->index == 0)
		{
			*line = ft_memalloc(truct->ret);
		}
		else
		{
			*line = ft_realloc(*line, truct->index, truct->index + truct->ret);
		}
		*line = ft_memcpy(*line + truct->index, truct->buff, truct->ret);
		truct->index = truct->ret + truct->index;
	}
	return (truct);
}

int		ft_create_tmp(char *buff, int *ret, int *slash_n, char **tmp)
{
		*tmp = ft_memalloc(*ret - *slash_n - 1);
		*tmp = ft_memcpy(*tmp, buff + (*slash_n + 1), *ret - *slash_n - 1);
		*ret = *ret - *slash_n - 1;
		*slash_n = -1;
		return (1);
}

int		ft_get_next_line(const int fd, char **line)
{
	static int	ret;
	static char	*tmp = NULL;
	t_struct	*truct;
	static int	slash_n;

	if ((truct = malloc(sizeof(*truct))) == NULL)
		return (-1);
	truct->index = 0;
	if (tmp)
	{
		return (ft_tmp(line, &slash_n, &ret, &tmp));
	}
	truct = ft_read(line, fd, &slash_n, truct);
	ret = truct->ret;
	if (ret == 0)
		return (0);
	printf("ret: %d\n", truct->index + slash_n);
	if (truct->index == 0)
	{
		*line = ft_memalloc(slash_n + 1);
	}
	else
		*line = ft_realloc(*line, truct->index, truct->index + slash_n);
//	*line = ft_memcpy(*line + truct->index, truct->buff, slash_n);
	if (slash_n != 0 && ret != slash_n + 1)
		ft_create_tmp(truct->buff, &ret, &slash_n, &tmp);
	else
		return (0);
	return (1);
}
