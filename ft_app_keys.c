/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:35:51 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/18 21:49:23 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(t_canvas *mlx, int key)
{
	if (mlx->isometric)
	{
		if (key == R)
			mlx->offset_x_iso -= 50;
		else if (key == L)
			mlx->offset_x_iso += 50;
		else if (key == U)
			mlx->offset_y_iso += 50;
		else if (key == D)
			mlx->offset_y_iso -= 50;
	}
	else
	{
		if (key == R)
			mlx->offset_x -= 50;
		else if (key == L)
			mlx->offset_x += 50;
		else if (key == U)
			mlx->offset_y += 50;
		else if (key == D)
			mlx->offset_y -= 50;
	}
}

void	ft_zoom(t_canvas *mlx, int key)
{
	if ((key == PL || key == PL_2) && mlx->scale <= 150)
	{
		mlx->scale += 3;
		ft_move(mlx, D);
	}
	else if ((key == MI || key == MI_2) && mlx->scale >= 3)
	{
		mlx->scale -= 3;
		ft_move(mlx, U);
	}
}

void	ft_z_scaler(t_canvas *mlx, int key)
{
	if (key == Z_U && mlx->isometric)
		mlx->z_scale += 1;
	else if (key == Z_D && mlx->isometric)
		mlx->z_scale -= 1;
}

void	ft_quit(t_canvas *mlx)
{
	ft_cleaner(&mlx->fdf, mlx->height);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit (0);
}

void	ft_rotation(t_canvas *mlx, int key)
{
	if (mlx->isometric)
	{
		if (key == NUM_4)
			mlx->img.alpha += 0.05;
		if (key == NUM_6)
			mlx->img.alpha -= 0.05;
		if (key == NUM_2)
			mlx->img.beta += 0.05;
		if (key == NUM_8)
				mlx->img.beta -= 0.05;
	}
}
