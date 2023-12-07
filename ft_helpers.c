/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:29:50 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/19 11:32:35 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawzilla_b(t_data **fdf, t_canvas *mlx, int height)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	height--;
	while (y <= height)
	{
		x = 0;
		while (1)
		{
			if (y < height)
				ft_line_drawer(fdf[y][x], fdf[y + 1][x], mlx);
			if (!fdf[y][x].end)
				ft_line_drawer(fdf[y][x], fdf[y][x + 1], mlx);
			if (fdf[y][x].end)
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	ft_menu(mlx);
}

int	ft_keys_log_b(int key, t_canvas *mlx)
{
	mlx->img.img = mlx_new_image(mlx->mlx_ptr, X, Y);
	mlx->img.id = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, \
	&mlx->img.len, &mlx->img.endian);
	if (key == ESC)
		ft_quit(mlx);
	return (0);
}

int	ft_default_colors(int z)
{
	int	bottom;
	int	peak;
	int	gradient;
	int	color;

	bottom = -70;
	peak = 20;
	gradient = 0xFFFFFF / (peak - bottom);
	color = gradient * (z - bottom);
	return (color);
}

int	ft_colors(char *str, int z)
{
	int	r;
	int	i;

	r = 0;
	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'x')
		i++;
	if (str[i] == 'x')
		i++;
	else
		return (ft_default_colors(z));
	while (str[i])
	{
		r *= 16;
		if (ft_isdigit(str[i]))
			r += str[i] - '0';
		else if (ft_isxdigit(str[i]))
			r += ft_toupper(str[i]) - 'A' + 10;
		else
			return (ft_default_colors(str[i]));
		i++;
	}
	return (r);
}

void	ft_pixel_put(t_canvas *mlx, int x, int y, int color)
{
	char	*p;

	if (x < mlx->win_x && y < mlx->win_y && x >= 0 && y >= 0)
	{
		p = mlx->img.id + (y * mlx->img.len + x * (mlx->img.bpp / 8));
		*(int *)p = color;
	}
}
