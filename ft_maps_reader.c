/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:28:58 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/16 01:00:27 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_cleaner(t_data ***fdf, int rows)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while ((*fdf)[y][x].z)
			free(&((*fdf)[y][x++].z));
		free((*fdf)[y++]);
	}
	free(*fdf);
	*fdf = NULL;
}

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

void	ft_filler(t_data **fdf, int fd)
{
	char	**str;
	char	*line;
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
			printf("%3d", fdf[y][x].z);
			free(str[x++]);
		}
		printf("\n");
		free(line);
		y++;
		free(str);
	}
}

t_data	**ft_maps_reader(char *file)
{
	t_data	**fdf;
	int		x;
	int		y;
	int		fd;

	x = ft_width(file);
	y = ft_height(file);
	fdf = (t_data **) malloc (sizeof (t_data *) * (y + 1));
	while (y > 0)
		fdf[--y] = (t_data *) malloc(sizeof (t_data) * (x + 1));
	fd = open(file, O_RDONLY, 0);
	ft_filler(fdf, fd);
	return (fdf);
}
