/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:21:36 by jebossue          #+#    #+#             */
/*   Updated: 2017/01/10 19:03:48 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

typedef struct	s_struct
{
	int		ret;
	char	buff[BUFF_SIZE];
	int		slash;
	int		i;
}				t_struct;

int	get_next_line(const int fd, char **line);

#endif
