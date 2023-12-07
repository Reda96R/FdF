/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keylogger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:39:02 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/19 15:10:19 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_cross(int key, t_canvas *mlx)
{
	(void)key;
	(void)mlx;
	exit (0);
}

int	ft_turn_around(t_canvas *mlx)
{
	mlx->img.img = mlx_new_image(mlx->mlx_ptr, X, Y);
	mlx->img.id = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, \
	&mlx->img.len, &mlx->img.endian);
	if (mlx->rot)
	{
		mlx->img.gamma += 0.05;
		if (mlx->img.gamma >= 6.3)
			mlx->img.gamma = 0;
		ft_drawzilla(mlx->fdf, mlx, mlx->height);
		return (1);
	}
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	return (0);
}

void	ft_turning(t_canvas *mlx)
{
	if (!mlx->rot)
		mlx->rot = 1;
	else
		mlx->rot = 0;
}

int	ft_keys_log(int key, t_canvas *mlx)
{
	if (ft_key_check(key))
	{
		mlx->img.img = mlx_new_image(mlx->mlx_ptr, X, Y);
		mlx->img.id = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, \
		&mlx->img.len, &mlx->img.endian);
		if (key == ESC)
			ft_quit(mlx);
		if (key == 48)
			ft_switch_proj(mlx, key);
		if (key == R || key == L || key == U || key == D)
			ft_move(mlx, key);
		if (key == PL || key == PL_2 || key == MI || key == MI_2)
			ft_zoom(mlx, key);
		if (key == Z_U || key == Z_D)
			ft_z_scaler(mlx, key);
		if (key == NUM_2 || key == NUM_4 || key == NUM_6 || key == NUM_8)
			ft_rotation(mlx, key);
		if (key == ROT)
			ft_turning(mlx);
		ft_drawzilla_b(mlx->fdf, mlx, mlx->height);
	}
	return (0);
}

void	ft_keylogger(t_canvas *mlx, int y, int n)
{
	mlx->height = y;
	mlx_hook(mlx->win_ptr, 17, (1L << 17), ft_cross, mlx);
	if (!n)
		mlx_key_hook(mlx->win_ptr, ft_keys_log, mlx);
	else
		mlx_key_hook(mlx->win_ptr, ft_keys_log_b, mlx);
	mlx_loop_hook(mlx->mlx_ptr, ft_turn_around, mlx);
	mlx_loop(mlx->mlx_ptr);
}
