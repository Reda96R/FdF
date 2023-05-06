/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_linux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:03:35 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/05 14:04:07 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

int	main(int ac, char *av[])
{
	t_data	**fdf;
	int		fd;
	char	*line;

	fd = open (av[1], O_RDONLY, 0);
	if (ac != 2 || !ft_extension_check(av[1]) || fd <= 0)
	{
		close (fd);
		ft_false_input(ac, fd);
	}
	else if (!get_next_line(fd, &line))
	{
    close (fd);
		ft_errors_buster(4);
	}
	else
	{
		fd = open (av[1], O_RDONLY, 0);
		fdf = ft_maps_reader(av[1], fd);
	}
  free(line);
	close (fd);
	ft_cleaner(&fdf, ft_height(av[1]));
	return (0);
}
