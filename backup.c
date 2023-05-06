/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:28:58 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/17 01:04:48 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_filler(t_data **fdf, int fd)
{
	char	**str;
	char	*line;
	int		x;
	int		y;
	int		r;
  int   width;

	y = 0;
	width = 1;
	r = 0;
	while (get_next_line(fd, &line))
	{
		if (y == 0)
			width += ft_space_counter(line, ' ');
		str = ft_split(line, ' ');
		x = 0;
		while (str[x])
		{
			fdf[y][x].z = ft_atoi(str[x]);
			printf("%3d", fdf[y][x].z);
			free(str[x]);
			x++;
		}
		printf("\n");
		if (x != width)
			r = y;
		free(str);
		free(line);
		y++;
	}
  if (r)
  {
    ft_cleaner(&fdf, y);
		printf("Error: Line %d has inconsistent length\n", r + 1);
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
	ft_filler(fdf, fd);
	return (fdf);
}
