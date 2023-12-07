/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 07:16:56 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/19 15:45:45 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu_instructions(t_canvas *mlx)
{
	int		n;
	char	*menu;

	n = 10;
	menu = "Welcome to FdF";
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 48, 5, ORANGE, menu);
	menu = "::: Instructions ::: ";
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, n += 80, WHITE, menu);
	menu = "Camera mouvment: W,S,A,D";
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 18, n += 60, M_TEXT, menu);
	menu = "Switch projection: Tab";
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 18, n += 40, M_TEXT, menu);
	menu = "Panoramic view: Space";
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 18, n += 40, M_TEXT, menu);
	menu = "Rotate: 4,6,2,8";
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 18, n += 40, M_TEXT, menu);
	menu = "Elevation: ] / [";
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 18, n += 40, M_TEXT, menu);
	menu = "Zoom: + / -";
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 18, n += 40, M_TEXT, menu);
}

void	ft_menu(t_canvas *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < (X / 5))
	{
		j = 0;
		while (j < Y)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, j++, BLACK);
		i++;
	}
	ft_menu_instructions(mlx);
}
