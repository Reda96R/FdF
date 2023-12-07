/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps_drawer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 07:28:18 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/19 11:31:43 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotation_matrix(t_data *pnt, t_canvas *mlx)
{
	double	x;
	double	y;
	double	z;

	x = (double)pnt->x;
	y = (double)pnt->y;
	z = (double)pnt->z;
	pnt->y = (int)round((y * cos(mlx->img.alpha)) + (z * sin(mlx->img.alpha)));
	pnt->z = (int)round((-y * sin(mlx->img.alpha)) + (z * cos(mlx->img.alpha)));
	z = (double)pnt->z;
	pnt->x = (int)round((x * cos(mlx->img.beta)) + (z * sin(mlx->img.beta)));
	pnt->z = (int)round((-x * sin(mlx->img.beta)) + (z * cos(mlx->img.beta)));
	x = (double)pnt->x;
	y = (double)pnt->y;
	pnt->x = (int)round((x * cos(mlx->img.gamma)) - (y * sin(mlx->img.gamma)));
	pnt->y = (int)round((x * sin(mlx->img.gamma)) + (y * cos(mlx->img.gamma)));
}

void	ft_param_setter(t_canvas *mlx, t_data *a, t_data *b)
{
	a->x *= mlx->scale;
	a->y *= mlx->scale;
	b->x *= mlx->scale;
	b->y *= mlx->scale;
	a->z *= mlx->z_scale;
	b->z *= mlx->z_scale;
	ft_rotation_matrix(a, mlx);
	ft_rotation_matrix(b, mlx);
	if (mlx->isometric)
	{
		ft_switch_to_iso(&a->x, &a->y, &a->z, mlx->angle);
		ft_switch_to_iso(&b->x, &b->y, &b->z, mlx->angle);
		a->x += mlx->offset_x_iso;
		b->x += mlx->offset_x_iso;
		a->y += mlx->offset_y_iso;
		b->y += mlx->offset_y_iso;
	}
	else
	{
		a->x += mlx->offset_x;
		b->x += mlx->offset_x;
		a->y += mlx->offset_y;
		b->y += mlx->offset_y;
	}
}

int	gradient(int s_color, int e_color)
{
	t_colors	c;

	c.s_r = r(s_color);
	c.s_g = g(s_color);
	c.s_b = b(s_color);
	c.e_r = r(e_color);
	c.e_g = g(e_color);
	c.e_b = b(e_color);
	return (rgb_encoder(c.s_r, c.s_g, c.s_b));
}

void	ft_line_drawer(t_data a, t_data b, t_canvas *mlx)
{
	float	max;
	int		color;
	int		i;

	i = 0;
	ft_param_setter(mlx, &a, &b);
	max = fmax(ft_absolute_value(b.x - a.x), ft_absolute_value(b.y - a.y));
	color = gradient(a.color, b.color);
	while (max >= 0)
	{
		ft_pixel_put(mlx, a.x, a.y, color);
		a.x += (b.x - a.x) / (float) max;
		a.y += (b.y - a.y) / (float) max;
		if (a.x > mlx->win_x || a.y > mlx->win_y || a.y < 0 || a.x < 0)
			break ;
		max--;
		i++;
	}
}

void	ft_drawzilla(t_data **fdf, t_canvas *mlx, int height)
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
}
