/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:59:12 by jebossue          #+#    #+#             */
/*   Updated: 2016/12/05 19:44:56 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	(void)argc;
	char	*line;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if ((line = (char *)malloc(sizeof(line) * 100)) == NULL)
		return (0);
	ft_get_next_line(fd, &line);
	ft_putstr(line);
	return (0);
}
