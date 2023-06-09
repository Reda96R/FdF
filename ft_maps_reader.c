/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:28:58 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/05 07:52:18 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>

int	ft_filler(t_data **fdf, int fd, int width)
{
	char	*line;
	int		x;
	int		y;
	char	**str;

	y = 0;
	while (get_next_line(fd, &line))
	{
		str = ft_split(line, ' ');
		x = 0;
		while (str[x])
		{
			fdf[y][x].z = ft_atoi(str[x]);
      printf("%3d", fdf[y][x].z);
			free(str[x++]);
		}
		printf("\n");
		free(str);
		free(line);
		if (x != width)
			return (y);
		y++;
	}
	return (0);
}

void	ft_parser(t_data **fdf, int fd, int y)
{
	int		r;
	int		width;
	char	*line;

	width = 1;
	get_next_line(fd, &line);
	width += ft_space_counter(line, ' ');
	free(line);
	r = ft_filler(fdf, fd, width);
	if (r)
	{
		close (fd);
		ft_cleaner(&fdf, y);
		ft_printf("Error: Line %d has inconsistent length\n", r + 1);
		exit (1);
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
	while (y > 0)
	{
		fdf[--y] = (t_data *)malloc(sizeof(t_data) * (x + 1));
		if (!fdf[y])
		{
			ft_cleaner(&fdf, y);
			return (NULL);
		}
	}
	ft_parser(fdf, fd, ft_height(file));
	return (fdf);
}
