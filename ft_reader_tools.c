/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:30:57 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/16 23:31:43 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_width(char *file)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_word_counter(line, ' ');
	free(line);
	close (fd);
	return (width);
}

int	ft_height(char *file)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close (fd);
	return (height);
}