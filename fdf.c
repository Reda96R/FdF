/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:28:02 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/17 01:20:10 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

int	main(int ac, char *av[])
{
	t_data	**fdf;
	int		fd;

	fd = open (av[1], O_RDONLY, 0);
	if (ac != 2 || !ft_extension_check(av[1]) || fd <= 0)
	{
    ft_false_input(ac, fd);
    close (fd);
    exit (1);
	}
	else
		fdf = ft_maps_reader(av[1], fd);
	ft_cleaner(&fdf, ft_height(av[1]));
	return (0);
}