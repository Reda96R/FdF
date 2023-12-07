/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:03:35 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/19 11:36:41 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_switch_to_iso(float *x, float *y, float *z, double n)
{
	*x = (*x - *y) * cos(n);
	*y = (*x + *y) * sin(n) - (*z);
}

int	ft_canvas_launcher(t_canvas *mlx)
{
	mlx->win_x = X;
	mlx->win_y = Y;
	mlx->scale = 20;
	mlx->z_scale = 1;
	mlx->angle = 0.7853980;
	mlx->isometric = 1;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (MLX_ERROR);
	mlx->win_ptr = \
	mlx_new_window (mlx->mlx_ptr, mlx->win_x, mlx->win_y, "FdF");
	if (!mlx->win_ptr)
		return (MLX_ERROR);
	mlx->offset_x = 500;
	mlx->offset_y = 250;
	mlx->offset_x_iso = 700;
	mlx->offset_y_iso = 230;
	mlx->img.alpha = 0;
	mlx->img.beta = 0;
	mlx->img.gamma = 0;
	mlx->rot = 0;
	mlx->img.img = mlx_new_image(mlx->mlx_ptr, X, Y);
	mlx->img.id = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, \
	&mlx->img.len, &mlx->img.endian);
	return (1);
}

int	main(int ac, char *av[])
{
	int			fd;
	char		*line;
	t_canvas	mlx;

	line = NULL;
	fd = open (av[1], O_RDONLY, 0);
	get_next_line(fd, &line);
	if ((ac != 2) || !ft_extension_check(av[1])
		|| fd <= 0 || !line || line[0] == '\n')
		ft_false_input(ac, fd, line);
	free (line);
	fd = open (av[1], O_RDONLY, 0);
	mlx.fdf = ft_maps_reader(av[1], fd);
	mlx.n = 1;
	if (!ft_canvas_launcher(&mlx))
	{
		close (fd);
		free(mlx.win_ptr);
		ft_cleaner(&mlx.fdf, ft_height(av[1]));
		return (0);
	}
	ft_drawzilla_b(mlx.fdf, &mlx, ft_height(av[1]));
	ft_keylogger(&mlx, ft_height(av[1]), 0);
	return (0);
}
