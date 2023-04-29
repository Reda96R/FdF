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
#include "get_next_line.h"

void	ft_filler(t_data **fdf, int fd)
{
	char	**str;
	char	*line;
	int		x;
	int		y;

	y = 0;
  // if (!get_next_line(fd, &line))
  // {
  //   printf("test\n");
  //   free(line);
  //   exit (215);
  // }   
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
		free(str);
		y++;
	}
}

t_data	**ft_maps_reader(char *file, int fd)
{
	t_data	**fdf;
	int		x;
	int		y;

  x = ft_width(file);
	y = ft_height(file);
	fdf = (t_data **) malloc (sizeof (t_data *) * (y + 1));
	while (y > 0)
		fdf[--y] = (t_data *) malloc(sizeof (t_data) * (x + 1));
	ft_filler(fdf, fd);
	return (fdf);
}
