/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:28:58 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/19 09:29:52 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_filler(t_data **fdf, int fd)
{
	char	*line;
	char	**str;
	int		x;
	int		y;

	y = 0;
	while (get_next_line(fd, &line))
	{
		str = ft_split(line, ' ');
		x = 0;
		while (str[x])
		{
			fdf[y][x].z = ft_atoi(str[x]);
			fdf[y][x].x = x;
			fdf[y][x].y = y;
			fdf[y][x].end = 0;
			fdf[y][x].color = ft_colors(str[x], fdf[y][x].z);
			free(str[x++]);
		}
		free(str);
		free(line);
		x--;
		fdf[y++][x].end = 1;
	}
}

t_data	**ft_maps_reader(char *file, int fd)
{
	t_data	**fdf;
	int		x;
	int		y;

	x = ft_width(file);
	y = ft_height(file);
	fdf = (t_data **)malloc(sizeof(t_data *) * (y + 1));
	if (!fdf)
		return (NULL);
	while (y)
	{
		fdf[--y] = (t_data *)malloc(sizeof(t_data) * (x + 1));
		if (!fdf[y])
		{
			ft_cleaner(&fdf, y);
			return (NULL);
		}
	}
	ft_filler(fdf, fd);
	return (fdf);
}
