/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:06:12 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/19 15:09:41 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_absolute_value(float n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	ft_space_counter(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
		if (str[i++] == c && str[i] != c)
			count++;
	return (count);
}

int	ft_extension_check(char *map)
{
	char	*extension;

	extension = ft_strrchr(map, 'f');
	if (extension == NULL || ft_strncmp(extension - 3, ".fdf", 4))
		return (0);
	return (1);
}

int	ft_key_check(int key)
{
	return (key == ESC || key == I || key == T || key == U || key == D || \
	key == R || key == L || key == PL || key == PL_2 || key == MI || \
	key == MI_2 || key == Z_U || key == Z_D || key == ROT || key == R \
	|| key == NUM_4 || key == NUM_6 || key == NUM_2 || key == NUM_8 \
	|| key == 48);
}

void	ft_switch_proj(t_canvas *mlx, int key)
{
	(void)key;
	if (mlx->isometric)
	{
		mlx->img.alpha = 0;
		mlx->img.beta = 0;
		mlx->img.gamma = 0;
		mlx->isometric = 0;
	}
	else
	mlx->isometric = 1;
}
